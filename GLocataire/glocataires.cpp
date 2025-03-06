#include "glocataires.h"
#include "connection.h"
#include "ui_glocataires.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QStandardItemModel>
#include <QStandardItem>

GLocataire::GLocataire(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GLocataire), model(new QSqlQueryModel(this))
{
    ui->setupUi(this);

    // Create a Connection object to verify the database connection
    Connection conn;

    // Check if the database connection is successful
    if (!conn.createconnect()) {
        qDebug() << "Database connection failed!";
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
        return;  // Exit the constructor if the connection fails
    }

    // If the connection is successful, proceed to display the data in the list view
    qDebug() << "Database connected successfully!";

    // Call the method to show locataires from the database
    showLocataires();

    connect(ui->pushButton_Ajouter, &QPushButton::clicked, this, &GLocataire::on_pushButton_Ajouter_clicked);
    connect(ui->pushButton_Supprimer, &QPushButton::clicked, this, &GLocataire::on_pushButton_Supprimer_clicked);
    connect(ui->pushButton_Modifier, &QPushButton::clicked, this, &GLocataire::on_pushButton_Modifier_clicked);
    connect(ui->listView, &QListView::clicked, this, &GLocataire::on_listView_clicked);
}

GLocataire::~GLocataire()
{
    delete ui;
}

void GLocataire::showLocataires()
{
    qDebug() << "Fetching locataires data...";

    QSqlQuery query;
    query.prepare("SELECT NOM, TEL, MAIL, CONTRAT, MONTANT_LOYER, STATUT_PAIEMENT, TYPE_LOCATAIRE FROM LOCATAIRES");

    // Execute the query
    if (query.exec()) {
        qDebug() << "Query executed successfully!";

        // Create a QStandardItemModel for QListView
        QStandardItemModel *model = new QStandardItemModel();

        // Loop through the query results and add each row to the model
        while (query.next()) {
            // Create a string that combines the columns for this row
            QString locataireString = query.value(0).toString() + " | " + query.value(1).toString() + " | "
                                      + query.value(2).toString() + " | " + query.value(3).toString() + " | "
                                      + query.value(4).toString() + " | " + query.value(5).toString() + " | "
                                      + query.value(6).toString();

            // Add the formatted string to the model as a new item
            QStandardItem *item = new QStandardItem(locataireString);
            model->appendRow(item);
        }

        // Set the model to the ListView widget
        ui->listView->setModel(model);
        qDebug() << "Setting model to listView...";
    } else {
        qDebug() << "Query failed: " << query.lastError().text();
    }
}

void GLocataire::on_pushButton_Ajouter_clicked()
{
    // Disable the button to prevent double-clicks
    ui->pushButton_Ajouter->setEnabled(false);

    // Get the values from the input fields
    QString nom = ui->line_NOMLoc->text();
    QString tel = ui->line_CAPACITELoc->text();
    QString mail = ui->line_MAILLoc->text();
    QString contrat = ui->line_CONTRATLoc->text();
    QString statutPaiement = ui->line_Statut_PAIEMENTLoc->text();
    QString type = ui->line_TYPELoc->text();
    QString montantLoyer = ui->line_MONTANT_LOYERLOC->text();

    // Validate input (check if fields are empty)
    if (nom.isEmpty() || tel.isEmpty() || mail.isEmpty() || statutPaiement.isEmpty() || type.isEmpty() || montantLoyer.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled.");
        ui->pushButton_Ajouter->setEnabled(true); // Re-enable button
        return;
    }

    // Ensure that "montantLoyer" is a valid number
    bool isDouble;
    double montant = montantLoyer.toDouble(&isDouble);
    if (!isDouble) {
        QMessageBox::warning(this, "Input Error", "Montant Loyer must be a valid number.");
        ui->pushButton_Ajouter->setEnabled(true);
        return;
    }

    // Check if the locataire already exists in the database
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM LOCATAIRES WHERE NOM = :nom AND TEL = :tel");
    checkQuery.bindValue(":nom", nom);
    checkQuery.bindValue(":tel", tel);
    checkQuery.exec();

    if (checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Duplicate Entry", "This locataire already exists in the database.");
        ui->pushButton_Ajouter->setEnabled(true);
        return;
    }

    // Prepare the SQL query for inserting a new locataire (exclude ID because it's auto-increment)
    QSqlQuery query;
    query.prepare("INSERT INTO LOCATAIRES (NOM, TEL, MAIL, CONTRAT, MONTANT_LOYER, STATUT_PAIEMENT, TYPE_LOCATAIRE) "
                  "VALUES (:nom, :tel, :mail, :contrat, :montantLoyer, :statutPaiement, :type)");

    // Bind the values to the query
    query.bindValue(":nom", nom);
    query.bindValue(":tel", tel);
    query.bindValue(":mail", mail);
    query.bindValue(":contrat", contrat);
    query.bindValue(":montantLoyer", montant);  // Bind the valid double value
    query.bindValue(":statutPaiement", statutPaiement);
    query.bindValue(":type", type);

    // Execute the query
    if (query.exec()) {
        qDebug() << "Locataire added successfully!";
        QMessageBox::information(this, "Success", "Locataire added successfully!");

        // Optionally, refresh the list view to show the newly added locataire
        showLocataires();
    } else {
        qDebug() << "Error adding locataire: " << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to add locataire to the database.");
    }

    // Re-enable the button after execution
    ui->pushButton_Ajouter->setEnabled(true);
}

void GLocataire::on_pushButton_Supprimer_clicked()
{
    // Get the telephone number entered by the user in the Line_DeleteID field
    QString deleteTel = ui->Line_DeleteID->text();

    // Check if the telephone number is empty
    if (deleteTel.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a telephone number to delete.");
        return;
    }

    // Prepare the SQL query to delete the record with the given telephone number
    QSqlQuery query;
    query.prepare("DELETE FROM LOCATAIRES WHERE tel = :tel");

    // Bind the telephone number parameter
    query.bindValue(":tel", deleteTel);

    // Execute the query
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Record deleted successfully.");

        // Optionally, refresh the list view to show the newly added locataire
        showLocataires();

    } else {
        QMessageBox::critical(this, "Error", "Failed to delete the record: " + query.lastError().text());
    }
}

void GLocataire::on_listView_clicked(const QModelIndex &index)
{
    // Get the text or data from the selected item (modify as per your data model)
    QString selectedItem = ui->listView->model()->data(index).toString();

    // Assuming the selected item contains the tel (or other identifier)
    // Here, we need to extract the `tel` (assuming it's the second column, adjust accordingly)

    // Split the selectedItem string to get the tel (as it's concatenated with other values)
    QStringList itemData = selectedItem.split(" | ");
    if (itemData.size() < 7) {
        QMessageBox::warning(this, "Error", "Invalid selection format.");
        return;
    }

    // The `tel` is assumed to be in the second position in the itemData list
    QString tel = itemData.at(1); // This assumes tel is the second field in the list

    // Fetch the corresponding data from the database using the tel
    QSqlQuery query;
    query.prepare("SELECT NOM, TEL, MAIL, CONTRAT, STATUT_PAIEMENT, TYPE_LOCATAIRE, MONTANT_LOYER "
                  "FROM LOCATAIRES WHERE TEL = :tel");
    query.bindValue(":tel", tel);  // Bind the tel to the query

    // Execute the query
    if (query.exec() && query.next()) {
        // Populate the input fields with the selected data
        ui->line_NOMLoc->setText(query.value(0).toString());
        ui->line_CAPACITELoc->setText(query.value(1).toString());
        ui->line_MAILLoc->setText(query.value(2).toString());
        ui->line_CONTRATLoc->setText(query.value(3).toString());
        ui->line_Statut_PAIEMENTLoc->setText(query.value(4).toString());
        ui->line_TYPELoc->setText(query.value(5).toString());
        ui->line_MONTANT_LOYERLOC->setText(query.value(6).toString());

        // Store tel for later use in the modify function
        selectedTel = tel;  // Set selectedTel to the tel from the database
    } else {
        // If the query does not return data
        QMessageBox::warning(this, "Error", "Item data not found.");
    }
}

void GLocataire::on_pushButton_Modifier_clicked()
{
    // Get the data from the input fields
    QString nom = ui->line_NOMLoc->text();
    QString tel = ui->line_CAPACITELoc->text();
    QString mail = ui->line_MAILLoc->text();
    QString contrat = ui->line_CONTRATLoc->text();
    QString statutPaiement = ui->line_Statut_PAIEMENTLoc->text();
    QString type = ui->line_TYPELoc->text();
    QString montantLoyer = ui->line_MONTANT_LOYERLOC->text();

    // Check if all fields are filled in
    if (nom.isEmpty() || tel.isEmpty() || mail.isEmpty() || contrat.isEmpty() ||
        statutPaiement.isEmpty() || type.isEmpty() || montantLoyer.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    // Convert montantLoyer to a valid number (optional step if necessary)
    bool ok;
    double montantLoyerDouble = montantLoyer.toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid number for the rent.");
        return;
    }

    // Prepare the SQL query to update the record based on the selected tel (unique identifier)
    QSqlQuery query;
    query.prepare("UPDATE LOCATAIRES SET NOM = :nom, TEL = :tel, MAIL = :mail, CONTRAT = :contrat, "
                  "STATUT_PAIEMENT = :statutPaiement, TYPE_LOCATAIRE = :type, MONTANT_LOYER = :montantLoyer "
                  "WHERE TEL = :selectedTel");

    // Bind the values
    query.bindValue(":nom", nom);
    query.bindValue(":tel", tel);
    query.bindValue(":mail", mail);
    query.bindValue(":contrat", contrat);
    query.bindValue(":statutPaiement", statutPaiement);
    query.bindValue(":type", type);
    query.bindValue(":montantLoyer", montantLoyerDouble);  // Bind as a double for number fields
    query.bindValue(":selectedTel", selectedTel);  // Use the stored selectedTel for the WHERE clause

    // Execute the update query
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Locataire updated successfully.");
        showLocataires();  // Optionally, refresh the list view
    } else {
        QMessageBox::critical(this, "Error", "Failed to update the locataire.");
    }
}
