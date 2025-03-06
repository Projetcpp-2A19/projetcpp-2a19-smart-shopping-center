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
    connect(ui->pushButton_Supprimer, SIGNAL(clicked()), this, SLOT(on_pushButton_Supprimer_clicked()));
    connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_listView_clicked(QModelIndex)));
}

GEvennement::~GEvennement()
{
    // Clean up any allocated memory or resources if needed
    delete model;
    delete ui;
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

void GEvennement::on_pushButton_Ajouter_clicked()
{
    // Disable the button to prevent double-clicks
    ui->pushButton_Ajouter->setEnabled(false);

    // Get the values from the input fields
    QString nom = ui->line_NOMevent->text().trimmed(); // Trim whitespace
    QString capacite = ui->line_CAPACITEevent->text().trimmed();
    QString type = ui->line_TYPEevent->text().trimmed();
    QString prix = ui->line_PRIXevent->text().trimmed();
    QDate dateDebut = ui->dateEditDebut->date();
    QDate dateFin = ui->dateEditFin->date();
    QString lieu = ui->line_LIEU->text().trimmed(); // Get the LIEU value

    // Validate input (check if fields are empty first)
    if (nom.isEmpty() || capacite.isEmpty() || type.isEmpty() || prix.isEmpty() || lieu.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled.");
        ui->pushButton_Ajouter->setEnabled(true); // Re-enable button
        return;
    }

    // Ensure that "prix" and "capacite" are valid numbers
    bool isPrixValid, isCapaciteValid;
    double prixValue = prix.toDouble(&isPrixValid);
    int capaciteValue = capacite.toInt(&isCapaciteValid);

    if (!isPrixValid || !isCapaciteValid) {
        QMessageBox::warning(this, "Input Error", "Capacité and Prix must be valid numbers.");
        ui->pushButton_Ajouter->setEnabled(true);
        return;
    }

    // Ensure the start date is before the end date
    if (dateDebut > dateFin) {
        QMessageBox::warning(this, "Input Error", "The start date must be before the end date.");
        ui->pushButton_Ajouter->setEnabled(true);
        return;
    }

    // Check if the event already exists in the database (based on NOM and DATE_DEBUT)
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EVENEMENTS WHERE NOM = :nom AND DATE_DEBUT = :dateDebut");
    checkQuery.bindValue(":nom", nom);
    checkQuery.bindValue(":dateDebut", dateDebut);

    if (!checkQuery.exec()) {
        qDebug() << "Error checking for existing event: " << checkQuery.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to check for existing event.");
        ui->pushButton_Ajouter->setEnabled(true); // Re-enable button
        return;
    }

    if (checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Duplicate Entry", "This event already exists in the database.");
        ui->pushButton_Ajouter->setEnabled(true);
        return;
    }

    // Prepare the SQL query for inserting a new event (exclude ID_EVENT because it's auto-increment)
    QSqlQuery query;
    query.prepare("INSERT INTO EVENEMENTS (NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX) "
                  "VALUES (:nom, :type, TO_DATE(:dateDebut, 'YYYY-MM-DD'), TO_DATE(:dateFin, 'YYYY-MM-DD'), :lieu, :capacite, :prix)");

    // Bind the values to the query, but ensure the dates are in 'YYYY-MM-DD' format
    query.bindValue(":dateDebut", dateDebut.toString("yyyy-MM-dd"));
    query.bindValue(":dateFin", dateFin.toString("yyyy-MM-dd"));

    qDebug() << "Date Debut: " << dateDebut.toString("yyyy-MM-dd");
    qDebug() << "Date Fin: " << dateFin.toString("yyyy-MM-dd");

    // Bind the other parameters
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":lieu", lieu);
    query.bindValue(":capacite", capaciteValue);
    query.bindValue(":prix", prixValue);

    // Execute the query
    if (query.exec()) {
        qDebug() << "Event added successfully!";
        QMessageBox::information(this, "Success", "Event added successfully!");

        // Optionally, refresh the list view to show the newly added event
        showEvennements();
    } else {
        qDebug() << "Error adding event: " << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to add event to the database.");
    }

    // Re-enable the button after execution
    ui->pushButton_Ajouter->setEnabled(true);
}


void GEvennement::on_pushButton_Supprimer_clicked()
{
    // Get the name entered by the user in the Line_DeleteID field
    QString deletenom = ui->Line_DeleteID->text();

    // Check if the name field is empty
    if (deletenom.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a name to delete.");
        return;
    }

    // Prepare the DELETE query to remove the event by its name
    QSqlQuery query;
    query.prepare("DELETE FROM EVENEMENTS WHERE NOM = :nom");

    // Bind the 'nom' parameter to the value entered by the user
    query.bindValue(":nom", deletenom);

    // Execute the query to delete the event
    if (query.exec()) {
        // Inform the user if the deletion was successful
        QMessageBox::information(this, "Success", "Event deleted successfully.");

        // Optionally, refresh the list view to show the updated event list
        showEvennements();
    } else {
        // If the query fails, show an error message with the error text
        QMessageBox::critical(this, "Error", "Failed to delete the event: " + query.lastError().text());
    }
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

void GEvennement::on_pushButton_Modifier_clicked()
{
    // Get the values from the input fields
    QString nom = ui->line_NOMevent->text().trimmed();    // Trim whitespace
    QString capacite = ui->line_CAPACITEevent->text().trimmed();
    QString type = ui->line_TYPEevent->text().trimmed();
    QString prix = ui->line_PRIXevent->text().trimmed();
    QDate dateDebut = ui->dateEditDebut->date();
    QDate dateFin = ui->dateEditFin->date();
    QString lieu = ui->line_LIEU->text().trimmed();  // Get the LIEU value

    // Check if the required fields are not empty
    if (nom.isEmpty() || capacite.isEmpty() || type.isEmpty() || prix.isEmpty() || lieu.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields to modify the event.");
        return;
    }

    // Convert string values to appropriate types
    bool capaciteValid = false;
    int capaciteInt = capacite.toInt(&capaciteValid);  // Validate capacite as integer
    bool prixValid = false;
    float prixFloat = prix.toFloat(&prixValid);  // Validate prix as float

    // If capacite or prix is invalid, show an error message
    if (!capaciteValid || !prixValid) {
        QMessageBox::warning(this, "Input Error", "Invalid value for Capacite or Prix.");
        return;
    }

    // Get the selected event's name from the LineEdit
    QString selectedEventNom = ui->line_NOMevent->text().trimmed();  // Assuming you're modifying the current event

    // Format the date as string (Oracle expects YYYY-MM-DD)
    QString dateDebutStr = dateDebut.toString("yyyy-MM-dd");
    QString dateFinStr = dateFin.toString("yyyy-MM-dd");

    // Prepare the SQL query to update the event in the database
    QSqlQuery query;
    query.prepare("UPDATE EVENEMENTS SET NOM = :nom, TYPE = :type, DATE_DEBUT = TO_DATE(:date_debut, 'YYYY-MM-DD'), "
                  "DATE_FIN = TO_DATE(:date_fin, 'YYYY-MM-DD'), LIEU = :lieu, CAPACITE = :capacite, PRIX = :prix "
                  "WHERE NOM = :selected_nom");

    // Bind the values to the query
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":date_debut", dateDebutStr);
    query.bindValue(":date_fin", dateFinStr);
    query.bindValue(":lieu", lieu);
    query.bindValue(":capacite", capaciteInt);
    query.bindValue(":prix", prixFloat);
    query.bindValue(":selected_nom", selectedEventNom); // Assuming you're modifying by the original name

    // Execute the query to update the event in the database
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Event updated successfully.");
        showEvennements();  // Refresh the event list to reflect the changes
    } else {
        QMessageBox::critical(this, "Error", "Failed to update the event: " + query.lastError().text());
    }
}


