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

    // ➤ Connexion automatique à Arduino
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

        QObject::connect(scanFingerprintButton, &QPushButton::clicked, [&]() {
            arduino.write_to_arduino("SCAN\n");
            QByteArray idEmpreinteData = arduino.read_from_arduino();

            if (idEmpreinteData.isEmpty()) {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Erreur");
                msgBox.setText("Aucune empreinte détectée.");
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
                return;
            }

            int fingerprintID = idEmpreinteData.toInt();
            if (fingerprintID == -1) {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Erreur");
                msgBox.setText("Empreinte non reconnue.");
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
                return;
            }

            QSqlQuery query;
            query.prepare("SELECT EMAIL, POSTE FROM EMPLOYES WHERE ID_EMPREINTE = :id");
            query.bindValue(":id", QString::number(fingerprintID));

            if (!query.exec()) {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Erreur SQL");
                msgBox.setText("Échec de la requête : " + query.lastError().text());
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
                return;
            }

            if (query.next()) {
                QString poste = query.value("POSTE").toString();
                if (poste == posteAutorise) {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Succès");
                    msgBox.setText("Connexion avec empreinte réussie !");
                    msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                    msgBox.exec();
                    fingerprintAuthenticated = true;
                    authDialog.accept();
                } else {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Refusé");
                    msgBox.setText("Poste non autorisé.");
                    msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                    msgBox.exec();
                }
            } else {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Erreur");
                msgBox.setText("Aucun utilisateur trouvé.");
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
            }
        });

        QObject::connect(loginButton, &QPushButton::clicked, [&]() {
            QString email = emailLineEdit->text().trimmed();
            QString password = passwordLineEdit->text().trimmed();

            if (email.isEmpty() || password.isEmpty()) {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Erreur");
                msgBox.setText("Veuillez remplir tous les champs.");
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
                return;
            }

            QSqlQuery query;
            query.prepare("SELECT MDP, POSTE FROM EMPLOYES WHERE EMAIL = :email");
            query.bindValue(":email", email);

            if (!query.exec()) {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Erreur SQL");
                msgBox.setText("Erreur lors de la requête : " + query.lastError().text());
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
                return;
            }

            if (query.next()) {
                QString mdp = query.value("MDP").toString();
                QString poste = query.value("POSTE").toString();

                if (mdp == password) {
                    if (poste == posteAutorise) {
                        QMessageBox msgBox;
                        msgBox.setWindowTitle("Succès");
                        msgBox.setText("Connexion réussie !");
                        msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                        msgBox.exec();
                        authDialog.accept();
                    } else {
                        QMessageBox msgBox;
                        msgBox.setWindowTitle("Refusé");
                        msgBox.setText("Poste non autorisé.");
                        msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                        msgBox.exec();
                    }
                } else {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Erreur");
                    msgBox.setText("Mot de passe incorrect.");
                    msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                    msgBox.exec();
                    attempts++;
                }
            } else {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Erreur");
                msgBox.setText("Aucun utilisateur trouvé.");
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
                attempts++;
            }
        });

        QObject::connect(forgotPasswordButton, &QPushButton::clicked, [&]() {
            QString email = emailLineEdit->text().trimmed();

            if (email.isEmpty()) {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Mot de passe oublié");
                msgBox.setText("Veuillez entrer votre email pour continuer.");
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
                return;
            }

            QSqlQuery query;
            query.prepare("SELECT EMAIL FROM EMPLOYES WHERE EMAIL = :email");
            query.bindValue(":email", email);

            if (query.exec() && query.next()) {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Mot de passe oublié");
                msgBox.setText("Un mot de passe temporaire ou un lien de réinitialisation a été envoyé à votre adresse.");
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
            } else {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Erreur");
                msgBox.setText("Adresse email introuvable.");
                msgBox.setStyleSheet("QMessageBox { background-color: #ff66b2; } QLabel { color: white; } QPushButton { color: white; background-color: #3366cc; }");
                msgBox.exec();
            }
        });

        int result = authDialog.exec();

        if (result == QDialog::Accepted) {
            return true;
        }
    }

    QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion après 2 tentatives.");
    return false;
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
