#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
<<<<<<< HEAD
#include <QDebug>
#include <QMessageBox> // For showing error messages
=======
>>>>>>> 8e8154f50e00950fb99a2f5f6515142693c4f1c2

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
<<<<<<< HEAD
=======
    void closeConnection();
>>>>>>> 8e8154f50e00950fb99a2f5f6515142693c4f1c2
};

#endif // CONNECTION_H
