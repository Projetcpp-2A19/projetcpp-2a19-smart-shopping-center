#include "dashboard.h"
#include "ui_dashboard.h"
#include"QMessageBox"
#include "gemploye.h"
#include "ui_gemploye.h"
#include <QMessageBox>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDialog>           // Pour créer une boîte de dialogue personnalisée
#include <QFormLayout>       // Pour structurer les champs de saisie dans la boîte de dialogue
#include <QLineEdit>         // Pour les champs de saisie de texte
#include <QPushButton>       // Pour les boutons dans la boîte de dialogue
#include <QHBoxLayout>
#include <QRegularExpression>
#include <QPrinter>
#include <QTextDocument>
#include <QSqlQuery>
#include <QFileDialog>
#include<QPdfWriter>
#include <QInputDialog>
#include <QBuffer>
#include <QPainter>

#include <QImage>
#include<arduino.h>
#include <qthread.h>
#include<qtimer.h>
#include"gemploye.h"

#include"authentification.h"

#include"glocataires.h"
#include"gevennement.h"

#include "gboutique.h"
dashboard::dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dashboard)
{
    ui->setupUi(this);
    // Activer l'adaptation des images à la taille des labels
    ui->lbl_Logo_Display->setScaledContents(true);
    ui->lbl_Logo_Display->setScaledContents(true);

    // Charger l'image principale
    QString imagePath = QCoreApplication::applicationDirPath() + "/photo.jpg";
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        ui->lbl_Logo_Display->setPixmap(pixmap);
    } else {
        //QMessageBox::warning(this, "Erreur", "Impossible de charger l'image : " + imagePath);
    }
    ui->lbl_Logo_Display->setAlignment(Qt::AlignCenter);

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

dashboard::~dashboard()
{
    delete ui;
}


void dashboard::on_pushButton_Employes_clicked()
{
    gemploye temp;
    if (temp.authentifierUtilisateur("Admin")) {
        gemploye *employeWindow = new gemploye(this);
        employeWindow->show();
    }
}

void dashboard::on_pushButton_Locataires_clicked()
{
    gemploye temp;
    if (temp.authentifierUtilisateur("Agent Locataire")) {
        GLocataire *locataireWindow = new GLocataire(this);
        locataireWindow->show();
    }
}

void dashboard::on_pushButton_Evennements_clicked()
{
    gemploye temp;
    if (temp.authentifierUtilisateur("Responsable Evenement")) {
        GEvennement *eventWindow = new GEvennement(this);
        eventWindow->show();
    }
}

void dashboard::on_pushButton_Boutiques_clicked()
{
    gemploye temp;
    if (temp.authentifierUtilisateur("Responsable Boutique")) {
        gboutique *boutiqueWindow = new gboutique(this);
        boutiqueWindow->show();
    }
}
