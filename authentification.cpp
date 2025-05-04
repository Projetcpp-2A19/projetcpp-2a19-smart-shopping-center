#include "gemploye.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QPixmap>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDialog>
#include <QRandomGenerator>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>
//#include <arduino.h>
#include<QThread>
#include "authentification.h"

Arduino arduino;

bool gemploye::authentifierUtilisateur(const QString& posteAutorise) {
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(nullptr, "Erreur", "Base de données non connectée.");
        return false;
    }

    if (arduino.connect_arduino() == -1) {
        QMessageBox::critical(nullptr, "Erreur Arduino", "Impossible de connecter la carte Arduino.");
        return false;
    }

    int attempts = 0;
    bool isAuthenticated = false;

    while (attempts < 2 && !isAuthenticated) {
        QDialog authDialog;
        authDialog.setWindowTitle("Authentification");
        authDialog.resize(400, 400);
        authDialog.setModal(true);
        authDialog.setStyleSheet(R"(
            QDialog {
                background-color: #ffccff;
                border-radius: 10px;
            }
            QLineEdit {
                border: 2px solid #6699ff;
                border-radius: 8px;
                padding: 5px;
                font-size: 14px;
                background-color: white;
                color: black;
            }
            QPushButton {
                background-color: #6699ff;
                color: white;
                border-radius: 8px;
                padding: 8px;
                font-size: 14px;
            }
            QPushButton:hover {
                background-color: #3366cc;
            }
        )");

        QLineEdit *emailLineEdit = new QLineEdit(&authDialog);
        emailLineEdit->setPlaceholderText("Email");

        QLineEdit *passwordLineEdit = new QLineEdit(&authDialog);
        passwordLineEdit->setPlaceholderText("Mot de passe");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        QPushButton *scanFingerprintButton = new QPushButton("Se connecter avec empreinte", &authDialog);
        QPushButton *loginButton = new QPushButton("Se connecter", &authDialog);
        QPushButton *forgotPasswordButton = new QPushButton("Mot de passe oublié ?", &authDialog);

        QVBoxLayout *layout = new QVBoxLayout(&authDialog);
        layout->addWidget(emailLineEdit);
        layout->addWidget(passwordLineEdit);
        layout->addWidget(scanFingerprintButton);
        layout->addWidget(loginButton);
        layout->addWidget(forgotPasswordButton);
        authDialog.setLayout(layout);

        // Authentification par empreinte
        QObject::connect(scanFingerprintButton, &QPushButton::clicked, [&]() {
            arduino.write_to_arduino("SCAN\n");
            QByteArray idData = arduino.read_from_arduino();
            idData = idData.trimmed();  // Nettoyer la donnée reçue

            if (idData.isEmpty()) {
                QMessageBox::warning(&authDialog, "Erreur", "Aucune réponse de l'Arduino.");
                return;
            }

            int fingerprintID = idData.toInt();
            if (fingerprintID == -1) {
                QMessageBox::warning(&authDialog, "Erreur", "Empreinte non reconnue.");
                return;
            }

            QSqlQuery query;
            query.prepare("SELECT NOM, POSTE FROM EMPLOYES WHERE ID_EMPREINTE = :id");
            query.bindValue(":id", fingerprintID);

            if (!query.exec()) {
                QMessageBox::critical(&authDialog, "Erreur SQL", query.lastError().text());
                return;
            }

            if (query.next()) {
                QString nom = query.value("NOM").toString();
                QString poste = query.value("POSTE").toString();

                if (poste == posteAutorise) {
                    QString message = "Bienvenue, " + nom + "\n";
                    arduino.write_to_arduino(message.toUtf8());

                    QMessageBox::information(&authDialog, "Succès", "Bienvenue " + nom + " !");
                    isAuthenticated = true;
                    authDialog.accept();
                } else {
                    arduino.write_to_arduino("POSTE NON AUTORISE");
                    QMessageBox::warning(&authDialog, "Refusé", "Poste non autorisé.");
                }
            } else {
                QMessageBox::warning(&authDialog, "Erreur", "Empreinte inconnue.");
            }
        });

        // Authentification classique
        QObject::connect(loginButton, &QPushButton::clicked, [&]() {
            QString email = emailLineEdit->text().trimmed();
            QString password = passwordLineEdit->text().trimmed();

            if (email.isEmpty() || password.isEmpty()) {
                QMessageBox::warning(&authDialog, "Erreur", "Veuillez remplir tous les champs.");
                return;
            }

            QSqlQuery query;
            query.prepare("SELECT MDP, POSTE, NOM FROM EMPLOYES WHERE EMAIL = :email");
            query.bindValue(":email", email);

            if (!query.exec()) {
                QMessageBox::critical(&authDialog, "Erreur SQL", query.lastError().text());
                return;
            }

            if (query.next()) {
                QString mdp = query.value("MDP").toString();
                QString poste = query.value("POSTE").toString();
                QString nom = query.value("NOM").toString();

                if (mdp == password) {
                    if (poste == posteAutorise) {
                        QString message = "Bienvenue, " + nom + "\n";
                        arduino.write_to_arduino(message.toUtf8());

                        QMessageBox::information(&authDialog, "Succès", "Bienvenue " + nom + " !");
                        isAuthenticated = true;
                        authDialog.accept();
                    } else {
                        arduino.write_to_arduino("POSTE NON AUTORISE");
                        QMessageBox::warning(&authDialog, "Refusé", "Poste non autorisé.");
                    }
                } else {
                    QMessageBox::warning(&authDialog, "Erreur", "Mot de passe incorrect.");
                    attempts++;
                }
            } else {
                QMessageBox::warning(&authDialog, "Erreur", "Utilisateur introuvable.");
                attempts++;
            }
        });

        QObject::connect(forgotPasswordButton, &QPushButton::clicked, [&]() {
            authDialog.close();
            motDePasseOublie();
        });

        QObject::connect(&authDialog, &QDialog::rejected, [&]() {
            attempts = 2;
        });

        if (authDialog.exec() == QDialog::Rejected || attempts >= 2) {
            return false;
        }
    }

    return true;
}



void gemploye::motDePasseOublie() {
    QString email = QInputDialog::getText(this, "Mot de passe oublié", "Entrez votre adresse e-mail :");

    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse e-mail.");
        return;
    }

    // Vérifier si l'email existe dans la base de données
    QSqlQuery query;
    query.prepare("SELECT ID_EMP, TELEPHONE FROM EMPLOYES WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Échec de la requête : " + query.lastError().text());
        return;
    }

    if (!query.next()) {
        QMessageBox::critical(this, "Erreur", "Email non trouvé.");
        return;
    }

    QString phoneNumber = query.value("TELEPHONE").toString().trimmed();
    if (phoneNumber.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Numéro de téléphone non trouvé.");
        return;
    }

    // Générer un code aléatoire de réinitialisation
    QString resetCode = QString::number(QRandomGenerator::global()->bounded(100000, 999999));

    // Envoyer le code par SMS via Twilio
    envoyerSMSCode(phoneNumber, resetCode);

    // Demander à l'utilisateur de saisir le code reçu
    bool ok;
    QString enteredCode = QInputDialog::getText(this, "Code de réinitialisation", "Entrez le code envoyé par SMS :", QLineEdit::Normal, "", &ok);

    if (ok && enteredCode == resetCode) {
        // Le code est correct, permettre à l'utilisateur de réinitialiser son mot de passe
        QString newPassword = QInputDialog::getText(this, "Nouveau mot de passe", "Entrez votre nouveau mot de passe :");

        if (newPassword.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez entrer un nouveau mot de passe.");
            return;
        }

        // Mettre à jour le mot de passe dans la base de données
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE EMPLOYES SET MDP = :newPassword WHERE EMAIL = :email");
        updateQuery.bindValue(":newPassword", newPassword);
        updateQuery.bindValue(":email", email);

        if (!updateQuery.exec()) {
            QMessageBox::critical(this, "Erreur SQL", "Échec de la mise à jour du mot de passe : " + updateQuery.lastError().text());
        } else {
            QMessageBox::information(this, "Succès", "Votre mot de passe a été réinitialisé avec succès.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Code incorrect. Réessayez.");
    }
}

void gemploye::envoyerSMSCode(const QString &phoneNumber, const QString &resetCode) {
    QString accountSID = "AC23ecaf784458972a0d603f17b12bd5c6";
    QString authToken = "37fa9015b344ec8d7b4fec782e5167a6";
    QString twilioNumber = "+14127252626";

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QString message = "Code de réinitialisation : " + resetCode;

    // Construction de l'URL de l'API Twilio
    QUrl url("https://api.twilio.com/2010-04-01/Accounts/" + accountSID + "/Messages.json");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Format international obligatoire : +216 suivi du numéro, sans espace ni caractères spéciaux
    QString fullNumber = phoneNumber;
    if (!phoneNumber.startsWith("+")) {
        fullNumber = "+216" + phoneNumber;
    }

    QUrlQuery params;
    params.addQueryItem("To", "+21651907098");
    params.addQueryItem("From", twilioNumber);
    params.addQueryItem("Body", message);

    QByteArray postData = params.toString(QUrl::FullyEncoded).toUtf8();

    // Authentification Basic
    QByteArray auth = (accountSID + ":" + authToken).toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + auth);

    QNetworkReply *reply = manager->post(request, postData);

    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "✅ SMS envoyé avec succès.";
        } else {
            qDebug() << "❌ Erreur d'envoi du SMS :" << reply->errorString();
            qDebug() << "Réponse brute :" << reply->readAll();  // Affiche le corps d'erreur JSON renvoyé par Twilio
        }
        reply->deleteLater();
    });
}

