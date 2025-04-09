#include "glocataires.h"
#include "ui_glocataires.h"
#include "connection.h"
#include "locataires.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QtCharts>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QInputDialog>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QUrlQuery>

GLocataire::GLocataire(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GLocataire)
    , model(new QSqlQueryModel(this))
    , statsChart(nullptr)
    , chartView(nullptr)
    , proxyModel(new QSortFilterProxyModel(this))
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    Locataires L;
    Connection conn;

    if (!conn.createconnect()) {
        qDebug() << "Database connection failed!";
        QMessageBox::critical(this, "Database Error",
                            "Failed to connect to the database: " +
                            QSqlDatabase::database().lastError().text());
        return;
    }

    qDebug() << "Database connected successfully!";
    
    // Initialize the table view
    L.showLocataires(ui->tableView);
    // Set up proxy model for sorting and filtering
    proxyModel->setSourceModel(ui->tableView->model());
    ui->tableView->setModel(proxyModel);

    // Configure the proxy model for sorting
    proxyModel->setDynamicSortFilter(true); // Enable dynamic sorting
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive); // Case-insensitive sorting
    proxyModel->setSortLocaleAware(true); // Locale-aware sorting
    ui->tableView->setModel(proxyModel);
    
    // Initialize sort combo box
    ui->sortComboBox->addItem("Par défaut");
    ui->sortComboBox->addItem("Montant croissant");
    ui->sortComboBox->addItem("Montant décroissant");

    // Connect signals and slots
    connect(ui->pushButton_Ajouter, &QPushButton::clicked, this, &GLocataire::on_pushButton_Ajouter_clicked);
    connect(ui->pushButton_Supprimer, &QPushButton::clicked, this, &GLocataire::on_pushButton_Supprimer_clicked);
    connect(ui->pushButton_Modifier, &QPushButton::clicked, this, &GLocataire::on_pushButton_Modifier_clicked);
    connect(ui->tableView, &QTableView::clicked, this, &GLocataire::on_tableView_clicked);
    connect(ui->stat, &QPushButton::clicked, this, &GLocataire::on_stat_clicked);
    connect(ui->PDF, &QPushButton::clicked, this, &GLocataire::on_PDF_clicked);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &GLocataire::on_searchLineEdit_textChanged);
    connect(ui->sortComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), 
            this, &GLocataire::on_sortComboBox_currentIndexChanged);
    connect(ui->pushButton_ChatBot, &QPushButton::clicked, this, &GLocataire::on_pushButton_ChatBot_clicked);
}

GLocataire::~GLocataire()
{
    delete model;
    delete ui;
}

void GLocataire::refreshTable()
{
    Locataires L;
    L.showLocataires(ui->tableView);
}

void GLocataire::populateFieldsFromSelection(const QModelIndex &index)
{
    if (!index.isValid()) return;

    // Get the row data
    QAbstractItemModel *model = ui->tableView->model();
    int row = index.row();

    // Populate the input fields with the selected row's data
    ui->line_IDENTIFIANT->setText(model->data(model->index(row, 8)).toString());
    ui->line_NOMLoc->setText(model->data(model->index(row, 1)).toString());
    ui->line_PhoneLoc->setText(model->data(model->index(row, 2)).toString());
    ui->line_MAILLoc->setText(model->data(model->index(row, 3)).toString());
    ui->line_CONTRATLoc->setText(model->data(model->index(row, 7)).toString());
    
    // Set the combobox value based on payment status
    QString statutPaiement = model->data(model->index(row, 6)).toString();
    int comboIndex = ui->comboBox_StatutPaiement->findText(statutPaiement);
    if (comboIndex != -1) {
        ui->comboBox_StatutPaiement->setCurrentIndex(comboIndex);
    }
    
    ui->line_TYPELoc->setText(model->data(model->index(row, 4)).toString());
    ui->line_MONTANT_LOYERLOC->setText(model->data(model->index(row, 5)).toString());
}

void GLocataire::on_tableView_clicked(const QModelIndex &index)
{
    populateFieldsFromSelection(index);
}

void GLocataire::on_pushButton_Supprimer_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner un locataire à supprimer.");
        return;
    }

    int row = currentIndex.row();
    QString identifiantStr = ui->tableView->model()->data(ui->tableView->model()->index(row, 8)).toString();
    bool ok;
    int identifiant = identifiantStr.toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Identifiant invalide.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                "Êtes-vous sûr de vouloir supprimer ce locataire ?",
                                QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Locataires L;
        bool success = L.Supprimer(identifiant);
        
        if (success) {
            QMessageBox::information(this, "Succès", "Locataire supprimé avec succès.");
            refreshTable();
        } else {
            QMessageBox::warning(this, "Erreur", "Erreur lors de la suppression du locataire.");
        }
    }
}

void GLocataire::on_pushButton_Modifier_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner un locataire à modifier.");
        return;
    }

    // Get values from input fields
    QString identifiantStr = ui->line_IDENTIFIANT->text();
    QString nom = ui->line_NOMLoc->text();
    QString telephone = ui->line_PhoneLoc->text();
    QString email = ui->line_MAILLoc->text();
    QString typeLogement = ui->line_TYPELoc->text();
    QString montantLoyerStr = ui->line_MONTANT_LOYERLOC->text();
    QString statutPaiement = ui->comboBox_StatutPaiement->currentText();
    QString typeContrat = ui->line_CONTRATLoc->text();

    // Basic validation
    if (nom.isEmpty() || telephone.isEmpty() || email.isEmpty() || 
        typeLogement.isEmpty() || montantLoyerStr.isEmpty() || 
        typeContrat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoires.");
        return;
    }

    bool ok;
    int identifiant = identifiantStr.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Identifiant invalide.");
        return;
    }

    float montantLoyer = montantLoyerStr.toFloat(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Montant du loyer invalide.");
        return;
    }

    // Create Locataires object and update
    Locataires L;
    L.setIdentifiant(identifiant);
    L.setNom(nom);
    L.setTel(telephone);
    L.setMail(email);
   // L.setType(typeLogement);
    L.setMontantLoyer(montantLoyer);
    L.setStatutPaiement(statutPaiement);
    L.setContrat(typeContrat);

    bool success = L.modifier(QString::number(L.getIdentifiant()), L.getNom(), L.getTel(),
                              L.getMail(), L.getContrat(), L.getStatutPaiement(),
                              L.getTypeLocataire(), QString::number(L.getMontantLoyer()));
    if (success) {
        QMessageBox::information(this, "Succès", "Locataire modifié avec succès.");
        refreshTable();
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la modification du locataire.");
    }
}

void GLocataire::createPieChart()
{
    // Delete existing chart if any
    if (statsChart) {
        delete statsChart;
        statsChart = nullptr;
    }
    if (chartView) {
        delete chartView;
        chartView = nullptr;
    }

    // Create a new chart
    statsChart = new QChart();
    QPieSeries *series = new QPieSeries();

    // Get payment status statistics
    QSqlQuery query;
    query.prepare("SELECT STATUT_PAIEMENT, COUNT(*) as count "
                "FROM LOCATAIRES "
                "GROUP BY STATUT_PAIEMENT");

    if (query.exec()) {
        while (query.next()) {
            QString status = query.value("STATUT_PAIEMENT").toString();
            int count = query.value("count").toInt();
            
            // Add slice to the pie series
            QPieSlice *slice = series->append(status, count);
            
            // Set colors based on payment status
            if (status == "Payé") {
                slice->setBrush(QColor(46, 204, 113));
            } else if (status == "En retard") {
                slice->setBrush(QColor(231, 76, 60));
            } else if (status == "En attente") {
                slice->setBrush(QColor(241, 196, 15));
            }
            
            // Connect slice signals
            connect(slice, &QPieSlice::hovered, this, [=](bool show){
                if (show) {
                    slice->setExploded(true);
                    slice->setLabelVisible(true);
                } else {
                    slice->setExploded(false);
                    slice->setLabelVisible(false);
                }
            });
        }
    }

    // Customize the chart
    statsChart->addSeries(series);
    statsChart->setTitle("Statistiques des paiements");
    statsChart->setAnimationOptions(QChart::AllAnimations);
    statsChart->legend()->setAlignment(Qt::AlignRight);

    // Create the chart view
    chartView = new QChartView(statsChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400, 300);

    // Show the chart in a new window
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques");
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->resize(600, 400);
    dialog->exec();
}

void GLocataire::on_stat_clicked()
{
    createPieChart();
}

void GLocataire::exportToPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        "Exporter en PDF", "",
        "Fichiers PDF (*.pdf)");
    
    if (fileName.isEmpty())
        return;
    
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";
    
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(30, 30, 30, 30));
    
    QPainter painter(&writer);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Get the model
    QAbstractItemModel *model = ui->tableView->model();
    int numRows = model->rowCount();
    
    // Define columns
    struct Column {
        QString header;
        int modelIndex;
        float widthRatio;
    };
    
    QVector<Column> columns = {
        {"ID", 8, 0.1f},
        {"Nom", 1, 0.2f},
        {"Téléphone", 2, 0.15f},
        {"Email", 3, 0.25f},
        {"Type", 4, 0.1f},
        {"Loyer", 5, 0.1f},
        {"Statut", 6, 0.1f}
    };
    
    // Set up fonts
    QFont titleFont("Arial", 18, QFont::Bold);
    QFont headerFont("Arial", 10, QFont::Bold);
    QFont contentFont("Arial", 10);
    
    // Draw title
    painter.setFont(titleFont);
    painter.drawText(QRect(0, 0, writer.width(), 50),
                    Qt::AlignHCenter | Qt::AlignVCenter,
                    "Liste des Locataires");
    
    // Calculate dimensions
    int startY = 100;
    int startX = 0;
    int rowHeight = writer.logicalDpiY() * 0.4; // Environ 1 cm (0.4 pouces)
    int totalWidth = writer.width() - 60; // Account for margins
    
    // Draw header
    painter.setFont(headerFont);
    int currentX = startX;
    
    for (const auto &col : columns) {
        int colWidth = totalWidth * col.widthRatio;
        QRect headerCell(currentX, startY, colWidth, rowHeight);
        
        // Draw header cell
        painter.fillRect(headerCell, QColor(240, 240, 240));
        painter.setPen(QPen(Qt::black, 1));
        painter.drawRect(headerCell);
        painter.drawText(headerCell, Qt::AlignCenter, col.header);
        
        currentX += colWidth;
    }
    
    startY += rowHeight;
    
    // Draw content
    painter.setFont(contentFont);
    for (int row = 0; row < numRows; ++row) {
        currentX = startX;
        
        // Alternate row colors
        if (row % 2 == 0) {
            painter.fillRect(QRect(startX, startY + (row * rowHeight), 
                                 totalWidth, rowHeight), 
                           QColor(252, 252, 252));
        }
        
        for (const auto &col : columns) {
            int colWidth = totalWidth * col.widthRatio;
            QRect cell(currentX, startY + (row * rowHeight), colWidth, rowHeight);
            
            // Draw cell border
            painter.setPen(QPen(Qt::black, 1));
            painter.drawRect(cell);
            
            // Get and format cell data
            QString text = model->data(model->index(row, col.modelIndex)).toString();
            
            // Draw cell text with padding
            painter.drawText(cell.adjusted(5, 0, -5, 0), 
                           Qt::AlignVCenter | Qt::AlignLeft, 
                           text);
            currentX += colWidth;
        }
    }
    
    // Draw footer with current date
    painter.setFont(contentFont);
    QRect footerRect(0, startY + (numRows * rowHeight) + 10, writer.width(), 20);
    painter.drawText(footerRect, Qt::AlignRight | Qt::AlignVCenter,
                    "Généré le: " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm"));
    
    painter.end();
    
    QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès !");
}

void GLocataire::on_PDF_clicked()
{
    exportToPDF();
}

// Check if locataire exists
bool GLocataire::locataireExists(int identifiant)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM LOCATAIRES WHERE IDENTIFIANT = :identifiant");
    query.bindValue(":identifiant", identifiant);

    if (query.exec() && query.next()) {
        return true;  // Found the locataire
    }
    return false;
}

void GLocataire::sendConfirmationEmail(const QString &recipientEmail, const QString &name)
{
    qDebug() << "Démarrage de l'envoi d'email via Mailjet à:" << recipientEmail;

    // Configuration Mailjet
    const QString apiKey = "353560aceeffc08e0d03d22686f7f685";
    const QString apiSecret = "873de1f24891f07f52bb859d8e07dcd3";
    const QString senderEmail = "c8b601g2@gmail.com";
    const QString senderName = "GLocataire";

    // Préparation de la requête HTTP
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    
    // Construction de l'URL
    QUrl endpoint("https://api.mailjet.com/v3.1/send");
    
    // Construction de la requête
    QNetworkRequest request(endpoint);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    // Ajout de l'authentification basique
    QString credentials = apiKey + ":" + apiSecret;
    QByteArray auth = "Basic " + credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", auth);
    
    // Préparation du contenu de l'email
    QString message = QString("Cher(e) %1,\n\nNous confirmons votre inscription en tant que locataire dans notre système GLocataire.\n\nVos informations ont été enregistrées avec succès.\n\nCordialement,\nL'équipe GLocataire").arg(name);
    
    // Construction du JSON pour l'API Mailjet
    QJsonObject email;
    email["From"] = QJsonObject{
        {"Email", senderEmail},
        {"Name", senderName}
    };
    
    QJsonArray to;
    to.append(QJsonObject{
        {"Email", recipientEmail},
        {"Name", name}
    });
    email["To"] = to;
    
    email["Subject"] = "Confirmation d'inscription - GLocataire";
    email["TextPart"] = message;
    
    QJsonArray messages;
    messages.append(email);
    
    QJsonObject jsonRequest;
    jsonRequest["Messages"] = messages;
    
    QJsonDocument doc(jsonRequest);
    QByteArray jsonData = doc.toJson();
    
    // Envoi de la requête POST
    QNetworkReply *reply = manager->post(request, jsonData);
    
    // Gestion de la réponse
    connect(reply, &QNetworkReply::finished, this, [=]() {
        if(reply->error() == QNetworkReply::NoError) {
            QMessageBox::information(this, "Succès", "Email de confirmation envoyé avec succès!");
        } else {
            QMessageBox::warning(this, "Erreur", "Erreur lors de l'envoi de l'email: " + reply->errorString());
            qDebug() << "Réponse de l'API:" << reply->readAll();
        }
        
        reply->deleteLater();
        manager->deleteLater();
    });
}

void GLocataire::on_pushButton_Ajouter_clicked()
{
    // Get the values from the input fields
    QString nom = ui->line_NOMLoc->text();  // Name
    QString tel = ui->line_PhoneLoc->text();  // Phone number
    QString mail = ui->line_MAILLoc->text();  // Email
    QString contrat = ui->line_CONTRATLoc->text();  // Contract
    QString statutPaiement = ui->comboBox_StatutPaiement->currentText();  // Payment Status
    QString typeLocataire = ui->line_TYPELoc->text();  // Tenant Type
    QString montantLoyerStr = ui->line_MONTANT_LOYERLOC->text();  // Rent Amount

    // Check if required fields are empty
    if (nom.isEmpty() || tel.isEmpty() || mail.isEmpty() || montantLoyerStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs obligatoires doivent être remplis.");
        return;
    }

    // Check if 'nom' contains only alphabetic characters (including accented letters)
    bool validNom = true;
    for (int i = 0; i < nom.length(); i++) {
        if (!nom[i].isLetter() && !nom[i].isSpace()) {
            validNom = false;
            break;
        }
    }
    if (!validNom) {
        QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres.");
        return;
    }

    // Check if 'tel' is a valid phone number (assuming +216 is the country code for Tunisia)
    if (!(tel.startsWith("+216") && tel.length() == 13)) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide.");
        return;
    }

    // Validate email format with a simple check (basic format check)
    if (!mail.contains("@") || !mail.contains(".")) {
        QMessageBox::warning(this, "Erreur", "Adresse email invalide.");
        return;
    }

    // Check if 'contrat' is not empty
    if (contrat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le champ Contrat est obligatoire.");
        return;
    }

    // Check if 'statutPaiement' is either 'Payé' or 'Non payé'
    if (statutPaiement != "Payé" && statutPaiement != "Non payé") {
        QMessageBox::warning(this, "Erreur", "Statut de paiement invalide. Utilisez 'Payé' ou 'Non payé'.");
        return;
    }

    // Check if 'typeLocataire' is not empty
    if (typeLocataire.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le champ Type de Locataire est obligatoire.");
        return;
    }

    // Convert the rent amount to double and check if the conversion is successful
    bool montantLoyerOk;
    double montantLoyer = montantLoyerStr.toDouble(&montantLoyerOk);
    if (!montantLoyerOk || montantLoyer <= 0) {
        QMessageBox::warning(this, "Erreur", "Montant de loyer invalide.");
        return;
    }

    // Optionally, generate or get an identifiant for the locataire
    QString identifiantStr = ui->line_IDENTIFIANT->text();  // Identifiant
    bool identifiantOk;
    int identifiant = identifiantStr.toInt(&identifiantOk);
    if (!identifiantOk || identifiant == 0) {
        QMessageBox::warning(this, "Erreur", "Identifiant invalide.");
        return;
    }

    // Create a new Locataire instance and call the Ajout method
    Locataires locataire;
    bool success = locataire.Ajout(identifiant, nom, tel, mail, contrat, statutPaiement, typeLocataire, montantLoyer);

    // Check the result
    if (success) {
        QMessageBox::information(this, "Succès", "Locataire ajouté avec succès.");
        locataire.showLocataires(ui->tableView);  // Optionally update the view

        // Envoyer l'email de confirmation
        sendConfirmationEmail(mail, nom);

        // Optionally, clear the input fields after adding the locataire
        ui->line_NOMLoc->clear();
        ui->line_PhoneLoc->clear();
        ui->line_MAILLoc->clear();
        ui->line_CONTRATLoc->clear();
        ui->comboBox_StatutPaiement->setCurrentIndex(0);
        ui->line_TYPELoc->clear();
        ui->line_MONTANT_LOYERLOC->clear();
        ui->line_IDENTIFIANT->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du locataire.");
    }
}

void GLocataire::on_pushButton_Retreive_clicked()
{
    // Get the identifiant from the input field
    QString identifiantStr = ui->line_IDENTIFIANT->text();  // Get IDENTIFIANT from the line edit

    // Convert QString to int (to match the IDENTIFIANT type in the database)
    bool ok;
    int identifiant = identifiantStr.toInt(&ok);

    // If the conversion fails (not a valid number), show an error
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "L'IDENTIFIANT fourni est invalide.");
        return;
    }

    // Retrieve the locataire data using the identifiant
    Locataires locataire;
    if (!locataire.RetreiveData(identifiant)) {
        QMessageBox::warning(this, "Erreur", "Locataire introuvable.");
        return;
    }

    // Fill the data into the respective line edits
    ui->line_NOMLoc->setText(locataire.getNom());
    ui->line_PhoneLoc->setText(locataire.getTel());
    ui->line_MAILLoc->setText(locataire.getMail());
    ui->line_CONTRATLoc->setText(locataire.getContrat());
    ui->line_MONTANT_LOYERLOC->setText(QString::number(locataire.getMontantLoyer()));
    ui->comboBox_StatutPaiement->setCurrentText(locataire.getStatutPaiement());
    ui->line_TYPELoc->setText(locataire.getTypeLocataire());
}

void GLocataire::filterLocataires(const QString &searchText)
{
    if (!proxyModel) return;
    
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
proxyModel->setFilterKeyColumn(-1); // -1 pour filtrer sur toutes les colonnes
    proxyModel->setFilterFixedString(searchText);
}

void GLocataire::sortLocataires(int sortOrder)
{
    if (!proxyModel) return;

    switch (sortOrder) {
    case 1: // Montant croissant
        proxyModel->sort(5, Qt::AscendingOrder);  // 5 est l'index de la colonne "Loyer"
        break;
    case 2: // Montant décroissant
        proxyModel->sort(5, Qt::DescendingOrder);
        break;
    default: // Par défaut
        proxyModel->sort(-1); // Désactive le tri
        break;
    }
}

void GLocataire::on_searchLineEdit_textChanged(const QString &text)
{
    filterLocataires(text);
}

void GLocataire::on_sortComboBox_currentIndexChanged(int index)
{
    sortLocataires(index);
}

void GLocataire::on_pushButton_ChatBot_clicked()
{
    bool ok;
    QString userInput = QInputDialog::getText(this, tr("ChatBot"),
                                             tr("Comment puis-je vous aider ?\n- Tapez 'info [nom]' pour les détails d'un locataire\n- Tapez 'liste' pour voir tous les locataires\n- Tapez 'aide' pour plus d'options"),
                                             QLineEdit::Normal, "", &ok);
    if (ok && !userInput.isEmpty()) {
        QString response;
        QSqlQuery query;
        
        // Convertir l'entrée en minuscules pour la comparaison
        QString command = userInput.toLower();
        
        if (command == "aide") {
            response = "Commandes disponibles :\n"
                      "- info [nom] : Affiche les détails d'un locataire\n"
                      "- liste : Affiche la liste des locataires\n"
                      "- paiements : Affiche les locataires avec leurs statuts de paiement\n"
                      "- retard : Liste les locataires en retard de paiement\n"
                      "- total : Affiche le nombre total de locataires";
        }
        else if (command == "liste") {
            query.exec("SELECT NOM FROM LOCATAIRES ORDER BY NOM");
            response = "Liste des locataires :\n";
            while (query.next()) {
                response += "- " + query.value(0).toString() + "\n";
            }
        }
        else if (command == "paiements") {
            query.exec("SELECT NOM, STATUT_PAIEMENT FROM LOCATAIRES ORDER BY NOM");
            response = "Statuts des paiements :\n";
            while (query.next()) {
                response += "- " + query.value(0).toString() + " : " + query.value(1).toString() + "\n";
            }
        }
        else if (command == "retard") {
            query.exec("SELECT NOM FROM LOCATAIRES WHERE STATUT_PAIEMENT = 'En retard' ORDER BY NOM");
            response = "Locataires en retard de paiement :\n";
            while (query.next()) {
                response += "- " + query.value(0).toString() + "\n";
            }
        }
        else if (command == "total") {
            query.exec("SELECT COUNT(*) FROM LOCATAIRES");
            if (query.next()) {
                response = "Nombre total de locataires : " + query.value(0).toString();
            }
        }
        else if (command.startsWith("info ")) {
            QString nom = command.mid(5); // Enlever "info " du début
            query.prepare("SELECT * FROM LOCATAIRES WHERE LOWER(NOM) = LOWER(:nom)");
            query.bindValue(":nom", nom);
            
            if (query.exec() && query.next()) {
                response = "Informations sur le locataire :\n"
                           "Nom : " + query.value("NOM").toString() + "\n"
                           "ID : " + query.value("IDENTIFIANT").toString() + "\n"
                           "Téléphone : " + query.value("TELEPHONE").toString() + "\n"
                           "Email : " + query.value("EMAIL").toString() + "\n"
                           "Type de contrat : " + query.value("TYPE_CONTRAT").toString() + "\n"
                           "Statut paiement : " + query.value("STATUT_PAIEMENT").toString() + "\n"
                           "Type de logement : " + query.value("TYPE_LOGEMENT").toString() + "\n"
                           "Montant loyer : " + query.value("MONTANT_LOYER").toString() + " DT";
            } else {
                response = "Désolé, je ne trouve pas de locataire avec ce nom. Vérifiez l'orthographe ou tapez 'liste' pour voir tous les locataires.";
            }
        }
        else {
            response = "Je ne comprends pas cette commande. Tapez 'aide' pour voir la liste des commandes disponibles.";
        }
        
        QMessageBox::information(this, "ChatBot", response);
    }
}
