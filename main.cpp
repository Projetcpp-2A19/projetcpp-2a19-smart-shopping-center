#include "gevennement.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection conn;
    if (conn.createconnect()) {
        qDebug() << "Connexion réussie à la base de données!";
        QMessageBox::information(nullptr, "Connexion", "Connexion réussie !");
    } else {
        qDebug() << "Échec de la connexion :" << QSqlDatabase::database().lastError().text();
        QMessageBox::critical(nullptr, "Connexion", "Échec de la connexion !");
        return -1;  // Arrêt du programme en cas d'échec
    }

    GEvennement w;
    w.show();

    return a.exec();
}

