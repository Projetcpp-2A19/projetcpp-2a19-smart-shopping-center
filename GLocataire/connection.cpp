#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;

    // Initialize the database connection with QODBC
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    // Set the database name (this should match the ODBC data source name)
    db.setDatabaseName("Source_Projet2A");  // Ensure the ODBC DSN is configured properly in your system
    db.setUserName("EYK");
    db.setPassword("EYK123");

    // Attempt to open the database
    if (db.open()) {


        test = true;
    }

    // Return the connection status
    return test;
}
