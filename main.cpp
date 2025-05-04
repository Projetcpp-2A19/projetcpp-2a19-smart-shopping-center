#include "connection.h"
#include "dashboard.h"  // Assure-toi que ce fichier existe bien
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

    dashboard dashboard;
    dashboard.show();

    return a.exec();
}
