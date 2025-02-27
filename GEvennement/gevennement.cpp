#include "gevennement.h"
#include "ui_gevennement.h"
#include <QMessageBox> // Pour afficher un message en cas d'erreur de chargement d'image

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
}

GEvennement::~GEvennement()
{
    delete ui;
}
