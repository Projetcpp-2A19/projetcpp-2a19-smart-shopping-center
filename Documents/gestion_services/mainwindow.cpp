#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Afficher les services au démarrage
    on_pushButton_Afficher_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Ajouter un service
void MainWindow::on_pushButton_Ajouter_clicked()
{
    QString id = ui->lineEdit_ID->text();
    QString type = ui->lineEdit_type->text();
    QString cible = ui->lineEdit_cible->text();
    QString statut = ui->lineEdit_statut->text();
    QString priorite = ui->lineEdit_priorite->text();

    Service service(id, type, cible, statut, priorite);
    bool test = service.ajouter();

    if (test) {
        QMessageBox::information(this, "Succès", "Service ajouté avec succès !");
        on_pushButton_Afficher_clicked();  // Actualiser l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du service !");
    }
}

// Modifier un service
void MainWindow::on_pushButton_Modifier_clicked()
{
    QString id = ui->lineEdit_ID->text();
    QString type = ui->lineEdit_type->text();
    QString cible = ui->lineEdit_cible->text();
    QString statut = ui->lineEdit_statut->text();
    QString priorite = ui->lineEdit_priorite->text();

    Service service(id, type, cible, statut, priorite);
    bool test = service.modifier(id);

    if (test) {
        QMessageBox::information(this, "Succès", "Service modifié avec succès !");
        on_pushButton_Afficher_clicked();  // Actualiser l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du service !");
    }
}

// Supprimer un service
void MainWindow::on_pushButton_Supprimer_clicked()
{
    QString id = ui->lineEdit_ID->text();

    bool test = service.supprimer(id);

    if (test) {
        QMessageBox::information(this, "Succès", "Service supprimé avec succès !");
        on_pushButton_Afficher_clicked();  // Actualiser l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du service !");
    }
}

// Afficher les services
void MainWindow::on_pushButton_Afficher_clicked()
{
    QSqlQueryModel* model = Service::afficher();
    ui->tableView->setModel(model);
}
