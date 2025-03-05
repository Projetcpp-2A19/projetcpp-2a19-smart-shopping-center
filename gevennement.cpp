#include "gevennement.h"
#include "ui_gevennement.h"
#include <QMessageBox> // Pour afficher un message en cas d'erreur de chargement d'image
#include <QSqlDatabase> // Pour gérer la connexion à la base de données
#include <QSqlQuery>    // Pour exécuter des requêtes SQL
#include <QSqlError>    // Pour gérer les erreurs SQL

GEvennement::GEvennement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GEvennement)
{
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
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données
    db.setUserName("EYK");//inserer nom de l'utilisateur
    db.setPassword("EYK123");//inserer mot de passe de cet utilisateur

    if (!db.open()) {
        QMessageBox::critical(this, "Erreur", "Erreur de connexion à la base de données : " + db.lastError().text());
    } else {
        QMessageBox::information(this, "Succès", "Connexion à la base de données réussie !");
    }

    // Connecter le bouton "Ajouter" à la fonction on_pushButton_Ajouter_clicked
    connect(ui->pushButton_Ajouter, &QPushButton::clicked, this, &GEvennement::on_pushButton_Ajouter_clicked);
}

GEvennement::~GEvennement()
{
    delete ui;
    db.close(); // Fermer la connexion à la base de données
}

void GEvennement::on_pushButton_Ajouter_clicked()
{
    // Récupérer les données saisies dans les champs
    QString id = ui->line_IDboutique->text();
    QString nom = ui->line_NOMboutique->text();
    QString type = ui->line_TYPEboutique->text();
    QString localisation = ui->line_LOCALISATIONboutique->text();
    QString surface = ui->line_SURFACEboutique->text();
    QString montant = ui->line_MONTANTboutique->text();
    QString etat = ui->line_ETATboutique->text();
    QString horaire = ui->timeEdit_HORAIRE->time().toString("HH:mm");

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || nom.isEmpty() || type.isEmpty() || localisation.isEmpty() ||
        surface.isEmpty() || montant.isEmpty() || etat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Préparer la requête SQL
    QSqlQuery query;
    query.prepare("INSERT INTO boutiques (ID_BOUTIQUE, NOM, TYPE, LOCALISATION, SURFACE, MONTANT, ETAT, HORAIRE_OUVERTURE) "
                  "VALUES (:id, :nom, :type, :localisation, :surface, :montant, :etat, :horaire)");
    query.bindValue(":id", id.toInt());
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":localisation", localisation);
    query.bindValue(":surface", surface.toInt());
    query.bindValue(":montant", montant.toInt());
    query.bindValue(":etat", etat);
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
        ui->line_ETATboutique->clear();
        ui->timeEdit_HORAIRE->setTime(QTime(0, 0));
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout : " + query.lastError().text());
    }
}
