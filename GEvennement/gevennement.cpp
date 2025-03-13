#include "gevennement.h"
#include "ui_gevennement.h"
#include "connection.h"
#include <QMessageBox> // For showing error messages
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <QStandardItemModel>
#include <QStandardItem>

#include <QtCharts> // Include Qt Charts

#include <QPrinter>       // For PDF generation
#include <QPainter>       // For drawing on the PDF
#include <QFileDialog>    // For file save dialog
#include <QDateTime>      // For adding a timestamp to the PDF


GEvennement::GEvennement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GEvennement), model(new QSqlQueryModel(this))
{
    ui->setupUi(this);

    // Create a Connection object to verify the database connection
    Connection conn;

    // Check if the database connection is successful
    if (!conn.createconnect()) {
        qDebug() << "Database connection failed!";
        // Access the last error directly from the database connection
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database: " + QSqlDatabase::database().lastError().text());
        return;  // Exit the constructor if the connection fails
    }

    // If the connection is successful, proceed to display the data in the list view
    qDebug() << "Database connected successfully!";

    // Call the method to show events from the database
    showEvennements();

    // Connect UI signals to slots
    connect(ui->pushButton_Ajouter, SIGNAL(clicked()), this, SLOT(on_pushButton_Ajouter_clicked()));

connect(ui->pushButton_Supprimer, &QPushButton::clicked, this, &GEvennement::on_pushButton_Supprimer_clicked);


    connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_listView_clicked(QModelIndex)));

    connect(ui->searchBar, &QLineEdit::textChanged, this, &GEvennement::onSearchInitiated);
    ui->comboBox_tri->addItem("Low to High");
    ui->comboBox_tri->addItem("High to Low");
    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &GEvennement::onSortChanged);
    connect(ui->pushButton_PDF, &QPushButton::clicked, this, &GEvennement::exportToPDF);


    connect(ui->pushButton_Statistique, &QPushButton::clicked, this, &GEvennement::on_pushButton_Statistique_clicked);


}



GEvennement::~GEvennement()
{
    // Clean up any allocated memory or resources if needed
    delete model;
    delete ui;
}


int GEvennement::countEvents() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EVENEMENTS");

    if (query.exec() && query.next()) {
        return query.value(0).toInt(); // Return the count of events
    } else {
        qDebug() << "Error counting events: " << query.lastError().text();
        return -1; // Return -1 to indicate an error
    }
}



void GEvennement::showEventsChart() {
    int count = countEvents();
    if (count < 0) {
        QMessageBox::critical(this, "Error", "Failed to fetch events count.");
        return;
    }

    // Create a bar series and add the count
    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Events");
    *set << count; // Add the count to the bar set
    series->append(set);

    // Create a chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Number of Events");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Create axes
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("Events"); // X-axis label
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, count + 10); // Y-axis range (add some padding)
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create a chart view to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a new window to display the chart
    QMainWindow *chartWindow = new QMainWindow();
    chartWindow->setCentralWidget(chartView);
    chartWindow->resize(800, 600);
    chartWindow->show();
}



void GEvennement::showEvennements()
{
    qDebug() << "Fetching events data...";

    QSqlQuery query;
    query.prepare("SELECT ID_EVENT, NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX FROM EVENEMENTS");

    // Execute the query
    if (query.exec()) {
        qDebug() << "Query executed successfully!";

        // Create a QStandardItemModel for QListView
        QStandardItemModel *model = new QStandardItemModel();

        // Loop through the query results and add each row to the model
        while (query.next()) {
            // Create a string that combines the columns for this row
            QString eventString = query.value(1).toString() + " | "   // NOM
                                  + query.value(2).toString() + " | " // TYPE
                                  + query.value(3).toDate().toString("yyyy-MM-dd") + " | " // DATE_DEBUT
                                  + query.value(4).toDate().toString("yyyy-MM-dd") + " | " // DATE_FIN
                                  + query.value(5).toString() + " | "  // LIEU
                                  + QString::number(query.value(6).toInt()) + " | "  // CAPACITE
                                  + QString::number(query.value(7).toFloat(), 'f', 2);  // PRIX

            // Add the formatted string to the model as a new item
            QStandardItem *item = new QStandardItem(eventString);
            model->appendRow(item);
        }

        // Set the model to the ListView widget
        ui->listView->setModel(model);
        qDebug() << "Setting model to listView...";

    } else {
        qDebug() << "Query failed: " << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to retrieve event data: " + query.lastError().text());
    }
}

void GEvennement::ajout(const QString& nom, const QString& capacite, const QString& type,
                        const QString& prix, const QDate& dateDebut, const QDate& dateFin, const QString& lieu)
{
    QString errorMessage;

    // Vérification que tous les champs sont remplis
    if (nom.isEmpty() || capacite.isEmpty() || type.isEmpty() || prix.isEmpty() || lieu.isEmpty()) {
        errorMessage += "All fields must be filled.\n";
    }

    // Vérification que capacité et prix sont des nombres valides
    bool okCapacite, okPrix;
    int capaciteInt = capacite.toInt(&okCapacite);
    double prixDouble = prix.toDouble(&okPrix);

    if (!okCapacite || capaciteInt <= 0) {
        errorMessage += "Capacity must be a valid positive number.\n";
    }

    if (!okPrix || prixDouble <= 0) {
        errorMessage += "Price must be a valid positive number.\n";
    }

    // Vérification que la date de fin est après la date de début
    if (dateFin <= dateDebut) {
        errorMessage += "End date must be after the start date.\n";
    }

    // Vérification si l'événement existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EVENEMENTS WHERE NOM = :nom AND DATE_DEBUT = :dateDebut");
    checkQuery.bindValue(":nom", nom);
    checkQuery.bindValue(":dateDebut", dateDebut.toString("yyyy-MM-dd"));

    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        errorMessage += "An event with this name and start date already exists.\n";
    }

    // Affichage unique des erreurs
    if (!errorMessage.isEmpty()) {
        //QMessageBox::warning(this, "Input Error", errorMessage);
        return; // On arrête ici

    }

    // Insérer l'événement dans la base de données
    QSqlQuery query;
    query.prepare("INSERT INTO EVENEMENTS (NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX) "
                  "VALUES (:nom, :type, :dateDebut, :dateFin, :lieu, :capacite, :prix)");

    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":dateDebut", dateDebut.toString("yyyy-MM-dd"));
    query.bindValue(":dateFin", dateFin.toString("yyyy-MM-dd"));
    query.bindValue(":lieu", lieu);
    query.bindValue(":capacite", capaciteInt);
    query.bindValue(":prix", prixDouble);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Event added successfully!");
        showEvennements();
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to add event to the database.");
    }
}


void GEvennement::on_pushButton_Ajouter_clicked()
{
    qDebug() << "on_pushButton_Ajouter_clicked called";

    // Get the values from the input fields
    QString nom = ui->line_NOMevent->text().trimmed();
    QString capacite = ui->line_CAPACITEevent->text().trimmed();
    QString type = ui->line_TYPEevent->text().trimmed();
    QString prix = ui->line_PRIXevent->text().trimmed();
    QDate dateDebut = ui->dateEditDebut->date();
    QDate dateFin = ui->dateEditFin->date();
    QString lieu = ui->line_LIEU->text().trimmed();

    // Call the ajout() method to insert the event
    ajout(nom, capacite, type, prix, dateDebut, dateFin, lieu);
    return;
}





void GEvennement::supprimer(const QString& nom)
{
    qDebug() << "supprimer method called with nom:" << nom;

    // Check if the name is empty
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a name to delete.");
        return;
    }

    // Prepare the DELETE query to remove the event by its name
    QSqlQuery query;
    query.prepare("DELETE FROM EVENEMENTS WHERE NOM = :nom");

    // Bind the 'nom' parameter to the value passed to the function
    query.bindValue(":nom", nom);

    // Execute the query to delete the event
    if (query.exec()) {
        // Inform the user if the deletion was successful
     //   QMessageBox::information(this, "Success", "Event deleted successfully.");

        // Optionally, refresh the list view to show the updated event list
        showEvennements();
    } else {
        // If the query fails, show an error message with the error text
        QMessageBox::critical(this, "Error", "Failed to delete the event: " + query.lastError().text());
    }
}

void GEvennement::on_pushButton_Supprimer_clicked()
{
    QString nom = ui->Line_DeleteID->text().trimmed(); // Get the name from the input field
    supprimer(nom); // Call the supprimer method
}




void GEvennement::on_listView_clicked(const QModelIndex &index)
{
    // Get the full text of the selected item
    QString selectedItem = ui->listView->model()->data(index).toString();

    qDebug() << "Selected Item: " << selectedItem; // Debugging: output the selected item to check its format

    // Assuming the selected item contains all the relevant columns (like NOM, TYPE, DATE_DEBUT, etc.)
    QStringList itemData = selectedItem.split(" | ");

    // Debugging: check the size and content of the split data
    qDebug() << "Item Data Size: " << itemData.size();
    for (const QString &data : itemData) {
        qDebug() << "Data: " << data;
    }

    if (itemData.size() < 7) {
        // Ensure we have all the expected fields
        QMessageBox::warning(this, "Error", "Invalid selection format.");
        return;
    }

    // Extract the event's details from the selected item
    QString nom = itemData.at(0); // NOM (first column)
    QString type = itemData.at(1); // TYPE (second column)
    QString dateDebut = itemData.at(2); // DATE_DEBUT (third column)
    QString dateFin = itemData.at(3); // DATE_FIN (fourth column)
    QString lieu = itemData.at(4); // LIEU (fifth column)
    QString capacite = itemData.at(5); // CAPACITE (sixth column)
    QString prix = itemData.at(6); // PRIX (seventh column)

    // Debugging: check if the extracted data is correct
    qDebug() << "Extracted Data:";
    qDebug() << "Nom: " << nom;
    qDebug() << "Type: " << type;
    qDebug() << "Date Debut: " << dateDebut;
    qDebug() << "Date Fin: " << dateFin;
    qDebug() << "Lieu: " << lieu;
    qDebug() << "Capacite: " << capacite;
    qDebug() << "Prix: " << prix;

    // Now, populate the input fields with the selected event data
    ui->line_NOMevent->setText(nom);
    ui->line_TYPEevent->setText(type);
    ui->dateEditDebut->setDate(QDate::fromString(dateDebut, "yyyy-MM-dd"));
    ui->dateEditFin->setDate(QDate::fromString(dateFin, "yyyy-MM-dd"));
    ui->line_LIEU->setText(lieu);
    ui->line_CAPACITEevent->setText(capacite);
    ui->line_PRIXevent->setText(prix);

    // Store the selected event's name or any unique identifier (e.g., NOM) for further use (e.g., for updating)
    selectedEventNom = nom; // Save the selected event's NOM to use it in the modification/update process
}

void GEvennement::modifier(const QString& nom, const QString& capacite, const QString& type,
                           const QString& prix, const QDate& dateDebut, const QDate& dateFin, const QString& lieu)
{
    // Prepare the SQL query to update the event in the database
    QSqlQuery query;
    query.prepare("UPDATE EVENEMENTS SET NOM = :nom, TYPE = :type, DATE_DEBUT = TO_DATE(:date_debut, 'YYYY-MM-DD'), "
                  "DATE_FIN = TO_DATE(:date_fin, 'YYYY-MM-DD'), LIEU = :lieu, CAPACITE = :capacite, PRIX = :prix "
                  "WHERE NOM = :selected_nom");

    // Bind the values to the query
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":date_debut", dateDebut.toString("yyyy-MM-dd"));
    query.bindValue(":date_fin", dateFin.toString("yyyy-MM-dd"));
    query.bindValue(":lieu", lieu);
    query.bindValue(":capacite", capacite.toInt());
    query.bindValue(":prix", prix.toFloat());
    query.bindValue(":selected_nom", nom); // Assuming you're modifying by the original name

    // Execute the query to update the event in the database
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Event updated successfully.");
        showEvennements();  // Refresh the event list to reflect the changes
    } else {
        QMessageBox::critical(this, "Error", "Failed to update the event: " + query.lastError().text());
    }
}

void GEvennement::on_pushButton_Modifier_clicked()
{
    // Get the values from the input fields
    QString nom = ui->line_NOMevent->text().trimmed();
    QString capacite = ui->line_CAPACITEevent->text().trimmed();
    QString type = ui->line_TYPEevent->text().trimmed();
    QString prix = ui->line_PRIXevent->text().trimmed();
    QDate dateDebut = ui->dateEditDebut->date();
    QDate dateFin = ui->dateEditFin->date();
    QString lieu = ui->line_LIEU->text().trimmed();

    // Check if the required fields are not empty
    if (nom.isEmpty() || capacite.isEmpty() || type.isEmpty() || prix.isEmpty() || lieu.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields to modify the event.");
        return;
    }

    // Call the modifier() method with the updated values
    modifier(nom, capacite, type, prix, dateDebut, dateFin, lieu);
}


void GEvennement::onSearchInitiated()
{
    // Get the text from the search bar for the event name (NOM)
    QString nom = ui->searchBar->text();  // Assuming you have a search bar for NOM (QLineEdit)

    // Prepare the SQL query to search by NOM
    QString queryStr = "SELECT NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX "
                       "FROM EVENEMENTS "
                       "WHERE NOM LIKE :nom";  // Search by NOM

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":nom", nom.isEmpty() ? "%" : "%" + nom + "%");  // Use LIKE for partial matching

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError();
        return;
    }

    // Create a QStandardItemModel to display the results in the listView
    QStandardItemModel *model = new QStandardItemModel();

    // Loop through the query results and add each row to the model
    while (query.next()) {
        QString eventString = query.value(0).toString() + " | "  // NOM
                              + query.value(1).toString() + " | "  // TYPE
                              + query.value(2).toString() + " | "  // DATE_DEBUT
                              + query.value(3).toString() + " | "  // DATE_FIN
                              + query.value(4).toString() + " | "  // LIEU
                              + query.value(5).toString() + " | "  // CAPACITE
                              + query.value(6).toString();         // PRIX

        // Add the formatted event string to the model as a new item
        QStandardItem *item = new QStandardItem(eventString);
        model->appendRow(item);
    }

    // Set the model to the ListView widget
    ui->listView->setModel(model);
    qDebug() << "Setting model to listView...";
}


void GEvennement::onSortChanged(int index)
{
    // Determine the sort order based on the selected item
    QString sortOrder = (index == 0) ? "ASC" : "DESC";  // "Low to High" is ASC, "High to Low" is DESC

    // Prepare the SQL query to sort by CAPACITE
    QString queryStr = QString("SELECT NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX "
                               "FROM EVENEMENTS "
                               "ORDER BY CAPACITE %1").arg(sortOrder);  // Sorting by CAPACITE

    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Query failed:" << query.lastError();
        return;
    }

    // Create a QStandardItemModel to display the sorted results
    QStandardItemModel *model = new QStandardItemModel();

    // Loop through the query results and add each row to the model
    while (query.next()) {
        QString eventString = query.value(0).toString() + " | "  // NOM
                              + query.value(1).toString() + " | "  // TYPE
                              + query.value(2).toString() + " | "  // DATE_DEBUT
                              + query.value(3).toString() + " | "  // DATE_FIN
                              + query.value(4).toString() + " | "  // LIEU
                              + query.value(5).toString() + " | "  // CAPACITE
                              + query.value(6).toString();         // PRIX

        // Add the formatted event string to the model as a new item
        QStandardItem *item = new QStandardItem(eventString);
        model->appendRow(item);
    }

    // Set the model to the ListView widget
    ui->listView->setModel(model);
    qDebug() << "Setting sorted model to listView...";
}


void GEvennement::exportToPDF() {
    // Open a file dialog to choose the save location and file name
    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file name specified.");
        return;
    }

    // Create a QPrinter object to handle PDF generation
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Create a QPainter object to draw on the PDF
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(this, "Error", "Could not create PDF file.");
        return;
    }

    // Set up fonts
    QFont titleFont = painter.font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);

    QFont headerFont = painter.font();
    headerFont.setPointSize(12);
    headerFont.setBold(true);

    QFont dataFont = painter.font();
    dataFont.setPointSize(10);

    // Define margins and spacing
    int margin = 50;
    int yPos = margin;
    int lineHeight = 20;
    int columnWidth = 100;

    // Draw the title
    painter.setFont(titleFont);
    painter.drawText(margin, yPos, "Events Report");
    yPos += lineHeight * 2;

    // Draw the table headers
    painter.setFont(headerFont);
    painter.drawText(margin, yPos, "Name");
    painter.drawText(margin + columnWidth, yPos, "Type");
    painter.drawText(margin + 2 * columnWidth, yPos, "Start Date");
    painter.drawText(margin + 3 * columnWidth, yPos, "End Date");
    painter.drawText(margin + 4 * columnWidth, yPos, "Location");
    painter.drawText(margin + 5 * columnWidth, yPos, "Capacity");
    painter.drawText(margin + 6 * columnWidth, yPos, "Price");
    yPos += lineHeight;

    // Draw a line under the headers
    painter.drawLine(margin, yPos, margin + 7 * columnWidth, yPos);
    yPos += lineHeight;

    // Fetch data from the database
    QSqlQuery query;
    query.prepare("SELECT NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX FROM EVENEMENTS");
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to fetch data: " + query.lastError().text());
        return;
    }

    // Draw the data rows
    painter.setFont(dataFont);
    while (query.next()) {
        QString nom = query.value(0).toString(); // NOM
        QString type = query.value(1).toString(); // TYPE
        QString dateDebut = query.value(2).toDate().toString("yyyy-MM-dd"); // DATE_DEBUT
        QString dateFin = query.value(3).toDate().toString("yyyy-MM-dd"); // DATE_FIN
        QString lieu = query.value(4).toString(); // LIEU
        QString capacite = QString::number(query.value(5).toInt()); // CAPACITE
        QString prix = QString::number(query.value(6).toDouble(), 'f', 2); // PRIX

        // Draw each column
        painter.drawText(margin, yPos, nom);
        painter.drawText(margin + columnWidth, yPos, type);
        painter.drawText(margin + 2 * columnWidth, yPos, dateDebut);
        painter.drawText(margin + 3 * columnWidth, yPos, dateFin);
        painter.drawText(margin + 4 * columnWidth, yPos, lieu);
        painter.drawText(margin + 5 * columnWidth, yPos, capacite);
        painter.drawText(margin + 6 * columnWidth, yPos, prix);

        // Move to the next line
        yPos += lineHeight;

        // Draw a line between rows
        painter.drawLine(margin, yPos, margin + 7 * columnWidth, yPos);
        yPos += lineHeight;
    }

    // End the painting process
    painter.end();

    // Notify the user that the PDF has been created
    QMessageBox::information(this, "Success", "PDF exported successfully to " + fileName);
}



void GEvennement::on_pushButton_Statistique_clicked()
{
    showEventsChart();

}

