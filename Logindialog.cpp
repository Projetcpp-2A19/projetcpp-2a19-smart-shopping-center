#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    authenticated(false)
{
    ui->setupUi(this);
    setWindowTitle("Authentification");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_Login_clicked()
{
    const QString email = ui->lineEdit_Email->text().trimmed();
    const QString password = ui->lineEdit_Password->text().trimmed();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM utilisateurs WHERE email = :email AND password = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", password); // ⚠️ En production, stocke les mots de passe hachés !

    if (query.exec()) {
        if (query.next()) { // Vérifie si un utilisateur correspondant existe
            authenticated = true;
            accept();  // Ferme le dialogue et retourne `QDialog::Accepted`
        } else {
            QMessageBox::critical(this, "Erreur", "Email ou mot de passe incorrect.");
        }
    } else {
        QMessageBox::critical(this, "Erreur SQL", "Échec de la requête : " + query.lastError().text());
    }
}
