#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include <QMainWindow>
#include <QSqlDatabase>      // Pour gérer la connexion à la base de données
#include <QSqlQuery>         // Pour exécuter des requêtes SQL
#include <QSqlError>         // Pour gérer les erreurs SQL
#include <QMessageBox>       // Pour afficher des messages
#include "ui_gevennement.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GEvennement;
}
QT_END_NAMESPACE

class GEvennement : public QMainWindow
{
    Q_OBJECT

public:
    GEvennement(QWidget *parent = nullptr);
    ~GEvennement();

private slots:
    void on_pushButton_Ajouter_clicked(); // Slot pour le bouton "Ajouter"

private:
    Ui::GEvennement *ui;
    QSqlDatabase db; // Objet pour gérer la connexion à la base de données
};

#endif // GEVENNEMENT_H
