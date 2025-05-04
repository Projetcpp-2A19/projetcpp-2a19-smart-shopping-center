#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
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
        on_pushButton_Afficher_clicked();// Actualiser l'affichage
        viderChamps(); //init les line edite
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du service !");
    }
}

// Modifier un service
void MainWindow::on_pushButton_Modifier_clicked()
{

    QString id = ui->lineEdit_ID->text();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir l'ID du service à modifier !");
        return;
    }

    // Vérifier si l'ID existe
    if (!Service::existeDeja(id)) {
        QMessageBox::warning(this, "Erreur", "Cet ID n'existe pas !");
        return;
    }

    // Récupérer les valeurs existantes
    QSqlQuery query;
    query.prepare("SELECT * FROM SERVICES WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données !");
        return;
    }

    QString oldType = query.value("TYPE").toString();
    QString oldCible = query.value("CIBLE").toString();
    QString oldStatut = query.value("STATUT").toString();
    QString oldPriorite = query.value("PRIORITE").toString();

    // Récupérer les champs saisis (ou garder l'ancien si vide)
    QString type = ui->lineEdit_type->text().isEmpty() ? oldType : ui->lineEdit_type->text();
    QString cible = ui->lineEdit_cible->text().isEmpty() ? oldCible : ui->lineEdit_cible->text();
    QString statut = ui->lineEdit_statut->text().isEmpty() ? oldStatut : ui->lineEdit_statut->text();
    QString priorite = ui->lineEdit_priorite->text().isEmpty() ? oldPriorite : ui->lineEdit_priorite->text();

    // Vérifications des nouvelles valeurs
    bool ok;
    double prioriteDouble = priorite.toDouble(&ok);
    if (!ok || prioriteDouble < 0 || prioriteDouble > 1) {
        QMessageBox::warning(this, "Erreur", "La priorité doit être un nombre entre 0 et 1 !");
        return;
    }

    if (cible.toLower() != "enfant" && cible.toLower() != "adulte") {
        QMessageBox::warning(this, "Erreur", "La cible doit être 'enfant' ou 'adulte' !");
        return;
    }

    if (type.toLower() != "homme" && type.toLower() != "femme") {
        QMessageBox::warning(this, "Erreur", "Le type doit être 'homme' ou 'femme' !");
        return;
    }

    if (statut != "0" && statut != "1") {
        QMessageBox::warning(this, "Erreur", "Le statut doit être 0 ou 1 !");
        return;
    }
    QString statutAncien;
    QSqlQuery q;
    q.prepare("SELECT STATUT FROM SERVICES WHERE ID_SERVICE = :id");
    q.bindValue(":id", id);
    if (q.exec() && q.next()) {
        statutAncien = q.value(0).toString();
    }


    // Modifier le service avec les nouvelles valeurs
    Service service(id, type, cible, statut, priorite);
    bool test = service.modifier(id);

    if (test) {
        QMessageBox::information(this, "Succès", "Service modifié avec succès !");
        on_pushButton_Afficher_clicked();
        viderChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du service !");
    }
    if (test) {
        QMessageBox::information(this, "Succès", "Service modifié !");
        Service::enregistrerHistorique(id, "Modification", statutAncien, statut);
        sauvegarderHistoriqueDansFichier(id, "Modification", statutAncien, statut); // 👈 ICI
         envoyerNotification(id, statut, priorite, type, cible);
        on_pushButton_Afficher_clicked();
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

    // Lire les infos du service AVANT suppression
    QString statut = "0", priorite = "-", type = "-", cible = "-";
    QSqlQuery query;
    query.prepare("SELECT STATUT, PRIORITE, TYPE, CIBLE FROM SERVICES WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        statut = query.value(0).toString();
        priorite = query.value(1).toString();
        type = query.value(2).toString();
        cible = query.value(3).toString();
    }

    // 🟡 Archiver le service avant suppression
    sauvegarderHistoriqueSuppression(id, type, cible, statut, priorite);

    // Supprimer le service
    bool test = Service::supprimer(id);

    if (test) {
        QMessageBox::information(this, "Succès", "Service supprimé avec succès !");
        envoyerNotification(id, "0", priorite, type, cible); // Notifier comme indisponible
        on_pushButton_Afficher_clicked();
        viderChamps();
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
void MainWindow::viderChamps()
{
    ui->lineEdit_ID->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_cible->clear();
    ui->lineEdit_statut->clear();
    ui->lineEdit_priorite->clear();
}
void MainWindow::on_pushButton_Rechercher_clicked()
{
    QString id = ui->lineEdit_recherche->text();
    ui->tableView->setModel(Service::rechercherParId(id));
}
void MainWindow::on_comboBox_tri_currentIndexChanged(int index)
{
    if (index == 0) {
        ui->tableView->setModel(Service::afficher());
    } else if (index == 1) {
        ui->tableView->setModel(Service::trierParPriorite());
    }

    ui->tableView->resizeColumnsToContents();
}
void MainWindow::on_pushButton_ExporterPDF_clicked()
{
    QAbstractItemModel* model = ui->tableView->model();
    if (!model || model->rowCount() == 0) {
        QMessageBox::information(this, "Information", "Aucune donnée à exporter.");
        return;
    }

    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    // HTML pour le tableau
    QString html = "<h2 style='text-align:center; color:#0077b6;'>📋 Liste des services</h2>";
    html += "<table border='1' cellspacing='0' cellpadding='6' style='width:100%; border-collapse:collapse; font-family:Arial;'>";

    // En-têtes
    html += "<tr style='background-color:#caf0f8; text-align:center;'>";
    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        html += "<th>" + header + "</th>";
    }
    html += "</tr>";

    // Données
    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr style='text-align:center;'>";
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            html += "<td>" + data + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";

    // Impression PDF
    QTextDocument doc;
    doc.setHtml(html);

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15), QPageLayout::Millimeter);

    doc.print(&printer);

    QMessageBox::information(this, "Succès", "✅ PDF exporté avec succès !");
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if (index == 0) {
        // 👉 Afficher tous les services
        ui->tableView->setModel(Service::afficher());
        ui->tableView->resizeColumnsToContents();
    }
    else if (index == 1) {
        // 👉 Afficher uniquement le service le plus demandé
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM STATS_DEMANDES WHERE ROWNUM = 1"); // Oracle: 1 seule ligne
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }
}




void MainWindow::on_pushButton_Historique_clicked()
{
    ui->tableView->setModel(Service::afficherHistorique());
    ui->tableView->resizeColumnsToContents();
}
void MainWindow::sauvegarderHistoriqueDansFichier(QString id, QString action, QString ancienStatut, QString nouveauStatut)
{
    QFile file("historique_services.txt");

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Date : " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << "\n";
        out << "ID_SERVICE : " << id << "\n";
        out << "Action     : " << action << "\n";
        out << "Ancien statut : " << ancienStatut << "\n";
        out << "Nouveau statut : " << nouveauStatut << "\n";
        out << "---------------------------------------------\n";
        file.close();
    }
}
void MainWindow::sauvegarderHistoriqueSuppression(QString id, QString type, QString cible, QString statut, QString priorite)
{
    QFile file("historique_services.txt");

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Date : " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << "\n";
        out << "Action : SUPPRESSION\n";
        out << "ID_SERVICE : " << id << "\n";
        out << "Type : " << type << "\n";
        out << "Cible : " << cible << "\n";
        out << "Statut : " << statut << "\n";
        out << "Priorité : " << priorite << "\n";
        out << "---------------------------------------------\n";
        file.close();
    }
}

void MainWindow::envoyerNotification(QString id, QString statut, QString priorite, QString type, QString cible)
{
    QUrl webhookUrl("https://discord.com/api/webhooks/1361019939548434703/V771jU6jMcKYBEk2LM54lTmjnT8C11of-C3PR3a2lUl01xAB6U2VQCxT-z8PtYHUeSgc");
    QNetworkRequest request(webhookUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QString statutTexte = (statut == "1") ? "✅ Disponible" : "❌ Indisponible";
    QString timestamp = QDateTime::currentDateTimeUtc().toString(Qt::ISODate); // format ISO

    QByteArray data = R"(
    {
      "content": "**🔔 Notification Service**",
      "embeds": [{
        "title": "🛠️ Service modifié",
        "color": 16753920,
        "fields": [
          { "name": "ID", "value": ")" + id.toUtf8() + R"(", "inline": true },
          { "name": "Statut", "value": ")" + statutTexte.toUtf8() + R"(", "inline": true },
          { "name": "Priorité", "value": ")" + priorite.toUtf8() + R"(", "inline": true },
          { "name": "Type", "value": ")" + type.toUtf8() + R"(", "inline": true },
          { "name": "Cible", "value": ")" + cible.toUtf8() + R"(", "inline": true }
        ],
        "footer": {
          "text": "Envoyé depuis l'application Qt"
        },
        "timestamp": ")" + timestamp.toUtf8() + R"("
      }]
    })";

    manager->post(request, data);
}


void MainWindow::on_pushButton_TestWebhook_clicked()
{
    envoyerNotification("TEST", "1", "0.9", "homme", "adulte");

}
void MainWindow::on_pushButton_deconnecter_clicked()
{
    // Déconnexion
    QMessageBox::information(this, "Déconnexion", "À bientôt!");
    close();
}

