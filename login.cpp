#include "login.h"  // Nom du fichier en minuscule pour correspondre au projet
#include "ui_Login.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login) // Initialisation correcte
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

// Bouton de connexion
void Login::on_pushButton_login_clicked()
{
    QString email = ui->lineEdit_email->text().trimmed();
    QString password = ui->lineEdit_password->text().trimmed();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM utilisateurs WHERE email = :email AND password = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", password); // ⚠️ Hachage recommandé (ex: SHA-256)

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Échec de la requête : " + query.lastError().text());
        return;
    }

    if (query.next()) {
        accept(); // Connexion réussie, fermer la fenêtre
    } else {
        QMessageBox::critical(this, "Erreur", "Email ou mot de passe incorrect.");
    }
}
