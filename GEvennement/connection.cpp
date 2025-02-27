#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    // Initialize the database connection with QODBC
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");  // Ensure the ODBC DSN is configured properly in your system
    db.setUserName("EYK");
    db.setPassword("EYK123");


    if (db.open())
        test=true;





    return  test;
}
