#include "gevennement.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection conn; // Créer une instance de la classe Connection
    if (conn.createconnect()) {
        qDebug() << "Connexion réussie à la base de données!";
        QMessageBox::information(nullptr, "Connexion", "Connexion réussie !");

    } else {
        qDebug() << "Échec de la connexion :" << QSqlDatabase::database().lastError().text();

        // Afficher un message d'erreur et demander à l'utilisateur s'il veut quitter
        QMessageBox::StandardButton reply;
        reply = QMessageBox::critical(nullptr, "Connexion",
                                      "Échec de la connexion à la base de données.\n"
                                      "Voulez-vous quitter l'application ?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            return -1;  // Arrêt du programme en cas d'échec
        } else {
            // Si l'utilisateur choisit de ne pas quitter, vous pouvez décider de continuer
            // Par exemple, vous pouvez afficher une fenêtre de connexion ou faire autre chose
            // Pour cet exemple, nous allons simplement quitter le programme
            return 0; // Quitter l'application
        }
    }

    GEvennement w; // Créer et afficher la fenêtre principale
    w.show();

    int result = a.exec();

    // Fermer la connexion à la base de données avant de quitter
    QSqlDatabase::database().close();
    return result;
}

