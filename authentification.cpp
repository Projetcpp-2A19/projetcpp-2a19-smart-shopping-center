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
#include"authentification.h"
Arduino arduino;
bool gemploye::authentifierUtilisateur() {
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(nullptr, "Erreur", "Base de données non connectée.");
        return false;
    }

    int attempts = 0;

    //int connectionStatus = arduino.connect_arduino();
   // if (connectionStatus != 0) {
       // QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à Arduino.");
    //  return false;
 //}

    while (attempts < 2) {
        QDialog authDialog;
        authDialog.setWindowTitle("Authentification avec Empreinte");
        authDialog.resize(400, 400);

        authDialog.setStyleSheet(R"(
            QDialog {
                background-color: #000000;
                border-radius: 10px;
            }
            QLineEdit {
                border: 2px solid #ff66b2;
                border-radius: 8px;
                padding: 5px;
                font-size: 14px;
                background-color: black;
                color: white;
            }
            QLineEdit:focus {
                border: 2px solid #6699ff;
            }
            QPushButton {
                background-color: #6699ff;
                color: white;
                border-radius: 8px;
                padding: 8px;
                font-size: 14px;
            }
            QPushButton:hover {
                background-color: #ff66b2;
            }
        )");

        QLineEdit *emailLineEdit = new QLineEdit(&authDialog);
        emailLineEdit->setPlaceholderText("Email");
        emailLineEdit->setMinimumHeight(35);

        QLineEdit *passwordLineEdit = new QLineEdit(&authDialog);
        passwordLineEdit->setPlaceholderText("Mot de passe");
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        passwordLineEdit->setMinimumHeight(35);

        QPushButton *scanFingerprintButton = new QPushButton("Se connecter avec empreinte", &authDialog);
        scanFingerprintButton->setMinimumHeight(40);

        QPushButton *loginButton = new QPushButton("Se connecter", &authDialog);
        loginButton->setMinimumHeight(40);

        QPushButton *forgotPasswordButton = new QPushButton("Mot de passe oublié ?", &authDialog);
        forgotPasswordButton->setMinimumHeight(40);

        QVBoxLayout *layout = new QVBoxLayout(&authDialog);
        layout->setSpacing(15);
        layout->setContentsMargins(30, 30, 30, 30);
        layout->addWidget(emailLineEdit);
        layout->addWidget(passwordLineEdit);
        layout->addWidget(scanFingerprintButton);
        layout->addWidget(loginButton);
        layout->addWidget(forgotPasswordButton);

        authDialog.setLayout(layout);

        int fingerprintID = -1;
        bool fingerprintAuthenticated = false; // <<< FLAG POUR SAVOIR

        QObject::connect(scanFingerprintButton, &QPushButton::clicked, [&]() {
            arduino.write_to_arduino("SCAN\n");

            QByteArray idEmpreinteData = arduino.read_from_arduino();
            if (idEmpreinteData.isEmpty()) {
                QMessageBox::warning(&authDialog, "Erreur", "Aucune empreinte détectée.");
            } else {
                fingerprintID = idEmpreinteData.toInt();
                if (fingerprintID == -1) {
                    QMessageBox::warning(&authDialog, "Erreur", "Empreinte non reconnue.");
                } else {
                    QSqlQuery query;
                    query.prepare("SELECT EMAIL, MDP FROM EMPLOYES WHERE ID_EMPREINTE = :id");
                    query.bindValue(":id", QString::number(fingerprintID));

                    if (!query.exec()) {
                        QMessageBox::critical(nullptr, "Erreur SQL", "Échec de la requête : " + query.lastError().text());
                        return;
                    }

                    if (query.next()) {
                        QMessageBox::information(nullptr, "Succès", "Connexion réussie !");

                        // Ouvrir l'interface principale
                        gemploye *gemployeWindow = new gemploye();
                        gemployeWindow->show();

                        fingerprintAuthenticated = true; // <<< METTRE À TRUE
                        authDialog.done(QDialog::Accepted);
                    } else {
                        QMessageBox::critical(nullptr, "Erreur", "Aucun utilisateur trouvé pour cette empreinte.");
                    }
                }
            }
        });

        QObject::connect(loginButton, &QPushButton::clicked, [&]() {
            authDialog.accept();
        });

        int result = authDialog.exec();

        // ✅ Après fermeture de authDialog
        if (result == QDialog::Accepted) {
            if (fingerprintAuthenticated) {
                // Si connexion par empreinte réussie
                return true; // FINIR proprement
            }

            // Sinon, c'est une connexion par email/mot de passe
            QString email = emailLineEdit->text().trimmed();
            QString password = passwordLineEdit->text().trimmed();

            if (email.isEmpty() || password.isEmpty()) {
                QMessageBox::warning(nullptr, "Erreur", "Veuillez remplir tous les champs.");
                return false;
            }

            QSqlQuery query;
            query.prepare("SELECT EMAIL, MDP FROM EMPLOYES WHERE EMAIL = :email");
            query.bindValue(":email", email);

            if (!query.exec()) {
                QMessageBox::critical(nullptr, "Erreur SQL", "Échec de la requête : " + query.lastError().text());
                return false;
            }

            if (query.next()) {
                QString storedEmail = query.value(0).toString();
                QString storedPassword = query.value(1).toString();

                if (storedEmail == email && storedPassword == password) {
                    QMessageBox::information(nullptr, "Succès", "Connexion réussie !");

                    gemploye *gemployeWindow = new gemploye();
                    gemployeWindow->show();

                    return true;
                } else {
                    QMessageBox::critical(nullptr, "Erreur", "Email ou mot de passe incorrect.");
                    attempts++;
                }
            } else {
                QMessageBox::critical(nullptr, "Erreur", "Aucun utilisateur trouvé pour cet email.");
                attempts++;
            }
        } else {
            return false;
        }
    }

    QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion après 2 tentatives.");
    return false;
}



void gemploye::envoyerSMSCode(const QString &phoneNumber, const QString &resetCode) {
    // Paramètres Twilio
    QString accountSID = "";
    QString authToken = "";
    QString twilioNumber = "";  // Numéro Twilio

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QString message = "Votre code de réinitialisation du mot de passe est : " + resetCode;

    // Construire la requête HTTP pour Twilio
    QNetworkRequest request(QUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSID + "/Messages.json"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("To", "+21699159664"); // Ajout du préfixe de la Tunisie
    params.addQueryItem("From", twilioNumber);
    params.addQueryItem("Body", message);

    QByteArray postData = params.query().toUtf8();
    request.setRawHeader("Authorization", "Basic " + QByteArray(QString(accountSID + ":" + authToken).toUtf8()).toBase64());

    // Envoyer la requête POST
    QNetworkReply *reply = manager->post(request, postData);
    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "SMS envoyé avec succès !";
        } else {
            qDebug() << "Erreur d'envoi du SMS :" << reply->errorString();
        }
        reply->deleteLater();
    });
}
