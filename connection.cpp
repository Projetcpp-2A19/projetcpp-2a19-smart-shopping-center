#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source _Projet2A");//inserer le nom de la source de données
    db.setUserName("EYK");//inserer nom de l'utilisateur
    db.setPassword("EYK123");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
void Connection::closeConnection(){db.close();}
