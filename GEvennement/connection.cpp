#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

Connection::Connection()
{
}

bool Connection::createconnect()
{
    // Initialize the database connection with QODBC
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");  // Ensure the ODBC DSN is configured properly in your system
    db.setUserName("EYK");
    db.setPassword("EYK123");

    // Attempt to open the database
    if (db.open()) {
        return true;  // Return true if the connection was successful
    } else {
        // Print the error message in case the connection fails
        qDebug() << "Database connection failed: " << db.lastError().text();
        return false;  // Return false if the connection failed
    }
}
