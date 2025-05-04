#include "gboutique.h"
#include "ui_gboutique.h"
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
#include <QRegularExpression>

#include"authentification.h"


gboutique::gboutique(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gboutique),
    chart(nullptr),
    chartView(nullptr),
    series(nullptr)
{
    ui->setupUi(this);
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

    if (arduino.connect_arduino() == 0) {
        qDebug() << "Arduino connecté avec succès.";
        connect(arduino.getserial(), &QSerialPort::readyRead, this, &gboutique::readFromArduino);
    } else {
        qDebug() << "Erreur de connexion à l'Arduino.";
    }
    toutesBoutiques = Boutique::afficher();
    initialiserEncodages();

    chartView = nullptr; // Initialisation
    chart = nullptr;
    if (!ui->layoutPrincipal) {
        qDebug() << "Attention: layoutPrincipal non initialisé";
    }    series = nullptr;

    connect(ui->pushButton_exporter_boutiques, &QPushButton::clicked, this, &gboutique::on_pushButton_exporter_boutiques_clicked);
    connect(ui->pushButton_vider_formulaire, &QPushButton::clicked, this, &gboutique::viderFormulaire);
    connect(arduino.getserial(), &QSerialPort::readyRead, this, &gboutique::readFromArduino);    // Activer l'adaptation des images à la taille des labels
    ui->lbl_Image_Display->setScaledContents(true);
    ui->lbl_Logo_Display->setScaledContents(true);

/*
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
*/
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

gboutique::~gboutique()
{
    if (chartView && ui->layoutPrincipal) {
        ui->layoutPrincipal->removeWidget(chartView);
    }

    delete chartView;
    delete chart;
    delete series;
    delete ui;
}

void gboutique::chargerBoutiques()
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

void gboutique::afficherBoutique(const Boutique &b)
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

void gboutique::viderFormulaire()
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

Boutique gboutique::lireFormulaire() const
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

void gboutique::on_tableWidget_Boutique_clicked(const QModelIndex &index)
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
    afficherRecommandations();
}


void gboutique::on_pushButton_Ajouter_clicked() {
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

void gboutique::on_pushButton_Modifier_clicked(){
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

void gboutique::on_pushButton_Supprimer_clicked() {
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
void gboutique::on_pushButton_Afficher_clicked()
{
    chargerBoutiques();    // Recharge la liste des boutiques non triées
    afficherStatistiquesEtatBoutiques();
    afficherHistogrammeMontants();

}


void gboutique::on_pushButton_recherche_boutique_clicked()
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

void gboutique::on_pushButton_trier_boutiques_clicked()
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

void gboutique::on_pushButton_exporter_boutiques_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Aucun chemin de fichier sélectionné.");
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(20, 20, 20, 20)); // Marges en points (1/72 inch)

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le PDF");
        return;
    }

    // Configuration des polices
    QFont titleFont("Arial", 16, QFont::Bold);
    QFont headerFont("Arial", 10, QFont::Bold);
    QFont contentFont("Arial", 9);

    // Dimensions utiles
    const QRectF pageRect = printer.pageRect(QPrinter::Point);
    const int PAGE_WIDTH = pageRect.width();    const int LINE_HEIGHT = 20;
    const int MARGIN = 40;
    int yPos = MARGIN;

    // Entête
    painter.setFont(titleFont);
    QRect titleRect(0, yPos, PAGE_WIDTH, 30);
    painter.drawText(titleRect, Qt::AlignCenter, "Liste des Boutiques");
    yPos += 40;

    // Ligne de séparation
    painter.drawLine(MARGIN, yPos, PAGE_WIDTH - MARGIN, yPos);
    yPos += 10;

    // En-têtes de colonnes
    painter.setFont(headerFont);
    QStringList headers = {"ID", "Nom", "Type", "Localisation", "Surface", "Montant", "État"};
    QVector<int> columnWidths = {50, 120, 100, 120, 60, 80, 80};

    // Ajustement dynamique des colonnes
    int totalWidth = std::accumulate(columnWidths.begin(), columnWidths.end(), 0);
    if (totalWidth > (PAGE_WIDTH - 2*MARGIN)) {
        double scaleFactor = (PAGE_WIDTH - 2*MARGIN) / (double)totalWidth;
        for (int& width : columnWidths) width *= scaleFactor;
    }

    // Dessin des en-têtes
    int xPos = MARGIN;
    for (int i = 0; i < headers.size(); ++i) {
        QRect rect(xPos, yPos, columnWidths[i], LINE_HEIGHT);
        painter.drawText(rect, Qt::AlignLeft | Qt::TextWordWrap, headers[i]);
        xPos += columnWidths[i] + 10;
    }
    yPos += LINE_HEIGHT + 10;

    // Contenu
    QSqlQuery query;
    query.prepare("SELECT ID_BOUTIQUE, NOM, TYPE, LOCALISATION, SURFACE, MONTANT, ETAT FROM boutiques");
    if (!query.exec()) {
        painter.end();
        QMessageBox::critical(this, "Erreur", "Erreur de requête : " + query.lastError().text());
        return;
    }

    painter.setFont(contentFont);
    QFontMetrics fm(contentFont);

    while (query.next()) {
        // Vérifier l'espace sur la page
        if (yPos > (pageRect.height() - MARGIN)) {
            printer.newPage();
            yPos = MARGIN;
        }

        xPos = MARGIN;
        for (int col = 0; col < headers.size(); ++col) {
            QString text = query.value(col).toString();

            // Alignement spécifique par colonne
            Qt::AlignmentFlag align = (col == 4 || col == 5) ? Qt::AlignRight : Qt::AlignLeft;

            QRect rect(xPos, yPos, columnWidths[col], LINE_HEIGHT);
            painter.drawText(rect, align | Qt::TextWordWrap, text);

            // Ajustement position X
            xPos += columnWidths[col] + 10;
        }

        yPos += LINE_HEIGHT + 5;

        // Ligne séparatrice
        painter.drawLine(MARGIN, yPos, PAGE_WIDTH - MARGIN, yPos);
        yPos += 10;
    }

    painter.end();
    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
}
void gboutique::afficherStatistiquesEtatBoutiques()
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
void gboutique::afficherHistogrammeMontants()
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


void gboutique::readFromArduino() {
    static QString buffer;
    static QRegularExpression idRegex(R"((\d+))"); // Regex pour extraire uniquement les chiffres

    while (arduino.getserial()->bytesAvailable()) {
        QByteArray rawData = arduino.read_from_arduino();
        buffer += QString::fromUtf8(rawData);

        // Détection de fin de trame (n'importe quel caractère non numérique)
        QRegularExpressionMatch match = idRegex.match(buffer);
        if (match.hasMatch()) {
            QString receivedId = match.captured(1);
            qDebug() << "ID validé :" << receivedId;

            // Mise à jour UI et vérification
            QMetaObject::invokeMethod(this, [this, receivedId]() {
                ui->line_IDLOCATAIREboutique_2->setText(receivedId);
                checkLocataireExistence(receivedId);
            }, Qt::QueuedConnection);

            buffer.clear(); // Réinitialiser après traitement réussi
        }
        else if (buffer.length() > 10) { // Anti-buffer overflow
            buffer.clear();
        }
    }
}
void gboutique::checkLocataireExistence(const QString &idLocataire) {
    QSqlQuery query;
    bool conversionOk;
    int id = idLocataire.toInt(&conversionOk);

    // Vérification de la conversion numérique
    if (!conversionOk) {
        QMessageBox::critical(this, "Erreur", "Format ID invalide - Veuillez entrer un nombre");
        sendCommandToArduino("ERR_INVALID_FORMAT");
        return;
    }

    // Vérification existence du locataire
    query.prepare("SELECT ID_LOCATAIRE FROM locataires WHERE ID_LOCATAIRE = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qCritical() << "Erreur SQL :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur DB",
                              "Erreur de vérification ID:\n" + query.lastError().text());
        return;
    }

    if (query.next()) {
        // Mise à jour du RFID
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE locataires SET RFID = ? WHERE ID_LOCATAIRE = ?");
        updateQuery.addBindValue(id); // RFID (même valeur que l'ID)
        updateQuery.addBindValue(id); // ID_LOCATAIRE

        if (updateQuery.exec()) {
            if (updateQuery.numRowsAffected() > 0) {
                QMessageBox::information(
                    this,
                    "Mise à jour réussie",
                    QString("ID %1 - BD mis à jour avec succès").arg(id)
                    );
                sendCommandToArduino("RFID_OK");
            } else {
                QMessageBox::warning(
                    this,
                    "Aucun changement",
                    "Le BD était déjà configuré pour cet ID"
                    );
            }
        } else {
            QMessageBox::critical(
                this,
                "Erreur mise à jour",
                "Échec de la mise à jour BD:\n" + updateQuery.lastError().text()
                );
        }
    } else {
        QMessageBox::warning(
            this,
            "ID introuvable",
            QString("Aucun locataire avec l'ID: %1").arg(id)
            );
        sendCommandToArduino("NF");
    }
}
void gboutique::keyPressEvent(QKeyEvent *event) {
    qDebug() << "Touche pressée:" << event->key();
    QMainWindow::keyPressEvent(event); // Appeler la méthode de base
}
// Modifier sendCommandToArduino() pour ajouter des logs :
void gboutique::sendCommandToArduino(const QString &command) {
    if (arduino.getserial()->isOpen()) {
        QByteArray data = command.toUtf8() + '\n';
        arduino.getserial()->write(data);
        arduino.getserial()->flush();
        qDebug() << "Commande envoyée :" << data.trimmed();
    }
}
void gboutique::initialiserEncodages() {
    // Encodage des catégories
    QSet<QString> types, localisations;

    foreach(const Boutique& b, toutesBoutiques) {
        types.insert(b.getType());
        localisations.insert(b.getLocalisation());
    }

    int index = 0;
    foreach(const QString& type, types) {
        typeEncoding[type] = index++;
    }

    index = 0;
    foreach(const QString& loc, localisations) {
        localisationEncoding[loc] = index++;
    }
}

QVector<double> gboutique::normaliserCaracteristiques(const Boutique& b) {
    // Normalisation Min-Max
    static double minSurface = 0, maxSurface = 0;
    static double minMontant = 0, maxMontant = 0;

    // Calculer une fois les min/max
    static bool initialized = false;
    if(!initialized) {
        foreach(const Boutique& bout, toutesBoutiques) {
            if(bout.getSurface() < minSurface) minSurface = bout.getSurface();
            if(bout.getSurface() > maxSurface) maxSurface = bout.getSurface();
            if(bout.getMontant() < minMontant) minMontant = bout.getMontant();
            if(bout.getMontant() > maxMontant) maxMontant = bout.getMontant();
        }
        initialized = true;
    }

    // Vecteur de caractéristiques normalisées [type, localisation, surface, montant]
    QVector<double> features(4);

    // Encodage one-hot simplifié
    features[0] = typeEncoding[b.getType()] / (double)typeEncoding.size();
    features[1] = localisationEncoding[b.getLocalisation()] / (double)localisationEncoding.size();

    // Normalisation surface (0-1)
    features[2] = (b.getSurface() - minSurface) / (maxSurface - minSurface);

    // Normalisation montant (0-1)
    features[3] = (b.getMontant() - minMontant) / (maxMontant - minMontant);

    return features;
}

double gboutique::calculerDistance(const Boutique& a, const Boutique& b) {
    QVector<double> aFeatures = normaliserCaracteristiques(a);
    QVector<double> bFeatures = normaliserCaracteristiques(b);

    double distance = 0.0;
    for(int i = 0; i < aFeatures.size(); ++i) {
        distance += pow(aFeatures[i] - bFeatures[i], 2);
    }
    return sqrt(distance);
}

QList<Boutique> gboutique::trouverVoisinsKNN(const Boutique& target, int k) {
    QList<QPair<double, Boutique>> distances;

    foreach(const Boutique& b, toutesBoutiques) {
        if(b.getId() == target.getId()) continue;
        double dist = calculerDistance(target, b);
        distances.append(qMakePair(dist, b));
    }

    // Trier par distance
    std::sort(distances.begin(), distances.end(),
              [](const QPair<double, Boutique>& a, const QPair<double, Boutique>& b) {
                  return a.first < b.first;
              });

    // Récupérer les k premiers
    QList<Boutique> voisins;
    for(int i = 0; i < qMin(k, distances.size()); ++i) {
        voisins.append(distances[i].second);
    }

    return voisins;
}

void gboutique::afficherRecommandations() {
    QModelIndex index = ui->tableWidget_Boutique->currentIndex();
    if(!index.isValid()) return;

    QString id = ui->tableWidget_Boutique->item(index.row(), 0)->text();
    Boutique cible = Boutique::getById(id);

    QList<Boutique> recommandations = trouverVoisinsKNN(cible, 3);

    ui->listWidget_Recommandations->clear();
    foreach(const Boutique& b, recommandations) {
        QString info = QString("%1\nType: %2\nLocalisation: %3\nSimilarité: %4%")
                           .arg(b.getNom())
                           .arg(b.getType())
                           .arg(b.getLocalisation())
                           .arg(QString::number(calculerSimilarite(cible, b) * 100, 'f', 1));

        ui->listWidget_Recommandations->addItem(info);
    }
}
double gboutique::calculerSimilarite(const Boutique& a, const Boutique& b) {
    return 1.0 / (1.0 + calculerDistance(a, b));
}

void gboutique::on_pushButton_deconnecter_clicked()
{
    // Déconnexion
    QMessageBox::information(this, "Déconnexion", "À bientôt!");
    close();
}
