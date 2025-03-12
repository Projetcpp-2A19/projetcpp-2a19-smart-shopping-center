#include "gevennement.h"
#include "ui_gevennement.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidgetItem>

GEvennement::GEvennement(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GEvennement) {
    ui->setupUi(this);

    // Activer l'adaptation des images à la taille des labels
    ui->lbl_Image_Display->setScaledContents(true);
    ui->lbl_Logo_Display->setScaledContents(true);

    // Charger l'image principale
    QString imagePath = QCoreApplication::applicationDirPath() + "/photo.jpg";
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        ui->lbl_Image_Display->setPixmap(pixmap);
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de charger l'image : " + imagePath);
    }
    ui->lbl_Image_Display->setAlignment(Qt::AlignCenter);

    // Charger le logo
    QString logoPath = QCoreApplication::applicationDirPath() + "/logo.gif";
    QPixmap logoPixmap(logoPath);
    if (!logoPixmap.isNull()) {
        ui->lbl_Logo_Display->setPixmap(logoPixmap);
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de charger le logo : " + logoPath);
    }
    ui->lbl_Logo_Display->setAlignment(Qt::AlignCenter);

    // Configurer la connexion à la base de données
    db = QSqlDatabase::addDatabase("QODBC", "boutiques_connection"); // Nom unique pour la connexion
    db.setDatabaseName("Source_Projet2A"); // Nom de la source de données ODBC
    db.setUserName("EYK"); // Nom d'utilisateur
    db.setPassword("EYK123"); // Mot de passe

    if (!db.open()) {
        QMessageBox::critical(this, "Erreur", "Erreur de connexion à la base de données : " + db.lastError().text());
    } else {
        QMessageBox::information(this, "Succès", "Connexion à la base de données réussie !");
    }

    // Connecter les boutons à leurs slots respectifs
    connect(ui->pushButton_Ajouter, &QPushButton::clicked, this, &GEvennement::on_pushButton_Ajouter_clicked);
    connect(ui->pushButton_Boutiques, &QPushButton::clicked, this, &GEvennement::loadBoutiques);
    connect(ui->pushButton_Supprimer, &QPushButton::clicked, this, &GEvennement::on_pushButton_Supprimer_clicked);

    // Charger les boutiques au démarrage de l'application (optionnel)
    loadBoutiques();
}

GEvennement::~GEvennement() {
    delete ui;
    db.close(); // Fermer la connexion à la base de données
}

bool GEvennement::boutiqueExists(int id) {
    QSqlQuery query(db);
    query.prepare("SELECT ID_BOUTIQUE FROM boutiques WHERE ID_BOUTIQUE = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return true; // La boutique existe déjà
    }
    return false; // La boutique n'existe pas
}

void GEvennement::on_pushButton_Ajouter_clicked() {
    // Récupérer les données saisies dans les champs
    QString id = ui->line_IDboutique->text();
    QString nom = ui->line_NOMboutique->text();
    QString type = ui->line_TYPEboutique->text();
    QString localisation = ui->line_LOCALISATIONboutique->text();
    QString surface = ui->line_SURFACEboutique->text();
    QString montant = ui->line_MONTANTboutique->text();
    QString etat = ui->comboBox_ETATboutique->currentText(); // Récupérer la valeur du QComboBox
    QString horaire = ui->timeEdit_HORAIRE->time().toString("HH:mm");

    // Vérifier que tous les champs obligatoires sont remplis
    if (id.isEmpty() || nom.isEmpty() || type.isEmpty() || localisation.isEmpty() ||
        surface.isEmpty() || montant.isEmpty() || etat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires !");
        return;
    }

    // Vérifier si la boutique existe déjà
    if (boutiqueExists(id.toInt())) {
        QMessageBox::warning(this, "Erreur", "Une boutique avec cet ID existe déjà !");
        return;
    }

    // Préparer la requête SQL
    QSqlQuery query(db);
    query.prepare("INSERT INTO boutiques (ID_BOUTIQUE, NOM, TYPE, LOCALISATION, SURFACE, MONTANT, ETAT, HORAIRE_OUVERTURE) "
                  "VALUES (:id, :nom, :type, :localisation, :surface, :montant, :etat, :horaire)");
    query.bindValue(":id", id.toInt());
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":localisation", localisation);
    query.bindValue(":surface", surface.toInt());
    query.bindValue(":montant", montant.toInt());
    query.bindValue(":etat", etat); // Utiliser la valeur du QComboBox
    query.bindValue(":horaire", horaire);

    // Exécuter la requête
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Boutique ajoutée avec succès !");
        // Effacer les champs après l'ajout
        ui->line_IDboutique->clear();
        ui->line_NOMboutique->clear();
        ui->line_TYPEboutique->clear();
        ui->line_LOCALISATIONboutique->clear();
        ui->line_SURFACEboutique->clear();
        ui->line_MONTANTboutique->clear();
        ui->comboBox_ETATboutique->setCurrentIndex(0); // Réinitialiser le QComboBox
        ui->timeEdit_HORAIRE->setTime(QTime(0, 0));

        // Actualiser le tableau des boutiques
        loadBoutiques();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout : " + query.lastError().text());
    }
}

void GEvennement::loadBoutiques() {
    // Effacer le contenu actuel du QTableWidget
    ui->tableWidget_Boutique->clearContents();
    ui->tableWidget_Boutique->setRowCount(0);

    // Définir les en-têtes de colonnes
    QStringList headers = {"ID", "Nom", "Type", "Localisation", "Surface", "Montant", "État", "Horaire"};
    ui->tableWidget_Boutique->setColumnCount(headers.size());
    ui->tableWidget_Boutique->setHorizontalHeaderLabels(headers);

    // Exécuter une requête SQL pour récupérer les boutiques
    QSqlQuery query(db);
    if (!query.exec("SELECT ID_BOUTIQUE, NOM, TYPE, LOCALISATION, SURFACE, MONTANT, ETAT, HORAIRE_OUVERTURE FROM boutiques")) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des boutiques : " + query.lastError().text());
        return;
    }

    // Remplir le QTableWidget avec les données de la base de données
    int row = 0;
    while (query.next()) {
        ui->tableWidget_Boutique->insertRow(row);
        for (int col = 0; col < headers.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget_Boutique->setItem(row, col, item);
        }
        row++;
    }
}



void GEvennement::on_pushButton_Supprimer_clicked() {
    // Récupérer la ligne sélectionnée dans le QTableWidget
    int selectedRow = ui->tableWidget_Boutique->currentRow();

    // Vérifier si une ligne est sélectionnée
    if (selectedRow == -1) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une boutique à supprimer !");
        return;
    }

    // Récupérer l'ID de la boutique sélectionnée
    QString id = ui->tableWidget_Boutique->item(selectedRow, 0)->text();

    // Demander une confirmation avant de supprimer
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer cette boutique ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return; // Annuler la suppression
    }

    // Exécuter la requête SQL pour supprimer la boutique
    QSqlQuery query(db);
    query.prepare("DELETE FROM boutiques WHERE ID_BOUTIQUE = :id");
    query.bindValue(":id", id.toInt());

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Boutique supprimée avec succès !");
        // Actualiser le tableau des boutiques
        loadBoutiques();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression : " + query.lastError().text());
    }
}
