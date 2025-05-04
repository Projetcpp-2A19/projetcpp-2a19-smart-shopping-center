#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
<<<<<<< HEAD
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données
=======
    db.setDatabaseName("Source _Projet2A");//inserer le nom de la source de données
>>>>>>> 8e8154f50e00950fb99a2f5f6515142693c4f1c2
    db.setUserName("EYK");//inserer nom de l'utilisateur
    db.setPassword("EYK123");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
<<<<<<< HEAD
=======
void Connection::closeConnection(){db.close();}
>>>>>>> 8e8154f50e00950fb99a2f5f6515142693c4f1c2
