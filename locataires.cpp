#include "locataires.h"
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QHeaderView>

// Constructors
Locataires::Locataires() {}  // Default constructor

Locataires::Locataires(int identifiant, const QString &nom, const QString &tel, const QString &mail,
                       const QString &contrat, const QString &statutPaiement, const QString &typeLocataire, double montantLoyer)
    : identifiant(identifiant), nom(nom), tel(tel), mail(mail),
    contrat(contrat), statutPaiement(statutPaiement), typeLocataire(typeLocataire), montantLoyer(montantLoyer) {}




QStandardItemModel* Locataires::showLocataires(QTableView *tableView) {
    qDebug() << "Fetching locataires data...";

    // Create the model
    QStandardItemModel *model = new QStandardItemModel();

    // Set up the headers
    QStringList headers;
    headers << "ID" << "Nom" << "Téléphone" << "Email" << "Type" << "Loyer" << "Paiement" << "Contrat" << "Identifiant";
    model->setHorizontalHeaderLabels(headers);

    // Define the query
    QSqlQuery query;
    query.prepare("SELECT ID_LOCATAIRE, NOM, TEL, MAIL, TYPE_LOCATAIRE, MONTANT_LOYER, "
                  "STATUT_PAIEMENT, CONTRAT, IDENTIFIANT "
                  "FROM LOCATAIRES");

    // Execute the query
    if (query.exec()) {
        qDebug() << "Query executed successfully!";
        int row = 0;
        
        // Loop through the query results
        while (query.next()) {
            // Get values from query
            QString idLocataire = query.value("ID_LOCATAIRE").toString();
            QString nom = query.value("NOM").toString();
            QString tel = query.value("TEL").toString();
            QString mail = query.value("MAIL").toString();
            QString typeLocataire = query.value("TYPE_LOCATAIRE").toString();
            QString montantLoyer = query.value("MONTANT_LOYER").toString();
            QString statutPaiement = query.value("STATUT_PAIEMENT").toString();
            QString contrat = query.value("CONTRAT").toString();
            QString identifiant = query.value("IDENTIFIANT").toString();

            // Add data to model
            model->setItem(row, 0, new QStandardItem(idLocataire));
            model->setItem(row, 1, new QStandardItem(nom));
            model->setItem(row, 2, new QStandardItem(tel));
            model->setItem(row, 3, new QStandardItem(mail));
            model->setItem(row, 4, new QStandardItem(typeLocataire));
            model->setItem(row, 5, new QStandardItem(montantLoyer));
            model->setItem(row, 6, new QStandardItem(statutPaiement));
            model->setItem(row, 7, new QStandardItem(contrat));
            model->setItem(row, 8, new QStandardItem(identifiant));

            row++;
        }
    } else {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    }

    // Set model to table view
    tableView->setModel(model);
    
    // Configure the table view
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    return model;
}





// Getters
int Locataires::getIdentifiant() const {
    return identifiant;  // Return the class's identifiant (not IDENTIFIANT)
}

QString Locataires::getNom() const {
    return nom;
}

QString Locataires::getTel() const {
    return tel;
}

QString Locataires::getMail() const {
    return mail;
}

QString Locataires::getContrat() const {
    return contrat;
}

QString Locataires::getStatutPaiement() const {
    return statutPaiement;
}

QString Locataires::getTypeLocataire() const {
    return typeLocataire;
}

double Locataires::getMontantLoyer() const {
    return montantLoyer;  // Return double for montantLoyer
}

// Setters
void Locataires::setIdentifiant(int identifiant) {
    this->identifiant = identifiant;  // Set the class's identifiant to the input value
}

void Locataires::setNom(const QString &nom) {
    this->nom = nom;
}

void Locataires::setTel(const QString &tel) {
    this->tel = tel;
}

void Locataires::setMail(const QString &mail) {
    this->mail = mail;
}

void Locataires::setContrat(const QString &contrat) {
    this->contrat = contrat;
}

void Locataires::setStatutPaiement(const QString &statutPaiement) {
    this->statutPaiement = statutPaiement;
}

void Locataires::setTypeLocataire(const QString &typeLocataire) {
    this->typeLocataire = typeLocataire;
}

void Locataires::setMontantLoyer(double montantLoyer) {
    this->montantLoyer = montantLoyer;  // Set montantLoyer as a double
}




QString Locataires::toString() const {
    return QString("---------------------------\n"
                   "Locataire Details:\n"
                   "---------------------------\n"
                   "Identifiant:    %1\n"
                   "Nom:            %2\n"
                   "Téléphone:      %3\n"
                   "Statut Paiement: %4\n"
                   "Montant Loyer:  %5\n"
                   "Contrat:        %6\n"
                   "Type Locataire: %7\n"
                   "Email:          %8\n")
        .arg(identifiant)                      // First field: Identifiant
        .arg(nom)                              // Second field: Nom
        .arg(tel)                              // Third field: Téléphone
        .arg(statutPaiement)                   // Fourth field: Statut Paiement
        .arg(montantLoyer)                     // Fifth field: Montant Loyer
        .arg(contrat)                          // Sixth field: Contrat
        .arg(typeLocataire)                    // Seventh field: Type Locataire
        .arg(mail);                    // Ninth field: ID Locataire
}


bool Locataires::Ajout(int identifiant, const QString& nom, const QString& tel, const QString& mail,
                       const QString& contrat, const QString& statutPaiement, const QString& typeLocataire, double montantLoyer)
{
    if (nom.isEmpty() || tel.isEmpty() || mail.isEmpty()) {
        qDebug() << "Error: Required fields (NOM, TEL, MAIL) cannot be empty.";
        return false;
    }

    QSqlQuery query;

    // Prepare the SQL query for insertion
    query.prepare("INSERT INTO LOCATAIRES (IDENTIFIANT, NOM, TEL, MAIL, CONTRAT, STATUT_PAIEMENT, TYPE_LOCATAIRE, MONTANT_LOYER) "
                  "VALUES (:identifiant, :nom, :tel, :mail, :contrat, :statutPaiement, :typeLocataire, :montantLoyer)");

    // Bind values to the query
    query.bindValue(":identifiant", identifiant);
    query.bindValue(":nom", nom);
    query.bindValue(":tel", tel);
    query.bindValue(":mail", mail);
    query.bindValue(":contrat", contrat);
    query.bindValue(":statutPaiement", statutPaiement);
    query.bindValue(":typeLocataire", typeLocataire);
    query.bindValue(":montantLoyer", montantLoyer);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error inserting locataire: " << query.lastError();
        return false; // Return false if insertion fails
    }

    return true; // Return true if insertion is successful
}



bool Locataires::Supprimer(int identifiant)
{
    QSqlQuery query;

    // Prepare the SQL query for deletion based on the identifiant
    query.prepare("DELETE FROM LOCATAIRES WHERE IDENTIFIANT = :identifiant");

    // Bind the value for deletion (identifiant should be an integer)
    query.bindValue(":identifiant", identifiant);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error deleting locataire: " << query.lastError();
        return false; // Return false if deletion fails
    }

    return true; // Return true if deletion is successful
}


bool Locataires::modifier(const QString &identifiant, const QString &nom, const QString &tel,
                         const QString &mail, const QString &contrat, const QString &statutPaiement,
                         const QString &typeLocataire, const QString &montantLoyer)
{
    // Prepare the SQL query to update the locataire record
    QSqlQuery query;
    QString updateQuery = "UPDATE LOCATAIRES SET ";

    // Only update the fields that are provided (i.e., non-empty or modified fields)
    bool firstField = true;

    // Add NOM field if not empty
    if (!nom.isEmpty()) {
        if (!firstField) updateQuery += ", ";
        updateQuery += "NOM = :nom";
        firstField = false;
    }

    // Add TEL field if not empty
    if (!tel.isEmpty()) {
        if (!firstField) updateQuery += ", ";
        updateQuery += "TEL = :tel";
        firstField = false;
    }

    // Add MAIL field if not empty
    if (!mail.isEmpty()) {
        if (!firstField) updateQuery += ", ";
        updateQuery += "MAIL = :mail";
        firstField = false;
    }

    // Add CONTRAT field if not empty
    if (!contrat.isEmpty()) {
        if (!firstField) updateQuery += ", ";
        updateQuery += "CONTRAT = :contrat";
        firstField = false;
    }

    // Add STATUT_PAIEMENT field if not empty
    if (!statutPaiement.isEmpty()) {
        if (!firstField) updateQuery += ", ";
        updateQuery += "STATUT_PAIEMENT = :statutPaiement";
        firstField = false;
    }

    // Add TYPE_LOCATAIRE field if not empty
    if (!typeLocataire.isEmpty()) {
        if (!firstField) updateQuery += ", ";
        updateQuery += "TYPE_LOCATAIRE = :typeLocataire";
        firstField = false;
    }

    // Add MONTANT_LOYER field if not empty
    if (!montantLoyer.isEmpty()) {
        if (!firstField) updateQuery += ", ";
        updateQuery += "MONTANT_LOYER = :montantLoyer";
        firstField = false;
    }

    // If no fields are being updated, return false
    if (firstField) {
        qWarning() << "No fields to update.";
        return false;
    }

    // Add the WHERE clause for IDENTIFIANT
    updateQuery += " WHERE IDENTIFIANT = :identifiant";

    // Debug: Print the final query
    qDebug() << "Update Query:" << updateQuery;

    // Prepare the query
    if (!query.prepare(updateQuery)) {
        qCritical() << "Failed to prepare query:" << query.lastError().text();
        return false;
    }

    // Bind values to the query
    if (!nom.isEmpty()) query.bindValue(":nom", nom);
    if (!tel.isEmpty()) query.bindValue(":tel", tel);
    if (!mail.isEmpty()) query.bindValue(":mail", mail);
    if (!contrat.isEmpty()) query.bindValue(":contrat", contrat);
    if (!statutPaiement.isEmpty()) query.bindValue(":statutPaiement", statutPaiement);
    if (!typeLocataire.isEmpty()) query.bindValue(":typeLocataire", typeLocataire);
    if (!montantLoyer.isEmpty()) query.bindValue(":montantLoyer", montantLoyer);
    query.bindValue(":identifiant", identifiant);

    // Debug: Print bound values
    qDebug() << "Bound Values:";
    qDebug() << "NOM:" << nom;
    qDebug() << "TEL:" << tel;
    qDebug() << "MAIL:" << mail;
    qDebug() << "CONTRAT:" << contrat;
    qDebug() << "STATUT_PAIEMENT:" << statutPaiement;
    qDebug() << "TYPE_LOCATAIRE:" << typeLocataire;
    qDebug() << "MONTANT_LOYER:" << montantLoyer;
    qDebug() << "IDENTIFIANT:" << identifiant;

    // Execute the query
    if (query.exec()) {
        qDebug() << "Locataire updated successfully!";
        return true;  // Success
    } else {
        qCritical() << "Failed to update locataire:" << query.lastError().text();
        return false;  // Failure
    }
}




bool Locataires::RetreiveData(int identifiant)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM LOCATAIRES WHERE IDENTIFIANT = :identifiant");
    query.bindValue(":identifiant", identifiant);

    if (!query.exec() || !query.next()) {
        return false;  // Return false if locataire not found
    }

    // Fill the object with the retrieved data
    this->identifiant = query.value("IDENTIFIANT").toInt();
    this->nom = query.value("NOM").toString();
    this->tel = query.value("TEL").toString();
    this->mail = query.value("MAIL").toString();
    this->contrat = query.value("CONTRAT").toString();
    this->statutPaiement = query.value("STATUT_PAIEMENT").toString();
    this->typeLocataire = query.value("TYPE_LOCATAIRE").toString();
    this->montantLoyer = query.value("MONTANT_LOYER").toDouble();

    return true;
}
