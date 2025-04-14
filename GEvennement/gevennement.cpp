#include "gevennement.h"
#include "ui_gevennement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlError>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QQuickWidget>
#include <QQuickItem>
#include <QHBoxLayout>
#include <QDebug>
#include <QGeoPositionInfoSource>
#include <QGeoServiceProvider>
#include <QRegularExpression>
#include "calendardialog.h"

GEvennement::GEvennement(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GEvennement), mapWidget(nullptr)
{
    ui->setupUi(this);
    setupUi();

    // Enregistrer les types QML nécessaires
    qRegisterMetaType<QGeoCoordinate>();

    // Initialiser le modèle avec QStandardItemModel au lieu de QSqlQueryModel
    model = new QStandardItemModel(this);

    // Ajouter un bouton pour le calendrier dans la barre d'outils
    QPushButton *calendarButton = new QPushButton("Calendrier", this);
    calendarButton->setObjectName("pushButton_Calendar");
    calendarButton->setStyleSheet(R"(
        QPushButton {
            font: 14pt "Segoe UI";
            color: rgb(255, 255, 255);
            border: 2px solid white;
            border-radius: 6px;
            background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                            stop: 0 #00a2c6, stop: 1 #dadbde);
            min-width: 80px;
        }
        QPushButton:pressed {
            background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                            stop: 0 #dadbde, stop: 1 #f6f7fa);
        }
    )");

    // Positionner le bouton du calendrier à côté des autres boutons
    calendarButton->setGeometry(820, 560, 171, 31);
    calendarButton->setParent(ui->centralwidget);
    calendarButton->show();

    // Connecter le signal clicked du bouton calendrier
    connect(calendarButton, &QPushButton::clicked, this, &GEvennement::on_pushButton_Calendar_clicked);

    // Afficher les événements au démarrage
    populateLocatairesComboBox();
    on_pushButton_Retreive_clicked();
}

GEvennement::~GEvennement()
{
    delete ui;
}

void GEvennement::on_pushButton_PDF_clicked()
{
    generatePDF();
}

void GEvennement::generatePDF()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Enregistrer le PDF", QString(), "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty())
        return;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));

    QTextDocument doc;
    QString html = "<h1 align='center'>Liste des Événements</h1>";
    html += "<table width='100%' border='1' cellspacing='0'>";
    html += "<tr bgcolor='#f0f0f0'>";
    html += "<th>ID</th><th>Type</th><th>Nom</th><th>Date Début</th><th>Date Fin</th><th>Lieu</th><th>Capacité</th><th>Prix</th>";
    html += "</tr>";

    QSqlQuery query;
    query.prepare("SELECT * FROM EVENEMENTS ORDER BY DATE_DEBUT");

    if (query.exec())
    {
        while (query.next())
        {
            html += "<tr>";
            html += "<td>" + query.value("IDENTIFIANT").toString() + "</td>";
            html += "<td>" + query.value("TYPE").toString() + "</td>";
            html += "<td>" + query.value("NOM").toString() + "</td>";
            html += "<td>" + formatDate(query.value("DATE_DEBUT").toDateTime()) + "</td>";
            html += "<td>" + formatDate(query.value("DATE_FIN").toDateTime()) + "</td>";
            html += "<td>" + query.value("LIEU").toString() + "</td>";
            html += "<td>" + query.value("CAPACITE").toString() + "</td>";
            html += "<td>" + query.value("PRIX").toString() + "</td>";
            html += "</tr>";
        }
    }

    html += "</table>";
    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès !");
}

QString GEvennement::formatDate(const QDateTime &date)
{
    return date.toString("dd/MM/yyyy hh:mm");
}

void GEvennement::setupUi()
{
    setWindowTitle("Gestion des Événements");

    // Appliquer les styles avec texte noir
    setStyleSheet(R"(
        QLineEdit, QDateEdit, QComboBox {
            color: black;
            font: 11pt "Segoe UI";
            border: 2px solid gray;
            border-radius: 10px;
            padding: 0 8px;
            background: white;
            selection-background-color: darkgray;
        }
        QDateEdit::drop-down, QComboBox::drop-down {
            subcontrol-origin: padding;
            subcontrol-position: top right;
            width: 20px;
            border-left-width: 1px;
            border-left-color: darkgray;
            border-left-style: solid;
            border-top-right-radius: 3px;
            border-bottom-right-radius: 3px;
        }
        QDateEdit::down-arrow, QComboBox::down-arrow {
            image: url(:/icons/down_arrow.png);
        }
    )");
}

// Implémentation des slots manquants
void GEvennement::on_pushButton_Employes_clicked()
{
    // Fonction vide pour le moment
    QMessageBox::information(this, "Navigation", "Navigation vers la section Employés");
}

void GEvennement::on_pushButton_Boutiques_clicked()
{
    // Fonction vide pour le moment
    QMessageBox::information(this, "Navigation", "Navigation vers la section Boutiques");
}

void GEvennement::on_pushButton_Ajouter_clicked()
{
    // Récupérer les données du formulaire
    QString nom = ui->line_NOMevent->text();
    QString capacite = ui->line_CAPACITEevent->text();
    QString type = ui->line_TYPEevent->text();
    QString prix = ui->line_PRIXevent->text();
    QDate dateDebut = ui->dateEditDebut->date();
    QDate dateFin = ui->dateEditFin->date();
    QString lieu = ui->line_LIEU->text();
    QString idLocataire = ui->comboBox_LOC->currentData().toString();
    QString identifiant = ui->lineEdit_IDENTIFIANT->text();

    // Validation des données
    if (nom.isEmpty() || capacite.isEmpty() || type.isEmpty() || prix.isEmpty() ||
        identifiant.isEmpty() || lieu.isEmpty())
    {
        QMessageBox::warning(this, "Attention", "Veuillez remplir tous les champs obligatoires.");
        return; // idLocataire.isEmpty() ||
    }

    // Valider les dates
    if (dateDebut > dateFin)
    {
        QMessageBox::warning(this, "Erreur de date", "La date de début doit être antérieure à la date de fin.");
        return;
    }

    // Vérifier si l'identifiant existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EVENEMENTS WHERE IDENTIFIANT = :id");
    checkQuery.bindValue(":id", identifiant);

    if (checkQuery.exec() && checkQuery.next())
    {
        if (checkQuery.value(0).toInt() > 0)
        {
            QMessageBox::warning(this, "Erreur", "Un événement avec cet identifiant existe déjà. Veuillez en choisir un autre.");
            return;
        }
    }

    // Ajouter l'événement
    if (E.ajout(nom, capacite, type, prix, dateDebut, dateFin, lieu, idLocataire, identifiant))
    {
        QMessageBox::information(this, "Succès", "Événement ajouté avec succès!");

        // Effacer les champs du formulaire
        ui->line_NOMevent->clear();
        ui->line_CAPACITEevent->clear();
        ui->line_TYPEevent->clear();
        ui->line_PRIXevent->clear();
        ui->line_LIEU->clear();
        ui->line_LOCATIONevent->clear();
        ui->comboBox_LOC->setCurrentIndex(0);
        ui->lineEdit_IDENTIFIANT->clear();

        // Actualiser la liste des événements
        on_pushButton_Retreive_clicked();
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'événement. Vérifiez vos données.");
    }
}

void GEvennement::on_pushButton_Supprimer_clicked()
{
    // Vérifier si une ligne est sélectionnée
    if (!ui->tableView->selectionModel()->hasSelection())
    {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un événement à supprimer.");
        return;
    }

    // Récupérer le nom de l'événement sélectionné
    int row = ui->tableView->selectionModel()->currentIndex().row();
    QString nom = model->index(row, 0).data().toString();

    // Confirmation de suppression
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
                                                              QString("Êtes-vous sûr de vouloir supprimer l'événement '%1' ?").arg(nom),
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        // Supprimer l'événement
        if (E.supprimer(nom, ui->tableView))
        {
            // La fonction supprimer met déjà à jour l'affichage et affiche un message de succès
            // Effacer les champs du formulaire
            ui->line_NOMevent->clear();
            ui->line_CAPACITEevent->clear();
            ui->line_TYPEevent->clear();
            ui->line_PRIXevent->clear();
            ui->line_LIEU->clear();
            ui->comboBox_LOC->setCurrentIndex(0);
            ui->lineEdit_IDENTIFIANT->clear();
        }
    }
}

void GEvennement::on_pushButton_Modifier_clicked()
{
    // Vérifier si une ligne est sélectionnée
    if (!ui->tableView->selectionModel()->hasSelection())
    {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un événement à modifier.");
        return;
    }

    // Récupérer le nom de l'événement sélectionné
    int row = ui->tableView->selectionModel()->currentIndex().row();
    QString nomActuel = model->index(row, 0).data().toString();

    // Récupérer les données du formulaire
    QString nouveauNom = ui->line_NOMevent->text();
    QString capacite = ui->line_CAPACITEevent->text();
    QString type = ui->line_TYPEevent->text();
    QString prix = ui->line_PRIXevent->text();
    QDate dateDebut = ui->dateEditDebut->date();
    QDate dateFin = ui->dateEditFin->date();
    QString lieu = ui->line_LIEU->text();
    QString idLocataire = ui->comboBox_LOC->currentData().toString();

    // Validation des données
    if (nouveauNom.isEmpty() || capacite.isEmpty() || type.isEmpty() || prix.isEmpty() ||
        idLocataire.isEmpty() || lieu.isEmpty())
    {
        QMessageBox::warning(this, "Attention", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // Valider les dates
    if (dateDebut > dateFin)
    {
        QMessageBox::warning(this, "Erreur de date", "La date de début doit être antérieure à la date de fin.");
        return;
    }

    // Valider le format des données numériques
    bool ok;
    capacite.toInt(&ok);
    if (!ok)
    {
        QMessageBox::warning(this, "Erreur de format", "La capacité doit être un nombre entier.");
        return;
    }

    prix.toDouble(&ok);
    if (!ok)
    {
        QMessageBox::warning(this, "Erreur de format", "Le prix doit être un nombre valide.");
        return;
    }

    // Confirmation de modification
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
                                                              "Êtes-vous sûr de vouloir modifier cet événement ?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        // Modifier l'événement
        if (E.modifier(nomActuel, nouveauNom, capacite, type, prix, dateDebut, dateFin, lieu, idLocataire))
        {
            QMessageBox::information(this, "Succès", "Événement modifié avec succès!");

            // Actualiser la liste des événements
            on_pushButton_Retreive_clicked();

            // Effacer les champs du formulaire
            ui->line_NOMevent->clear();
            ui->line_CAPACITEevent->clear();
            ui->line_TYPEevent->clear();
            ui->line_PRIXevent->clear();
            ui->line_LIEU->clear();
            ui->comboBox_LOC->setCurrentIndex(0);
            ui->lineEdit_IDENTIFIANT->clear();
        }
    }
}

void GEvennement::on_pushButton_Modifier_2_clicked()
{
    // Afficher les statistiques
    showPieChartDialog();
}

void GEvennement::on_pushButton_Modifier_3_clicked()
{
    // Générer le PDF
    generatePDF();
}

void GEvennement::on_pushButton_Rechercher_clicked()
{
    // Récupérer le texte de recherche
    QString searchText = ui->lineEdit_Recherche->text();

    if (searchText.isEmpty())
    {
        // Si le champ de recherche est vide, afficher tous les événements
        on_pushButton_Retreive_clicked();
        return;
    }

    // Recherche par identifiant, nom ou type
    QSqlQuery query;
    query.prepare("SELECT * FROM eyk.EVENEMENTS "
                  "WHERE IDENTIFIANT LIKE :search OR NOM LIKE :search OR TYPE LIKE :search "
                  "ORDER BY NOM");
    query.bindValue(":search", "%" + searchText + "%");

    if (query.exec())
    {
        // Créer un nouveau modèle
        QStandardItemModel *newModel = new QStandardItemModel(ui->tableView);

        // Configuration des en-têtes
        QStringList headers;
        headers << "Nom" << "Type" << "Date Début" << "Date Fin" << "Lieu" << "Capacité" << "Prix" << "Locataire" << "Identifiant";
        newModel->setHorizontalHeaderLabels(headers);

        // Variables pour stocker l'ID du locataire
        QMap<QString, QString> locataireNames;

        // Récupérer les noms des locataires
        QSqlQuery locQuery("SELECT ID_LOCATAIRE, NOM FROM eyk.LOCATAIRES");
        while (locQuery.next())
        {
            locataireNames[locQuery.value("ID_LOCATAIRE").toString()] = locQuery.value("NOM").toString();
        }

        // Remplir le modèle avec les résultats de la recherche
        int row = 0;
        while (query.next())
        {
            QList<QStandardItem *> rowItems;

            // Création des items dans l'ordre demandé
            rowItems << new QStandardItem(query.value("NOM").toString())
                     << new QStandardItem(query.value("TYPE").toString())
                     << new QStandardItem(query.value("DATE_DEBUT").toDate().toString("dd/MM/yyyy"))
                     << new QStandardItem(query.value("DATE_FIN").toDate().toString("dd/MM/yyyy"))
                     << new QStandardItem(query.value("LIEU").toString())
                     << new QStandardItem(query.value("CAPACITE").toString())
                     << new QStandardItem(query.value("PRIX").toString());

            // Ajouter le nom du locataire
            QString idLocataire = query.value("ID_LOCATAIRE").toString();
            QString nomLocataire = locataireNames.value(idLocataire, "Inconnu");
            rowItems << new QStandardItem(nomLocataire);

            // Ajouter l'identifiant
            rowItems << new QStandardItem(query.value("IDENTIFIANT").toString());

            // Configuration des items
            for (int col = 0; col < rowItems.size(); ++col)
            {
                rowItems[col]->setTextAlignment(Qt::AlignCenter);
                rowItems[col]->setEditable(false);
                newModel->setItem(row, col, rowItems[col]);
            }
            row++;
        }

        // Supprimer l'ancien modèle et définir le nouveau
        if (model)
        {
            delete model;
        }
        model = newModel;
        ui->tableView->setModel(model);

        // Définir une largeur spécifique pour chaque colonne
        QList<int> columnWidths = {150, 100, 100, 100, 150, 80, 80, 150, 100};
        for (int col = 0; col < columnWidths.size() && col < model->columnCount(); ++col)
        {
            ui->tableView->setColumnWidth(col, columnWidths[col]);
        }

        // Configuration supplémentaire du tableau
        ui->tableView->setSortingEnabled(true);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableView->setAlternatingRowColors(true);

        qDebug() << "Recherche terminée avec" << row << "résultats pour" << searchText;
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche: " + query.lastError().text());
    }
}

void GEvennement::on_pushButton_TriType_clicked()
{
    // Trier par type d'événement
    QSqlQuery query;
    query.prepare("SELECT * FROM eyk.EVENEMENTS ORDER BY TYPE");

    if (query.exec())
    {
        // Créer un nouveau modèle
        QStandardItemModel *newModel = new QStandardItemModel(ui->tableView);

        // Configuration des en-têtes
        QStringList headers;
        headers << "Nom" << "Type" << "Date Début" << "Date Fin" << "Lieu" << "Capacité" << "Prix" << "Locataire" << "Identifiant";
        newModel->setHorizontalHeaderLabels(headers);

        // Variables pour stocker l'ID du locataire
        QMap<QString, QString> locataireNames;

        // Récupérer les noms des locataires
        QSqlQuery locQuery("SELECT ID_LOCATAIRE, NOM FROM eyk.LOCATAIRES");
        while (locQuery.next())
        {
            locataireNames[locQuery.value("ID_LOCATAIRE").toString()] = locQuery.value("NOM").toString();
        }

        // Remplir le modèle avec les résultats triés
        int row = 0;
        while (query.next())
        {
            QList<QStandardItem *> rowItems;

            // Création des items dans l'ordre demandé
            rowItems << new QStandardItem(query.value("NOM").toString())
                     << new QStandardItem(query.value("TYPE").toString())
                     << new QStandardItem(query.value("DATE_DEBUT").toDate().toString("dd/MM/yyyy"))
                     << new QStandardItem(query.value("DATE_FIN").toDate().toString("dd/MM/yyyy"))
                     << new QStandardItem(query.value("LIEU").toString())
                     << new QStandardItem(query.value("CAPACITE").toString())
                     << new QStandardItem(query.value("PRIX").toString());

            // Ajouter le nom du locataire
            QString idLocataire = query.value("ID_LOCATAIRE").toString();
            QString nomLocataire = locataireNames.value(idLocataire, "Inconnu");
            rowItems << new QStandardItem(nomLocataire);

            // Ajouter l'identifiant
            rowItems << new QStandardItem(query.value("IDENTIFIANT").toString());

            // Configuration des items
            for (int col = 0; col < rowItems.size(); ++col)
            {
                rowItems[col]->setTextAlignment(Qt::AlignCenter);
                rowItems[col]->setEditable(false);
                newModel->setItem(row, col, rowItems[col]);
            }
            row++;
        }

        // Supprimer l'ancien modèle et définir le nouveau
        if (model)
        {
            delete model;
        }
        model = newModel;
        ui->tableView->setModel(model);

        // Définir une largeur spécifique pour chaque colonne
        QList<int> columnWidths = {150, 100, 100, 100, 150, 80, 80, 150, 100};
        for (int col = 0; col < columnWidths.size() && col < model->columnCount(); ++col)
        {
            ui->tableView->setColumnWidth(col, columnWidths[col]);
        }

        // Configuration supplémentaire du tableau
     /*   ui->tableView->setSortingEnabled(true);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableView->setAlternatingRowColors(true);*/

        qDebug() << "Tri par TYPE terminé avec" << row << "événements.";
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec du tri: " + query.lastError().text());
    }
}

void GEvennement::on_pushButton_TriDate_clicked()
{
    // Trier par date d'événement
    QSqlQuery query;
    query.prepare("SELECT * FROM eyk.EVENEMENTS ORDER BY DATE_DEBUT");

    if (query.exec())
    {
        // Créer un nouveau modèle
        QStandardItemModel *newModel = new QStandardItemModel(ui->tableView);

        // Configuration des en-têtes
        QStringList headers;
        headers << "Nom" << "Type" << "Date Début" << "Date Fin" << "Lieu" << "Capacité" << "Prix" << "Locataire" << "Identifiant";
        newModel->setHorizontalHeaderLabels(headers);

        // Variables pour stocker l'ID du locataire
        QMap<QString, QString> locataireNames;

        // Récupérer les noms des locataires
        QSqlQuery locQuery("SELECT ID_LOCATAIRE, NOM FROM eyk.LOCATAIRES");
        while (locQuery.next())
        {
            locataireNames[locQuery.value("ID_LOCATAIRE").toString()] = locQuery.value("NOM").toString();
        }

        // Remplir le modèle avec les résultats triés
        int row = 0;
        while (query.next())
        {
            QList<QStandardItem *> rowItems;

            // Création des items dans l'ordre demandé
            rowItems << new QStandardItem(query.value("NOM").toString())
                     << new QStandardItem(query.value("TYPE").toString())
                     << new QStandardItem(query.value("DATE_DEBUT").toDate().toString("dd/MM/yyyy"))
                     << new QStandardItem(query.value("DATE_FIN").toDate().toString("dd/MM/yyyy"))
                     << new QStandardItem(query.value("LIEU").toString())
                     << new QStandardItem(query.value("CAPACITE").toString())
                     << new QStandardItem(query.value("PRIX").toString());

            // Ajouter le nom du locataire
            QString idLocataire = query.value("ID_LOCATAIRE").toString();
            QString nomLocataire = locataireNames.value(idLocataire, "Inconnu");
            rowItems << new QStandardItem(nomLocataire);

            // Ajouter l'identifiant
            rowItems << new QStandardItem(query.value("IDENTIFIANT").toString());

            // Configuration des items
            for (int col = 0; col < rowItems.size(); ++col)
            {
                rowItems[col]->setTextAlignment(Qt::AlignCenter);
                rowItems[col]->setEditable(false);
                newModel->setItem(row, col, rowItems[col]);
            }
            row++;
        }

        // Supprimer l'ancien modèle et définir le nouveau
        if (model)
        {
            delete model;
        }
        model = newModel;
        ui->tableView->setModel(model);

        // Définir une largeur spécifique pour chaque colonne
        QList<int> columnWidths = {150, 100, 100, 100, 150, 80, 80, 150, 100};
        for (int col = 0; col < columnWidths.size() && col < model->columnCount(); ++col)
        {
            ui->tableView->setColumnWidth(col, columnWidths[col]);
        }

        // Configuration supplémentaire du tableau
       /* ui->tableView->setSortingEnabled(true);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableView->setAlternatingRowColors(true);*/

        qDebug() << "Tri par DATE_DEBUT terminé avec" << row << "événements.";
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec du tri: " + query.lastError().text());
    }
}

void GEvennement::on_pushButton_Retreive_clicked()
{
    // Utiliser la fonction showEvennements de la classe Evennement pour afficher tous les événements
    E.showEvennements(ui->tableView);

    // Nous n'utilisons plus QSqlQueryModel mais QStandardItemModel
    // Le cast est donc différent
    model = qobject_cast<QStandardItemModel *>(ui->tableView->model());
}

void GEvennement::on_tableView_clicked(const QModelIndex &index)
{
    // Récupérer les données de la ligne sélectionnée
    if (index.isValid())
    {
        int row = index.row();

        // Obtenir le modèle et vérifier son type
        QAbstractItemModel *currentModel = ui->tableView->model();
        if (!currentModel)
        {
            qDebug() << "Erreur: Aucun modèle associé au tableView";
            return;
        }

        // L'ordre des colonnes est: Nom, Type, Date Début, Date Fin, Lieu, Capacité, Prix, Locataire, Identifiant

        try
        {
            // Récupérer le nom pour la modification/suppression (première colonne)
            QString nom = currentModel->index(row, 0).data().toString();
            selectedEventNom = nom;

            // Remplir les champs du formulaire avec les données
            ui->line_NOMevent->setText(currentModel->index(row, 0).data().toString());  // Nom
            ui->line_TYPEevent->setText(currentModel->index(row, 1).data().toString()); // Type

            // Convertir les dates
            QVariant dateDebutValue = currentModel->index(row, 2).data();
            QVariant dateFinValue = currentModel->index(row, 3).data();

            QDate dateDebut = dateDebutValue.toDate();
            QDate dateFin = dateFinValue.toDate();

            if (dateDebut.isValid())
            {
                ui->dateEditDebut->setDate(dateDebut);
            }
            else
            {
                // Essayer de parser manuellement
                QString dateStr = dateDebutValue.toString();
                QDate parsedDate = QDate::fromString(dateStr, "dd/MM/yyyy");
                if (parsedDate.isValid())
                {
                    ui->dateEditDebut->setDate(parsedDate);
                }
            }

            if (dateFin.isValid())
            {
                ui->dateEditFin->setDate(dateFin);
            }
            else
            {
                // Essayer de parser manuellement
                QString dateStr = dateFinValue.toString();
                QDate parsedDate = QDate::fromString(dateStr, "dd/MM/yyyy");
                if (parsedDate.isValid())
                {
                    ui->dateEditFin->setDate(parsedDate);
                }
            }

            ui->line_LIEU->setText(currentModel->index(row, 4).data().toString());          // Lieu
            ui->line_CAPACITEevent->setText(currentModel->index(row, 5).data().toString()); // Capacité
            ui->line_PRIXevent->setText(currentModel->index(row, 6).data().toString());     // Prix

            // Identifiant est dans la dernière colonne (8)
            QString identifiant = currentModel->index(row, 8).data().toString();
            ui->lineEdit_IDENTIFIANT->setText(identifiant);

            // Locataire est dans la colonne 7
            QString locataireName = currentModel->index(row, 7).data().toString();

            // Rechercher dans le combobox par nom
            int comboIndex = ui->comboBox_LOC->findText(locataireName);
            if (comboIndex != -1)
            {
                ui->comboBox_LOC->setCurrentIndex(comboIndex);
            }

            qDebug() << "Ligne sélectionnée:" << row
                     << "Nom:" << nom
                     << "Type:" << ui->line_TYPEevent->text()
                     << "Identifiant:" << identifiant;
        }
        catch (const std::exception &e)
        {
            qDebug() << "Exception lors de l'accès aux données:" << e.what();
        }
    }
}

void GEvennement::on_lineEdit_Recherche_textChanged(const QString &text)
{
    // Recherche dynamique quand le texte change
    if (text.isEmpty())
    {
        // Si le champ est vide, afficher tous les événements
        on_pushButton_Retreive_clicked();
    }
    else
    {
        // Sinon, effectuer la recherche
        on_pushButton_Rechercher_clicked();
    }
}

void GEvennement::on_pushButton_Dashboard_clicked()
{
    showPieChartDialog();
}

void GEvennement::on_pushButton_Locataires_clicked()
{
    // Navigation vers la section Locataires
    QMessageBox::information(this, "Navigation", "Navigation vers la section Locataires");
}

void GEvennement::on_pushButton_Services_clicked()
{
    // Navigation vers la section Services
    QMessageBox::information(this, "Navigation", "Navigation vers la section Services");
}

void GEvennement::on_pushButton_Evennements_clicked()
{
    // Actualiser la page des événements
    on_pushButton_Retreive_clicked();
}

void GEvennement::on_pushButton_deconnecter_clicked()
{
    // Déconnexion
    QMessageBox::information(this, "Déconnexion", "À bientôt!");
    close();
}

void GEvennement::populateLocatairesComboBox()
{
    // Remplir le combobox des locataires
    ui->comboBox_LOC->clear();

    QSqlQuery query;
    query.prepare("SELECT ID_LOCATAIRE, NOM FROM eyk.LOCATAIRES ORDER BY NOM");

    if (query.exec())
    {
        while (query.next())
        {
            QString id = query.value("ID_LOCATAIRE").toString();
            QString nom = query.value("NOM").toString();
            ui->comboBox_LOC->addItem(nom, id);
        }
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Impossible de charger la liste des locataires: " + query.lastError().text());
    }
}

QChart *GEvennement::createPieChart()
{
    QSqlQuery query;
    query.prepare("SELECT TYPE, COUNT(*) as COUNT FROM eyk.EVENEMENTS GROUP BY TYPE");

    QPieSeries *series = new QPieSeries();

    if (query.exec())
    {
        while (query.next())
        {
            QString type = query.value("TYPE").toString();
            int count = query.value("COUNT").toInt();

            QPieSlice *slice = series->append(type + " (" + QString::number(count) + ")", count);
            slice->setLabelVisible(true);
            slice->setLabelPosition(QPieSlice::LabelOutside);

            // Couleurs vives et distinctes pour chaque type
            if (type.contains("Conférence", Qt::CaseInsensitive))
            {
                slice->setColor(QColor("#E74C3C")); // Rouge vif
                slice->setBorderColor(Qt::white);
                slice->setBorderWidth(2);
            }
            else if (type.contains("Concert", Qt::CaseInsensitive))
            {
                slice->setColor(QColor("#3498DB")); // Bleu électrique
                slice->setBorderColor(Qt::white);
                slice->setBorderWidth(2);
            }
            else if (type.contains("Exposition", Qt::CaseInsensitive))
            {
                slice->setColor(QColor("#2ECC71")); // Vert émeraude
                slice->setBorderColor(Qt::white);
                slice->setBorderWidth(2);
            }
            else if (type.contains("Séminaire", Qt::CaseInsensitive))
            {
                slice->setColor(QColor("#F1C40F")); // Jaune soleil
                slice->setBorderColor(Qt::white);
                slice->setBorderWidth(2);
            }
            else if (type.contains("Formation", Qt::CaseInsensitive))
            {
                slice->setColor(QColor("#9B59B6")); // Violet royal
                slice->setBorderColor(Qt::white);
                slice->setBorderWidth(2);
            }
            else if (type.contains("Spectacle", Qt::CaseInsensitive))
            {
                slice->setColor(QColor("#E67E22")); // Orange vif
                slice->setBorderColor(Qt::white);
                slice->setBorderWidth(2);
            }
            else if (type.contains("Festival", Qt::CaseInsensitive))
            {
                slice->setColor(QColor("#16A085")); // Turquoise foncé
                slice->setBorderColor(Qt::white);
                slice->setBorderWidth(2);
            }
            else if (type.contains("Atelier", Qt::CaseInsensitive))
            {
                slice->setColor(QColor("#8E44AD")); // Violet profond
                slice->setBorderColor(Qt::white);
                slice->setBorderWidth(2);
            }
            else
            {
                slice->setColor(QColor("#34495E")); // Gris bleuté
                slice->setBorderColor(Qt::white);
                slice->setBorderWidth(2);
            }

            // Effet d'explosion au clic
            connect(slice, &QPieSlice::clicked, [=]()
                    {
                if (slice->isExploded()) {
                    slice->setExploded(false);
                } else {
                    slice->setExploded(true);
                } });

            // Effet de survol
            connect(slice, &QPieSlice::hovered, [=](bool show)
                    {
                if (show) {
                    slice->setLabelVisible(true);
                    slice->setExploded(true);
                } else {
                    slice->setExploded(false);
                } });
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des événements par type");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setBackgroundBrush(QColor("#FFFFFF")); // Fond blanc

    return chart;
}

void GEvennement::showPieChartDialog()
{
    // Afficher le graphique dans une boîte de dialogue
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des Événements");
    dialog->setMinimumSize(600, 400);

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QChartView *chartView = new QChartView(createPieChart(), dialog);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);

    QPushButton *closeButton = new QPushButton("Fermer", dialog);
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    layout->addWidget(closeButton);

    dialog->setLayout(layout);
    dialog->exec();
}

void GEvennement::exportToPDF(const QModelIndex &index)
{
    // Fonction pour exporter les détails d'un événement individuel en PDF
    if (!index.isValid())
    {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un événement.");
        return;
    }

    int row = index.row();
    QString identifiant = model->index(row, 0).data().toString();

    // Récupérer les détails de l'événement
    QSqlQuery query;
    query.prepare("SELECT * FROM eyk.EVENEMENTS WHERE IDENTIFIANT = :id");
    query.bindValue(":id", identifiant);

    if (query.exec() && query.next())
    {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        "Enregistrer le PDF", QString(), "Fichiers PDF (*.pdf)");

        if (fileName.isEmpty())
            return;

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        printer.setPageSize(QPageSize(QPageSize::A4));

        QTextDocument doc;
        QString html = "<h1 align='center'>Détails de l'Événement</h1>";
        html += "<p><strong>ID:</strong> " + query.value("IDENTIFIANT").toString() + "</p>";
        html += "<p><strong>Nom:</strong> " + query.value("NOM").toString() + "</p>";
        html += "<p><strong>Type:</strong> " + query.value("TYPE").toString() + "</p>";
        html += "<p><strong>Capacité:</strong> " + query.value("CAPACITE").toString() + "</p>";
        html += "<p><strong>Prix:</strong> " + query.value("PRIX").toString() + "</p>";
        html += "<p><strong>Date Début:</strong> " + formatDate(query.value("DATE_DEBUT").toDateTime()) + "</p>";
        html += "<p><strong>Date Fin:</strong> " + formatDate(query.value("DATE_FIN").toDateTime()) + "</p>";
        html += "<p><strong>Lieu:</strong> " + query.value("LIEU").toString() + "</p>";

        doc.setHtml(html);
        doc.print(&printer);

        QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès !");
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les détails de l'événement.");
    }
}

void GEvennement::on_pushButton_Map_clicked()
{
    qDebug() << "Bouton Map cliqué";

    // Créer une boîte de dialogue pour la carte
    QDialog *mapDialog = new QDialog(this);
    mapDialog->setWindowTitle("Carte des événements");
    mapDialog->setMinimumSize(800, 600);

    // Créer un layout vertical pour la boîte de dialogue
    QVBoxLayout *layout = new QVBoxLayout(mapDialog);

    // Initialiser la carte dans la boîte de dialogue
    QQuickWidget *dialogMapWidget = new QQuickWidget(mapDialog);
    dialogMapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    // Activer le débogage QML
    QQmlEngine *engine = dialogMapWidget->engine();
    engine->rootContext()->setContextProperty("debug", true);

    // Charger les événements depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT IDENTIFIANT, NOM, TYPE, LIEU FROM eyk.EVENEMENTS");

    QVariantList events;
    if (query.exec())
    {
        while (query.next())
        {
            QString lieu = query.value("LIEU").toString();
            qDebug() << "Lieu trouvé:" << lieu;
            // Extraire les coordonnées du format "Latitude: X, Longitude: Y"
            QRegularExpression regex("Latitude: (-?\\d+\\.?\\d*), Longitude: (-?\\d+\\.?\\d*)");
            QRegularExpressionMatch match = regex.match(lieu);
            if (match.hasMatch())
            {
                double latitude = match.captured(1).toDouble();
                double longitude = match.captured(2).toDouble();

                QVariantMap event;
                event["id"] = query.value("IDENTIFIANT").toString();
                event["nom"] = query.value("NOM").toString();
                event["type"] = query.value("TYPE").toString();
                event["latitude"] = latitude;
                event["longitude"] = longitude;
                events.append(event);
                qDebug() << "Événement ajouté:" << event;
            }
        }
    }
    else
    {
        qDebug() << "Erreur de requête:" << query.lastError().text();
    }

    qDebug() << "Nombre d'événements trouvés:" << events.size();

    // Définir la source QML
    QUrl sourceUrl = QUrl("qrc:/map.qml");
    qDebug() << "URL de la source QML:" << sourceUrl;

    // Passer les événements au contexte QML avant de charger le fichier
    engine->rootContext()->setContextProperty("initialEvents", events);

    // Charger le fichier QML
    dialogMapWidget->setSource(sourceUrl);

    // Vérifier les erreurs de chargement
    if (dialogMapWidget->status() == QQuickWidget::Error)
    {
        QString errors;
        for (const QQmlError &error : dialogMapWidget->errors())
        {
            errors += error.toString() + "\n";
            qDebug() << "Erreur QML:" << error.toString();
        }
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement de la carte:\n" + errors);
        delete mapDialog;
        return;
    }

    // Passer les événements au QML
    QQuickItem *rootObject = dialogMapWidget->rootObject();
    if (rootObject)
    {
        rootObject->setProperty("events", events);
        connect(rootObject, SIGNAL(locationSelected(double, double)),
                this, SLOT(onLocationSelected(double, double)));
        qDebug() << "Signaux de la carte connectés avec succès";
    }
    else
    {
        qDebug() << "Erreur: Impossible de récupérer l'objet racine QML";
        QMessageBox::warning(this, "Avertissement", "Impossible de connecter les signaux de la carte");
    }

    layout->addWidget(dialogMapWidget);

    // Ajouter des boutons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("OK", mapDialog);
    QPushButton *cancelButton = new QPushButton("Annuler", mapDialog);

    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);

    // Connecter les boutons
    connect(okButton, &QPushButton::clicked, mapDialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, mapDialog, &QDialog::reject);

    // Afficher la boîte de dialogue
    mapDialog->exec();

    // Nettoyer
    delete mapDialog; // Cela détruira aussi dialogMapWidget car il est enfant de mapDialog
}

void GEvennement::onLocationSelected(double latitude, double longitude)
{
    qDebug() << "Location sélectionnée:" << latitude << longitude;
    QString location = QString("Latitude: %1, Longitude: %2").arg(latitude).arg(longitude);
    ui->line_LIEU->setText(location);
}

void GEvennement::on_pushButton_Calendar_clicked()
{
    // Ouvrir la boîte de dialogue du calendrier
    CalendarDialog dialog(this);
    dialog.exec();
}
