#include "evennement.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlError>  // Add this include for QSqlError
#include <QDebug>
#include <QSqlDatabase>
#include <QHeaderView>



// Constructors
Evennement::Evennement() {}

Evennement::Evennement(const QString& nom, const QString& capacite, const QString& type,
                       const QString& prix, const QDate& dateDebut, const QDate& dateFin,
                       const QString& lieu, const QString& idLocataire, const QString& identifiant)
    : nom(nom), capacite(capacite), type(type), prix(prix),
    dateDebut(dateDebut), dateFin(dateFin), lieu(lieu),
    ID_LOCATAIRE(idLocataire), IDENTIFIANT(identifiant) {}


// Getters
QString Evennement::getNom() const { return nom; }
QString Evennement::getCapacite() const { return capacite; }
QString Evennement::getType() const { return type; }
QString Evennement::getPrix() const { return prix; }
QDate Evennement::getDateDebut() const { return dateDebut; }
QDate Evennement::getDateFin() const { return dateFin; }
QString Evennement::getLieu() const { return lieu; }
QString Evennement::getIDLocataire() const { return ID_LOCATAIRE; }
QString Evennement::getIdentifiant() const { return IDENTIFIANT; }  // New getter


// Setters
void Evennement::setNom(const QString& nom) { this->nom = nom; }
void Evennement::setCapacite(const QString& capacite) { this->capacite = capacite; }
void Evennement::setType(const QString& type) { this->type = type; }
void Evennement::setPrix(const QString& prix) { this->prix = prix; }
void Evennement::setDateDebut(const QDate& dateDebut) { this->dateDebut = dateDebut; }
void Evennement::setDateFin(const QDate& dateFin) { this->dateFin = dateFin; }
void Evennement::setLieu(const QString& lieu) { this->lieu = lieu; }
void Evennement::setIDLocataire(const QString& idLocataire) { this->ID_LOCATAIRE = idLocataire; }
void Evennement::setIdentifiant(const QString& identifiant) { this->IDENTIFIANT = identifiant; }  // New setter





// CRUD Methods

void Evennement::showEvennements(QTableView *tableView)
{
    qDebug() << "Récupération des événements...";

    QSqlQuery query;
    query.prepare(
        "SELECT "
        "E.NOM, "
        "E.TYPE, "
        "E.DATE_DEBUT, "
        "E.DATE_FIN, "
        "E.LIEU, "
        "E.CAPACITE, "
        "E.PRIX, "
        "L.NOM as LOCATAIRE_NOM, "
        "E.IDENTIFIANT "
        "FROM eyk.EVENEMENTS E "
        "LEFT JOIN eyk.LOCATAIRES L ON E.ID_LOCATAIRE = L.ID_LOCATAIRE "
        "ORDER BY E.NOM"
        );

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur", "Impossible de récupérer les événements : " + query.lastError().text());
        return;
    }

    QStandardItemModel *model = new QStandardItemModel(tableView);

    // Configuration des en-têtes dans l'ordre demandé
    QStringList headers;
    headers << "Nom" << "Type" << "Date Début" << "Date Fin" << "Lieu" << "Capacité" << "Prix" << "Locataire" << "Identifiant";
    model->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        QList<QStandardItem*> rowItems;

        // Création des items dans l'ordre demandé
        rowItems << new QStandardItem(query.value("NOM").toString())
                 << new QStandardItem(query.value("TYPE").toString())
                 << new QStandardItem(query.value("DATE_DEBUT").toDate().toString("dd/MM/yyyy"))
                 << new QStandardItem(query.value("DATE_FIN").toDate().toString("dd/MM/yyyy"))
                 << new QStandardItem(query.value("LIEU").toString())
                 << new QStandardItem(query.value("CAPACITE").toString())
                 << new QStandardItem(query.value("PRIX").toString())
                 << new QStandardItem(query.value("LOCATAIRE_NOM").toString())
                 << new QStandardItem(query.value("IDENTIFIANT").toString());

        // Configuration des items
        for(int col = 0; col < rowItems.size(); ++col) {
            rowItems[col]->setTextAlignment(Qt::AlignCenter);
            rowItems[col]->setEditable(false);
            model->setItem(row, col, rowItems[col]);
        }
        row++;
    }

    // Configuration du tableau
    tableView->setModel(model);

    // Définir une largeur spécifique pour chaque colonne
    QList<int> columnWidths = {150, 100, 100, 100, 150, 80, 80, 150, 100};
    for(int col = 0; col < columnWidths.size(); ++col) {
        tableView->setColumnWidth(col, columnWidths[col]);
    }

    // Configuration supplémentaire du tableau
    tableView->setSortingEnabled(true);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setAlternatingRowColors(true);
    tableView->verticalHeader()->setVisible(false);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->verticalHeader()->setDefaultSectionSize(30);

    qDebug() << "Affichage mis à jour avec" << row << "événements.";
}



QString Evennement::toString() const {
    return QString("---------------------------\n"
                   "Evennement Details:\n"
                   "---------------------------\n"
                   "Identifiant:   %1\n"
                   "Nom:           %2\n"
                   "Capacité:      %3\n"
                   "Type:          %4\n"
                   "Prix:          %5\n"
                   "Date de Début: %6\n"
                   "Date de Fin:   %7\n"
                   "Lieu:          %8\n"
                   "Locataire ID:  %9\n")
        .arg(IDENTIFIANT)                     // First field: Identifiant
        .arg(nom)                             // Second field: Nom
        .arg(capacite)                        // Third field: Capacité
        .arg(type)                            // Fourth field: Type
        .arg(prix)                            // Fifth field: Prix
        .arg(dateDebut.toString("yyyy-MM-dd")) // Sixth field: Date de Début
        .arg(dateFin.toString("yyyy-MM-dd"))   // Seventh field: Date de Fin
        .arg(lieu)                            // Eighth field: Lieu
        .arg(ID_LOCATAIRE);                    // Ninth field: Locataire ID
}




bool Evennement::ajout(QString nom, QString capacite, QString type, QString prix, QDate dateDebut, QDate dateFin, QString lieu, QString idLocataire, QString IDENTIFIANT)
{
    // Vérifier la connexion à la base de données
    if (!verifierConnexion()) {
        qDebug() << "Erreur: La base de données n'est pas accessible";
        return false;
    }

    // Validation des données
    bool conversionOk = false;
    int capaciteInt = capacite.toInt(&conversionOk);
    if (!conversionOk) {
        qDebug() << "Erreur: La capacité n'est pas un nombre valide";
        QMessageBox::warning(nullptr, "Erreur de validation", "La capacité doit être un nombre entier.");
        return false;
    }

    double prixDouble = prix.toDouble(&conversionOk);
    if (!conversionOk) {
        qDebug() << "Erreur: Le prix n'est pas un nombre valide";
        QMessageBox::warning(nullptr, "Erreur de validation", "Le prix doit être un nombre valide.");
        return false;
    }

    QSqlQuery query;
    // L'ordre des champs correspond exactement à l'ordre de la base de données
    // ID_EVENT est géré par un déclencheur (trigger) Oracle
    QString queryStr = "INSERT INTO eyk.EVENEMENTS (NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX, ID_LOCATAIRE, IDENTIFIANT) "
                       "VALUES (:nom, :type, :dateDebut, :dateFin, :lieu, :capacite, :prix, :idLocataire, :identifiant)";

    qDebug() << "Requête SQL à exécuter:" << queryStr;

    if (!query.prepare(queryStr)) {
        qDebug() << "Erreur lors de la préparation de la requête:" << query.lastError().text();
        return false;
    }

    // Lier les valeurs dans l'ordre des champs
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFin", dateFin);
    query.bindValue(":lieu", lieu);
    query.bindValue(":capacite", capaciteInt); // Utiliser la valeur convertie
    query.bindValue(":prix", prixDouble); // Utiliser la valeur convertie
    /*
    // Convertir ID_LOCATAIRE en nombre entier
    int idLocataireInt = idLocataire.toInt(&conversionOk);
    if (!conversionOk) {
        qDebug() << "Erreur: L'ID du locataire n'est pas un nombre valide";
        QMessageBox::warning(nullptr, "Erreur de validation", "L'ID du locataire doit être un nombre entier.");
        return false;
    }
*/
    int idLocataireInt = 63;

    query.bindValue(":idLocataire", idLocataireInt);
    query.bindValue(":identifiant", IDENTIFIANT);

    // Debug des valeurs finales
    qDebug() << "Valeurs finales à insérer:";
    qDebug() << "nom:" << nom;
    qDebug() << "type:" << type;
    qDebug() << "dateDebut:" << dateDebut;
    qDebug() << "dateFin:" << dateFin;
    qDebug() << "lieu:" << lieu;
    qDebug() << "capacite:" << capaciteInt;
    qDebug() << "prix:" << prixDouble;
    qDebug() << "idLocataire:" << idLocataireInt;
    qDebug() << "IDENTIFIANT:" << IDENTIFIANT;

    if (query.exec()) {
        qDebug() << "Evennement ajouté avec succès!";
        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout de l'événement:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur d'ajout", "Impossible d'ajouter l'événement: " + query.lastError().text());
        return false;
    }
}





bool Evennement::supprimer(QString nomOuId, QTableView *tableView)
{
    qDebug() << "Tentative de suppression de l'événement avec:" << nomOuId;

    // Vérifier la connexion à la base de données
    if (!verifierConnexion()) {
        QMessageBox::critical(nullptr, "Erreur", "La connexion à la base de données n'est pas disponible.");
        return false;
    }

    // Vérifier si le paramètre est vide
    if (nomOuId.isEmpty()) {
        QMessageBox::warning(nullptr, "Attention", "L'identifiant ou le nom de l'événement est vide.");
        return false;
    }

    // Essayer d'abord de rechercher par IDENTIFIANT
    QSqlQuery checkQuery;
    /*checkQuery.prepare("SELECT COUNT(*) FROM eyk.EVENEMENTS WHERE IDENTIFIANT = :id");
    checkQuery.bindValue(":id", nomOuId);

    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::warning(nullptr, "Attention", "Impossible de vérifier l'existence de l'événement.");
        return false;
    }
*/
    bool eventExists = checkQuery.value(0).toInt() > 0;

    // Si non trouvé par IDENTIFIANT, essayer par NOM
    QString whereClause;
    QString paramName;
    if (!eventExists) {
        checkQuery.prepare("SELECT COUNT(*) FROM eyk.EVENEMENTS WHERE NOM = :nom");
        checkQuery.bindValue(":nom", nomOuId);

        if (!checkQuery.exec() || !checkQuery.next()) {
            QMessageBox::warning(nullptr, "Attention", "Impossible de vérifier l'existence de l'événement.");
            return false;
        }

        eventExists = checkQuery.value(0).toInt() > 0;
        if (eventExists) {
            whereClause = "NOM = :valeur";
            paramName = "nom";
        } else {
            whereClause = "IDENTIFIANT = :valeur";
            paramName = "identifiant";
        }
    } else {
        whereClause = "IDENTIFIANT = :valeur";
        paramName = "identifiant";
    }

    if (!eventExists) {
        QMessageBox::warning(nullptr, "", "Aucun événement trouvé avec cet identifiant ou ce nom.");
        return false;
    }

    // Récupérer le nom de l'événement pour le message de confirmation
    QSqlQuery nameQuery;
    nameQuery.prepare("SELECT NOM FROM eyk.EVENEMENTS WHERE " + whereClause);
    nameQuery.bindValue(":valeur", nomOuId);

    QString eventName = nomOuId;
    if (nameQuery.exec() && nameQuery.next()) {
        eventName = nameQuery.value("NOM").toString();
    }

    // Demander confirmation à l'utilisateur
    QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "Confirmation",
                                                              QString("Voulez-vous vraiment supprimer l'événement '%1' ?").arg(eventName),
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return false;
    }

    // Préparer et exécuter la requête de suppression
    QSqlQuery query;
    query.prepare("DELETE FROM eyk.EVENEMENTS WHERE " + whereClause);
    query.bindValue(":valeur", nomOuId);

    if (query.exec()) {
        int affectedRows = query.numRowsAffected();
        if (affectedRows > 0) {
            qDebug() << "Événement supprimé avec succès, lignes affectées:" << affectedRows;
            QMessageBox::information(nullptr, "Succès", "L'événement a été supprimé avec succès.");

            // Rafraîchir l'affichage
            showEvennements(tableView);
            return true;
        } else {
            qDebug() << "Aucune ligne supprimée bien que la requête ait réussi";
            QMessageBox::warning(nullptr, "Attention", "Aucun événement n'a été supprimé.");
            return false;
        }
    } else {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur", "Impossible de supprimer l'événement : " + query.lastError().text());
        return false;
    }
}

bool Evennement::modifier(QString nom, QString nouveauNom, QString capacite, QString type,
                          QString prix, QDate dateDebut, QDate dateFin,
                          QString lieu, QString idLocataire)
{
    qDebug() << "Tentative de modification de l'événement avec le nom:" << nom;

    // Vérifier la connexion à la base de données
    if (!verifierConnexion()) {
        QMessageBox::critical(nullptr, "Erreur", "La connexion à la base de données n'est pas disponible.");
        return false;
    }

    // Vérifier si le nom est vide
    if (nom.isEmpty()) {
        QMessageBox::warning(nullptr, "Attention", "Le nom de l'événement est vide.");
        return false;
    }

    // Vérifier si l'événement existe
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM eyk.EVENEMENTS WHERE NOM = :nom");
    checkQuery.bindValue(":nom", nom);
    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::warning(nullptr, "Attention", "Impossible de vérifier l'existence de l'événement.");
        return false;
    }

    if (checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(nullptr, "Attention", "Aucun événement trouvé avec ce nom.");
        return false;
    }

    // Préparer la requête de modification selon l'ordre exact des champs dans la base
    QSqlQuery query;
    query.prepare(
        "UPDATE eyk.EVENEMENTS SET "
        "NOM = :nouveauNom, "
        "TYPE = :type, "
        "DATE_DEBUT = :dateDebut, "
        "DATE_FIN = :dateFin, "
        "LIEU = :lieu, "
        "CAPACITE = :capacite, "
        "PRIX = :prix, "
        "ID_LOCATAIRE = :idLocataire "
        "WHERE NOM = :nom"
        );

    // Lier les valeurs dans l'ordre des champs
    query.bindValue(":nom", nom);
    query.bindValue(":nouveauNom", nouveauNom);
    query.bindValue(":type", type);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFin", dateFin);
    query.bindValue(":lieu", lieu);
    query.bindValue(":capacite", capacite.toInt());
    query.bindValue(":prix", prix.toDouble());
    query.bindValue(":idLocataire", idLocataire.toInt());

    if (query.exec()) {
        qDebug() << "Événement modifié avec succès";
        QMessageBox::information(nullptr, "Succès", "L'événement a été modifié avec succès.");
        return true;
    } else {
        qDebug() << "Erreur lors de la modification:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur", "Impossible de modifier l'événement : " + query.lastError().text());
        return false;
    }
}

bool Evennement::modifierTempEtHumd(const QString& temp, const QString& humd, QLabel *LABEL_temp)
{
    QDate dateDuJour = QDate::currentDate();

    if (!verifierConnexion()) {
        QMessageBox::critical(nullptr, "Erreur", "Connexion à la base de données indisponible.");
        return false;
    }

    // Requête pour vérifier si un événement est en cours aujourd'hui
    QSqlQuery checkQuery;
    checkQuery.prepare(R"(
        SELECT NOM
        FROM eyk.EVENEMENTS
        WHERE :dateDuJour BETWEEN DATE_DEBUT AND DATE_FIN
    )");
    checkQuery.bindValue(":dateDuJour", dateDuJour);

    if (!checkQuery.exec() || !checkQuery.next()) {
        LABEL_temp->setText("Pas d'événement");
        return false;
    }

    QString nomEvenement = checkQuery.value(0).toString();

    // Mise à jour des valeurs de température et humidité
    QSqlQuery updateQuery;
    updateQuery.prepare(R"(
        UPDATE eyk.EVENEMENTS
        SET TEMP = :temp, HUMD = :humd
        WHERE :dateDuJour BETWEEN DATE_DEBUT AND DATE_FIN
    )");
    updateQuery.bindValue(":temp", temp);
    updateQuery.bindValue(":humd", humd);
    updateQuery.bindValue(":dateDuJour", dateDuJour);

    if (updateQuery.exec()) {
        if (updateQuery.numRowsAffected() > 0) {
            QString texte = "Événement : " + nomEvenement + "\nTempérature : " + temp + "\nHumidité : " + humd;
            LABEL_temp->setText(texte);
            return true;
        } else {
            LABEL_temp->setText("Pas d'événement");
            return false;
        }
    } else {
        qDebug() << "Erreur de mise à jour :" << updateQuery.lastError().text();
        LABEL_temp->setText("Erreur de mise à jour");
        return false;
    }
}
