#include "authentification.h"  // Inclure le fichier où la fonction est définie
#include "gevennement.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, "Erreur de connexion", "Échec de connexion à la base de données.");
        return -1;
    }

    // Crée une instance de la classe GEvennement
    GEvennement gEvent;

    // Vérification de l'authentification avant d'afficher l'interface principale
    if (!gEvent.authentifierUtilisateur()) {
        return 0;  // Quitte l'application si l'authentification échoue
    }

    // Si l'authentification réussit, on affiche l'interface principale
    gEvent.show();

    return a.exec();
}
