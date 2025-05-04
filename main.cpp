<<<<<<< HEAD
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
=======
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


>>>>>>> 8e8154f50e00950fb99a2f5f6515142693c4f1c2

    return a.exec();
}
