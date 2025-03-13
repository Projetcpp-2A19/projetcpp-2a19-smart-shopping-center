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

    // Contrôles de saisie
    if (id.isEmpty() || type.isEmpty() || cible.isEmpty() || statut.isEmpty() || priorite.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    // Vérifier que la priorité est un nombre valide entre 0 et 1
    bool ok;
    double prioriteDouble = priorite.toDouble(&ok);
    if (!ok || prioriteDouble < 0 || prioriteDouble > 1) {
        QMessageBox::warning(this, "Erreur", "La priorité doit être un nombre entre 0 et 1 !");
        return;
    }

    // Vérifier que la cible est "enfant" ou "adulte"
    if (cible.toLower() != "enfant" && cible.toLower() != "adulte") {
        QMessageBox::warning(this, "Erreur", "La cible doit être 'enfant' ou 'adulte' !");
        return;
    }

    // Vérifier que le type est "homme" ou "femme"
    if (type.toLower() != "homme" && type.toLower() != "femme") {
        QMessageBox::warning(this, "Erreur", "Le type doit être 'homme' ou 'femme' !");
        return;
    }

    // Vérifier que le statut est 0 ou 1
    if (statut != "0" && statut != "1") {
        QMessageBox::warning(this, "Erreur", "Le statut doit être 0 ou 1 !");
        return;
    }

    // Ajouter le service
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

    // Contrôles de saisie
    if (id.isEmpty() || type.isEmpty() || cible.isEmpty() || statut.isEmpty() || priorite.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    // Vérifier que la priorité est un nombre valide entre 0 et 1
    bool ok;
    double prioriteDouble = priorite.toDouble(&ok);
    if (!ok || prioriteDouble < 0 || prioriteDouble > 1) {
        QMessageBox::warning(this, "Erreur", "La priorité doit être un nombre entre 0 et 1 !");
        return;
    }

    // Vérifier que la cible est "enfant" ou "adulte"
    if (cible.toLower() != "enfant" && cible.toLower() != "adulte") {
        QMessageBox::warning(this, "Erreur", "La cible doit être 'enfant' ou 'adulte' !");
        return;
    }

    // Vérifier que le type est "homme" ou "femme"
    if (type.toLower() != "homme" && type.toLower() != "femme") {
        QMessageBox::warning(this, "Erreur", "Le type doit être 'homme' ou 'femme' !");
        return;
    }

    // Vérifier que le statut est 0 ou 1
    if (statut != "0" && statut != "1") {
        QMessageBox::warning(this, "Erreur", "Le statut doit être 0 ou 1 !");
        return;
    }

    // Modifier le service
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

    // Vérifier que l'ID existe déjà
    if (!Service::existeDeja(id)) {
        QMessageBox::warning(this, "Erreur", "Cet ID n'existe pas !");
        return;
    }

    // Supprimer le service
    bool test = Service::supprimer(id);

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
