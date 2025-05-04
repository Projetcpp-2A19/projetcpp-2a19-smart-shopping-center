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
        QMessageBox msgBox;
        msgBox.setWindowTitle("Erreur");
        msgBox.setText("Base de données non connectée.");
        msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
        msgBox.exec();
        return false;
    }

    if (arduino.connect_arduino() == -1) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Erreur Arduino");
        msgBox.setText("Impossible de connecter la carte Arduino.");
        msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
        msgBox.exec();
        return false;
    }

    int attempts = 0;
    bool fingerprintAuthenticated = false;

    while (attempts < 2) {
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
        layout->setSpacing(15);
        layout->setContentsMargins(30, 30, 30, 30);
        layout->addWidget(emailLineEdit);
        layout->addWidget(passwordLineEdit);
        layout->addWidget(scanFingerprintButton);
        layout->addWidget(loginButton);
        layout->addWidget(forgotPasswordButton);
        authDialog.setLayout(layout);

        QObject::connect(&authDialog, &QDialog::rejected, [&]() {
            attempts = 2;
        });

        // Connexion par empreinte
        QObject::connect(scanFingerprintButton, &QPushButton::clicked, [&]() {
            arduino.write_to_arduino("SCAN\n");
            QByteArray idEmpreinteData = arduino.read_from_arduino();

            if (idEmpreinteData.isEmpty()) {
                QMessageBox::warning(&authDialog, "Erreur", "Aucune empreinte détectée.");
                return;
            }

            int fingerprintID = idEmpreinteData.toInt();
            if (fingerprintID == -1) {
                QMessageBox::warning(&authDialog, "Erreur", "Empreinte non reconnue.");
                return;
            }

            QSqlQuery query;
            query.prepare("SELECT NOM, EMAIL, POSTE FROM EMPLOYES WHERE ID_EMPREINTE = :id");
            query.bindValue(":id", QString::number(fingerprintID));

            if (!query.exec()) {
                QMessageBox::critical(&authDialog, "Erreur SQL", "Échec de la requête : " + query.lastError().text());
                return;
            }

            if (query.next()) {
                QString poste = query.value("POSTE").toString();
                QString nomComplet = query.value("NOM").toString(); // Utilisation du champ NOM

                if (poste == posteAutorise) {
                    // Envoi à Arduino
                    arduino.write_to_arduino("Bienvenue, " + nomComplet.toUtf8() + "\n");

                    // Affichage du message dans une boite de dialogue
                    QMessageBox::information(&authDialog, "Succès", "Connexion avec empreinte réussie !");
                    fingerprintAuthenticated = true;
                    authDialog.accept();
                } else {
                    QMessageBox::warning(&authDialog, "Refusé", "Poste non autorisé.");
                }
            } else {
                QMessageBox::warning(&authDialog, "Erreur", "Aucun utilisateur trouvé.");
            }
        });

        // Connexion par email et mot de passe
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
                QMessageBox::critical(&authDialog, "Erreur SQL", "Erreur lors de la requête : " + query.lastError().text());
                return;
            }

            if (query.next()) {
                QString mdp = query.value("MDP").toString();
                QString poste = query.value("POSTE").toString();
                QString nom = query.value("NOM").toString();

                if (mdp == password) {
                    if (poste == posteAutorise) {
                        // Envoi à Arduino
                        arduino.write_to_arduino("Bienvenue, " + nom.toUtf8() + "\n");

                        QMessageBox::information(&authDialog, "Succès", "Connexion réussie !");
                        authDialog.accept();
                    } else {
                        QMessageBox::warning(&authDialog, "Refusé", "Poste non autorisé.");
                    }
                } else {
                    QMessageBox::warning(&authDialog, "Erreur", "Mot de passe incorrect.");
                    attempts++;
                }
            } else {
                QMessageBox::warning(&authDialog, "Erreur", "Aucun utilisateur trouvé.");
                attempts++;
            }
        });

        // Mot de passe oublié
        QObject::connect(forgotPasswordButton, &QPushButton::clicked, [&]() {
            authDialog.close();
            motDePasseOublie();
        });

        int result = authDialog.exec();

        if (result == QDialog::Accepted) {
            return true;
        }
    }

    QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion après 2 tentatives.");
    return false;
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
    QString accountSID = "AC6fec22b2984b9ffe0655eeb40ee721ce";
    QString authToken = "58df0660acc56e1ee61c5e50bd21ccb6";
    QString twilioNumber = "+19898229939";

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QString message = "Code de réinitialisation : " + resetCode;

    QUrl url("https://api.twilio.com/2010-04-01/Accounts/" + accountSID + "/Messages.json");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("To", "+216" + phoneNumber); // s'assurer que le numéro est bien au format tunisien
    params.addQueryItem("From", twilioNumber);
    params.addQueryItem("Body", message);

    QByteArray postData = params.query(QUrl::FullyEncoded).toUtf8();
    QString credentials = accountSID + ":" + authToken;
    request.setRawHeader("Authorization", "Basic " + QByteArray(credentials.toUtf8()).toBase64());

    QNetworkReply *reply = manager->post(request, postData);
    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "SMS envoyé avec succès.";
        } else {
            qDebug() << "Erreur d'envoi du SMS :" << reply->errorString();
        }
        reply->deleteLater();
    });
}
