#include "gevennement.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GEvennement w;
    w.show();

    int result = a.exec();

    // Fermer la connexion à la base de données avant de quitter
    QSqlDatabase::database().close();
    return result;
}
