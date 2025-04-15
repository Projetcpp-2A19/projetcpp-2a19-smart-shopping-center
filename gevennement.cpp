#include "gevennement.h"
#include "ui_gevennement.h"
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QList>
#include <algorithm> // Pour std::min_element et std::max_element
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>




GEvennement::GEvennement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GEvennement),
    chart(nullptr),
    chartView(nullptr),
    series(nullptr)
{
    ui->setupUi(this);

    chartView = nullptr; // Initialisation
    chart = nullptr;
    if (!ui->layoutPrincipal) {
        qDebug() << "Attention: layoutPrincipal non initialisé";
    }    series = nullptr;

    connect(ui->pushButton_exporter_boutiques, &QPushButton::clicked, this, &GEvennement::on_pushButton_exporter_boutiques_clicked);
    connect(ui->pushButton_vider_formulaire, &QPushButton::clicked, this, &GEvennement::viderFormulaire);

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

    trayIcon = new QSystemTrayIcon(this);
    QPixmap notificationPixmap(32, 32); // Nouveau nom de variable
    notificationPixmap.fill(Qt::blue);
    trayIcon->setIcon(QIcon(notificationPixmap));
    if (QSystemTrayIcon::isSystemTrayAvailable()) {
        trayIcon->show();
    } else {
        qDebug() << "Le système de notification n'est pas disponible";
    }


    // Configuration initiale
    ui->tableWidget_Boutique->setColumnCount(10);
    QStringList headers = {"ID", "Nom", "Type", "Localisation", "Surface", "Montant", "État", "Horaire", "ID_EMPLOYE", "ID_LOCATAIRE" };
    ui->tableWidget_Boutique->setHorizontalHeaderLabels(headers);



}

GEvennement::~GEvennement()
{
    if (chartView && ui->layoutPrincipal) {
        ui->layoutPrincipal->removeWidget(chartView);
    }

    delete chartView;
    delete chart;
    delete series;
    delete ui;
}

void GEvennement::chargerBoutiques()
{
    ui->tableWidget_Boutique->setRowCount(0);
    QList<Boutique> boutiques = Boutique::afficher();

    for (const Boutique &b : boutiques) {
        int row = ui->tableWidget_Boutique->rowCount();
        ui->tableWidget_Boutique->insertRow(row);

        ui->tableWidget_Boutique->setItem(row, 0, new QTableWidgetItem(b.getId()));
        ui->tableWidget_Boutique->setItem(row, 1, new QTableWidgetItem(b.getNom()));
        ui->tableWidget_Boutique->setItem(row, 2, new QTableWidgetItem(b.getType()));
        ui->tableWidget_Boutique->setItem(row, 3, new QTableWidgetItem(b.getLocalisation()));
        ui->tableWidget_Boutique->setItem(row, 4, new QTableWidgetItem(QString::number(b.getSurface())));
        ui->tableWidget_Boutique->setItem(row, 5, new QTableWidgetItem(QString::number(b.getMontant())));
        ui->tableWidget_Boutique->setItem(row, 6, new QTableWidgetItem(b.getEtat()));
        ui->tableWidget_Boutique->setItem(row, 7, new QTableWidgetItem(b.getHoraire()));
        ui->tableWidget_Boutique->setItem(row, 8, new QTableWidgetItem(b.getIdEmploye()));
        ui->tableWidget_Boutique->setItem(row, 9, new QTableWidgetItem(b.getIdLocataire()));
    }
}

void GEvennement::afficherBoutique(const Boutique &b)
{
    ui->line_NOMboutique->setText(b.getNom());
    ui->line_TYPEboutique->setText(b.getType());
    ui->line_LOCALISATIONboutique->setText(b.getLocalisation());
    ui->line_SURFACEboutique->setText(QString::number(b.getSurface()));
    ui->line_MONTANTboutique->setText(QString::number(b.getMontant()));
    ui->comboBox_ETATboutique->setCurrentText(b.getEtat());
    ui->timeEdit_HORAIRE->setTime(QTime::fromString(b.getHoraire()));
    ui->line_IDEMPboutique->setText(b.getIdEmploye());
    ui->line_IDLOCATAIREboutique->setText(b.getIdLocataire());
}

void GEvennement::viderFormulaire()
{
    ui->line_NOMboutique->clear();
    ui->line_TYPEboutique->clear();
    ui->line_LOCALISATIONboutique->clear();
    ui->line_SURFACEboutique->clear();
    ui->line_MONTANTboutique->clear();
    ui->comboBox_ETATboutique->setCurrentIndex(0);
    ui->timeEdit_HORAIRE->setTime(QTime(8,0));
    ui->line_IDEMPboutique->clear();
    ui->line_IDLOCATAIREboutique->clear();
}

Boutique GEvennement::lireFormulaire() const
{
    Boutique b;
    b.setNom(ui->line_NOMboutique->text().trimmed());
    b.setType(ui->line_TYPEboutique->text().trimmed());
    b.setLocalisation(ui->line_LOCALISATIONboutique->text().trimmed());
    b.setSurface(ui->line_SURFACEboutique->text().toDouble());
    b.setMontant(ui->line_MONTANTboutique->text().toDouble());
    b.setEtat(ui->comboBox_ETATboutique->currentText());
    b.setHoraire(ui->timeEdit_HORAIRE->time().toString("HH:mm"));
    b.setIdEmploye(ui->line_IDEMPboutique->text().trimmed());
    b.setIdLocataire(ui->line_IDLOCATAIREboutique->text().trimmed());

    return b;
}

void GEvennement::on_tableWidget_Boutique_clicked(const QModelIndex &index)
{
    // Vérifiez si l'index est valide
    if (!index.isValid()) {
        return; // Sortir si l'index n'est pas valide
    }

    // Récupérer l'ID de la boutique sélectionnée
    QString id = ui->tableWidget_Boutique->item(index.row(), 0)->text(); // Supposons que l'ID est dans la première colonne
    Boutique b = Boutique::getById(id); // Récupérer la boutique par ID

    // Afficher les détails de la boutique dans le formulaire
    afficherBoutique(b);
}


void GEvennement::on_pushButton_Ajouter_clicked() {
    Boutique b = lireFormulaire();

    QString errorMessage;

    if (b.getNom().isEmpty() || b.getType().isEmpty() || b.getLocalisation().isEmpty() ||
        b.getIdEmploye().isEmpty() || b.getIdLocataire().isEmpty()) {
        errorMessage += "Veuillez remplir tous les champs obligatoires.\n";
    }

    if (b.getSurface() <= 0) {
        errorMessage += "La surface doit être un chiffre positif.\n";
    }

    if (b.getMontant() <= 0) {
        errorMessage += "Le montant doit être un chiffre positif.\n";
    }

    if (!QRegularExpression("^[0-9]+$").match(b.getIdEmploye()).hasMatch()) {
        errorMessage += "L'ID employé doit contenir uniquement des chiffres.\n";
    }

    if (!QRegularExpression("^[0-9]+$").match(b.getIdLocataire()).hasMatch()) {
        errorMessage += "L'ID locataire doit contenir uniquement des chiffres.\n";
    }

    if (!errorMessage.isEmpty()) {
        QMessageBox::warning(this, "Erreur", errorMessage);
        return;
    }

    if (!QRegularExpression("^[a-zA-Z0-9]{3,}$").match(b.getNom()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom de la boutique doit contenir au minimum 3 lettres ou chiffres.");
        return;
    }

    if (!QRegularExpression("^[a-zA-Z]{3,}$").match(b.getType()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le type de la boutique doit contenir au minimum 3 lettres.");
        return;
    }

    if (Boutique::ajouter(b)) {
        QMessageBox::information(this, "Succès", "Boutique ajoutée avec succès");
        viderFormulaire();
        chargerBoutiques();

        // Récupérer tous les montants depuis la base
        QList<double> montants;
        QSqlQuery query;
        query.prepare("SELECT MONTANT FROM boutiques");
        if (!query.exec()) {
            qDebug() << "Erreur SQL:" << query.lastError().text();
            return;
        }


        while (query.next()) {
            montants.append(query.value(0).toDouble());
        }

        qDebug() << "Nombre de montants:" << montants.size();

        if (!montants.isEmpty()) {
            double montantMin = *std::min_element(montants.begin(), montants.end());
            double montantMax = *std::max_element(montants.begin(), montants.end());

            if (QSystemTrayIcon::isSystemTrayAvailable()) {
                trayIcon->showMessage(
                    "Statistiques des montants",
                    QString("Nouveau montant ajouté: %1 DT\nMin: %2 DT - Max: %3 DT")
                        .arg(b.getMontant())
                        .arg(montantMin)
                        .arg(montantMax),
                    QSystemTrayIcon::Information,
                    5000
                    );
            } else {
                QMessageBox::information(
                    this,
                    "Statistiques des montants",
                    QString("Nouveau montant ajouté: %1 DT\nMin: %2 DT - Max: %3 DT")
                        .arg(b.getMontant())
                        .arg(montantMin)
                        .arg(montantMax)
                    );
            }
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de la boutique");
    }
}
/*void GEvennement::on_pushButton_Ajouter_clicked()
{
    Boutique b = lireFormulaire();
    QString errorMessage;

    if (b.getNom().isEmpty() || b.getType().isEmpty() || b.getLocalisation().isEmpty() ||
        b.getIdEmploye().isEmpty() || b.getIdLocataire().isEmpty()) {
        errorMessage += "Veuillez remplir tous les champs obligatoires.\n";
    }

    if (b.getSurface() <= 0) {
        errorMessage += "La surface doit être un chiffre positif.\n";
    }

    if (b.getMontant() <= 0) {
        errorMessage += "Le montant doit être un chiffre positif.\n";
    }

    if (!QRegularExpression("^[0-9]+$").match(b.getIdEmploye()).hasMatch()) {
        errorMessage += "L'ID employé doit contenir uniquement des chiffres.\n";
    }

    if (!QRegularExpression("^[0-9]+$").match(b.getIdLocataire()).hasMatch()) {
        errorMessage += "L'ID locataire doit contenir uniquement des chiffres.\n";
    }

    if (!errorMessage.isEmpty()) {
        QMessageBox::warning(this, "Erreur", errorMessage);
        return;
    }

    if (!QRegularExpression("^[a-zA-Z0-9]{3,}$").match(b.getNom()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom de la boutique doit contenir au minimum 3 lettres ou chiffres.");
        return;
    }

    if (!QRegularExpression("^[a-zA-Z]{3,}$").match(b.getType()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le type de la boutique doit contenir au minimum 3 lettres.");
        return;
    }

    if (Boutique::ajouter(b)) {
        QMessageBox::information(this, "Succès", "Boutique ajoutée avec succès");
        viderFormulaire();
        chargerBoutiques();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de la boutique");
    }
}
*/
void GEvennement::on_pushButton_Modifier_clicked(){
    QModelIndex index = ui->tableWidget_Boutique->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une boutique à modifier.");
        return;
    }

    Boutique b = lireFormulaire();
    b.setId(ui->tableWidget_Boutique->item(index.row(), 0)->text());

    if (Boutique::modifier(b)) {
        QMessageBox::information(this, "Succès", "Boutique modifiée avec succès");
        viderFormulaire();
        chargerBoutiques();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de la boutique");
    }
}

void GEvennement::on_pushButton_Supprimer_clicked() {
    QModelIndex index = ui->tableWidget_Boutique->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une boutique");
        return;
    }

    QString id = ui->tableWidget_Boutique->item(index.row(), 0)->text();
    if (QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette boutique ?") == QMessageBox::Yes) {
        if (Boutique::supprimer(id)) {
            QMessageBox::information(this, "Succès", "Boutique supprimée avec succès");
            viderFormulaire();
            chargerBoutiques();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression");
        }
    }
}
void GEvennement::on_pushButton_Afficher_clicked()
{
    chargerBoutiques();    // Recharge la liste des boutiques non triées
    afficherStatistiquesEtatBoutiques();
    afficherHistogrammeMontants();

}


void GEvennement::on_pushButton_recherche_boutique_clicked()
{
    QString rechercheId = ui->lineEdit_recherche_id->text().trimmed();
    if (rechercheId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID à rechercher.");
        return;
    }

    QList<Boutique> boutiques = Boutique::afficher();
    ui->tableWidget_Boutique->clearContents();
    ui->tableWidget_Boutique->setRowCount(0);

    for (const Boutique &b : boutiques) {
        if (b.getId() == rechercheId) {
            int row = ui->tableWidget_Boutique->rowCount();
            ui->tableWidget_Boutique->insertRow(row);
            ui->tableWidget_Boutique->setItem(row, 0, new QTableWidgetItem(b.getId()));
            ui->tableWidget_Boutique->setItem(row, 1, new QTableWidgetItem(b.getNom()));
            ui->tableWidget_Boutique->setItem(row, 2, new QTableWidgetItem(b.getType()));
            ui->tableWidget_Boutique->setItem(row, 3, new QTableWidgetItem(b.getLocalisation()));
            ui->tableWidget_Boutique->setItem(row, 4, new QTableWidgetItem(QString::number(b.getSurface())));
            ui->tableWidget_Boutique->setItem(row, 5, new QTableWidgetItem(QString::number(b.getMontant())));
            ui->tableWidget_Boutique->setItem(row, 6, new QTableWidgetItem(b.getEtat()));
            ui->tableWidget_Boutique->setItem(row, 7, new QTableWidgetItem(b.getHoraire()));
            ui->tableWidget_Boutique->setItem(row, 8, new QTableWidgetItem(b.getIdEmploye()));
            ui->tableWidget_Boutique->setItem(row, 9, new QTableWidgetItem(b.getIdLocataire()));
            return; // Sortir après avoir trouvé la boutique
        }
    }
    QMessageBox::information(this, "Résultat", "Aucune boutique trouvée avec cet ID.");
}

void GEvennement::on_pushButton_trier_boutiques_clicked()
{
    QList<Boutique> boutiques = Boutique::afficher();
    std::sort(boutiques.begin(), boutiques.end(), [](const Boutique &a, const Boutique &b) {
        return a.getNom() < b.getNom();
    });

    ui->tableWidget_Boutique->clearContents();
    ui->tableWidget_Boutique->setRowCount(0);

    for (const Boutique &b : boutiques) {
        int row = ui->tableWidget_Boutique->rowCount();
        ui->tableWidget_Boutique->insertRow(row);
        ui->tableWidget_Boutique->setItem(row, 0, new QTableWidgetItem(b.getId()));
        ui->tableWidget_Boutique->setItem(row, 1, new QTableWidgetItem(b.getNom()));
        ui->tableWidget_Boutique->setItem(row, 2, new QTableWidgetItem(b.getType()));
        ui->tableWidget_Boutique->setItem(row, 3, new QTableWidgetItem(b.getLocalisation()));
        ui->tableWidget_Boutique->setItem(row, 4, new QTableWidgetItem(QString::number(b.getSurface())));
        ui->tableWidget_Boutique->setItem(row, 5, new QTableWidgetItem(QString::number(b.getMontant())));
        ui->tableWidget_Boutique->setItem(row, 6, new QTableWidgetItem(b.getEtat()));
        ui->tableWidget_Boutique->setItem(row, 7, new QTableWidgetItem(b.getHoraire()));
        ui->tableWidget_Boutique->setItem(row, 8, new QTableWidgetItem(b.getIdEmploye()));
        ui->tableWidget_Boutique->setItem(row, 9, new QTableWidgetItem(b.getIdLocataire()));
    }

    QMessageBox::information(this, "Succès", "Les boutiques ont été triées par nom.");
}

void GEvennement::on_pushButton_exporter_boutiques_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Aucun chemin de fichier sélectionné.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT ID_BOUTIQUE, NOM, TYPE, LOCALISATION, SURFACE, MONTANT, ETAT, HORAIRE_OUVERTURE, ID_LOCATAIRE, ID_EMP FROM boutiques");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données des boutiques : " + query.lastError().text());
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageMargins(QMarginsF(20, 20, 20, 20));

    QPainter painter(&printer);
    QFont titleFont("Arial", 16, QFont::Bold);
    QFont headerFont("Arial", 12, QFont::Bold);
    QFont contentFont("Arial", 10);

    painter.setFont(titleFont);
    painter.drawText(200, 50, "Liste des Boutiques");

    painter.setFont(headerFont);
    int y = 100;
    int x = 50;
    int columnWidth = 100;

    painter.drawText(x, y, "ID");
    painter.drawText(x + columnWidth, y, "Nom");
    painter.drawText(x + 2 * columnWidth, y, "Type");
    painter.drawText(x + 3 * columnWidth, y, "Localisation");
    painter.drawText(x + 4 * columnWidth, y, "Surface");
    painter.drawText(x + 5 * columnWidth, y, "Montant");
    painter.drawText(x + 6 * columnWidth, y, "État");
    painter.drawText(x + 7 * columnWidth, y, "Horaire d'Ouverture");
        painter.drawText(x + 8 * columnWidth, y, "ID Locataire");
    painter.drawText(x + 9 * columnWidth, y, "ID EMP");

    painter.drawLine(50, y + 5, 950, y + 5);

    painter.setFont(contentFont);
    y += 20;
    while (query.next()) {
        painter.drawText(x, y, query.value("ID_BOUTIQUE").toString());
        painter.drawText(x + columnWidth, y, query.value("NOM").toString());
        painter.drawText(x + 2 * columnWidth, y, query.value("TYPE").toString());
        painter.drawText(x + 3 * columnWidth, y, query.value("LOCALISATION").toString());
        painter.drawText(x + 4 * columnWidth, y, query.value("SURFACE").toString());
        painter.drawText(x + 5 * columnWidth, y, query.value("MONTANT").toString());
        painter.drawText(x + 6 * columnWidth, y, query.value("ETAT").toString());
        painter.drawText(x + 7 * columnWidth, y, query.value("HORAIRE_OUVERTURE").toString());
        painter.drawText(x + 8 * columnWidth, y, query.value("ID_LOCATAIRE").toString());
        painter.drawText(x + 9 * columnWidth, y, query.value("ID_EMP").toString());
        y += 20;
    }

    painter.end();
    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
}
void GEvennement::afficherStatistiquesEtatBoutiques()
{
    // Nettoyer les anciens éléments s'ils existent
    if (series) {
        delete series;
        series = nullptr;
    }
    if (chart) {
        delete chart;
        chart = nullptr;
    }
    if (chartView) {
        // Supprimer le widget du layout avant de le supprimer
        ui->layoutPrincipal->removeWidget(chartView);
        delete chartView;
        chartView = nullptr;
    }

    // Créer une nouvelle série
    series = new QPieSeries();

    // Récupérer les données depuis la base
    QSqlQuery query;
    query.prepare("SELECT etat, COUNT(*) FROM boutiques GROUP BY etat");
    if (query.exec()) {
        while (query.next()) {
            QString etat = query.value(0).toString();
            int count = query.value(1).toInt();
            QPieSlice *slice = series->append(etat, count);
            slice->setLabelVisible();
            slice->setLabel(QString("%1 (%2)").arg(etat).arg(count));
        }
    } else {
        qDebug() << "Erreur requête SQL:" << query.lastError().text();
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les statistiques");
        return;
    }

    // Configurer le graphique
    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des boutiques par état");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);

    // Créer la vue du graphique
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400, 300);

    // Ajouter au layout principal
    if (ui->layoutPrincipal) {
        // Ajouter un espace avant le graphique si nécessaire
        ui->layoutPrincipal->addSpacing(20);

        // Ajouter le graphique
        ui->layoutPrincipal->addWidget(chartView);

        // Ajouter un stretch pour pousser le graphique vers le haut
        ui->layoutPrincipal->addStretch();
    } else {
        qDebug() << "Erreur: layoutPrincipal non trouvé";
        QMessageBox::warning(this, "Erreur", "Impossible d'afficher le graphique");
    }
}
void GEvennement::afficherHistogrammeMontants()
{
    // Get the list of amounts from the database
    QList<double> montants;
    QSqlQuery query;
    query.prepare("SELECT MONTANT FROM boutiques");
    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        montants.append(query.value(0).toDouble());
    }

    // Create a bar set and add all the amounts to it
    QBarSet *set = new QBarSet("Montants des Boutiques");

    for (double montant : montants) {
        *set << montant;
    }

    // Create a bar series and add the set to it
    QBarSeries *series = new QBarSeries();
    series->append(set);

    // Create a chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Histogramme des Montants des Boutiques");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Create a category axis for the X-axis and set it
    QStringList categories;
    for (int i = 1; i <= montants.size(); ++i) {
        categories << QString::number(i); // Set X-axis categories as indices (e.g., 1, 2, 3, etc.)
    }
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create a value axis for the Y-axis and set it
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, *std::max_element(montants.begin(), montants.end()));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create a chart view to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->layoutPrincipal->addWidget(chartView);
}
