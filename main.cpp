#include "authentification.h"
#include "gemploye.h"
#include"glocataires.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include "gevennement.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, "Erreur de connexion", "Échec de connexion à la base de données.");
        return -1;
    }

    // Crée une instance de la classe GEvennement
    gemploye gemploye;
    //GLocataire w;
   // GEvennement e;

    // Vérification de l'authentification avant d'afficher l'interface principale
    if (!gemploye.authentifierUtilisateur()) {
        return 0;  // Quitte l'application si l'authentification échoue
    }

    // Si l'authentification réussit, on affiche l'interface principale
   // gemploye.show();
    // w.show();
    return a.exec();
}
