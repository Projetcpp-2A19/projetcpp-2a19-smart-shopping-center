#include "service.h"
#include <QDebug>
#include <QSqlError>

// Constructeurs
Service::Service() {}
Service::Service(QString id, QString type, QString cible, QString statut, QString priorite) {
    this->id = id;
    this->type = type;
    this->cible = cible;
    this->statut = statut;
    this->priorite = priorite;
}

// Getters
QString Service::getId() const { return id; }
QString Service::getType() const { return type; }
QString Service::getCible() const { return cible; }
QString Service::getStatut() const { return statut; }
QString Service::getPriorite() const { return priorite; }

// Setters
void Service::setId(QString id) { this->id = id; }
void Service::setType(QString type) { this->type = type; }
void Service::setCible(QString cible) { this->cible = cible; }
void Service::setStatut(QString statut) { this->statut = statut; }
void Service::setPriorite(QString priorite) { this->priorite = priorite; }

// Ajouter un service
bool Service::ajouter() {
    // Vérifier que l'ID n'existe pas déjà
    if (existeDeja(id)) {
        qDebug() << "Erreur : L'ID existe déjà !";
        return false;
    }

    // Vérifier que la priorité est un nombre valide entre 0 et 1
    bool ok;
    double prioriteDouble = priorite.toDouble(&ok);
    if (!ok || prioriteDouble < 0 || prioriteDouble > 1) { // Priorité entre 0 et 1
        qDebug() << "Erreur : La priorité doit être un nombre entre 0 et 1 !";
        return false;
    }

    // Vérifier que la cible est "enfant" ou "adulte"
    if (cible.toLower() != "enfant" && cible.toLower() != "adulte") {
        qDebug() << "Erreur : La cible doit être 'enfant' ou 'adulte' !";
        return false;
    }

    // Vérifier que le type est "homme" ou "femme"
    if (type.toLower() != "homme" && type.toLower() != "femme") {
        qDebug() << "Erreur : Le type doit être 'homme' ou 'femme' !";
        return false;
    }

    // Vérifier que le statut est 0 ou 1
    if (statut != "0" && statut != "1") {
        qDebug() << "Erreur : Le statut doit être 0 ou 1 !";
        return false;
    }

    // Exécuter la requête SQL
    QSqlQuery query;
    query.prepare("INSERT INTO SERVICES (ID_SERVICE, TYPE, CIBLE, STATUT, PRIORITE) "
                  "VALUES (:id, :type, :cible, :statut, :priorite)");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":cible", cible);
    query.bindValue(":statut", statut);
    query.bindValue(":priorite", priorite);

    if (query.exec()) {
        qDebug() << "Service ajouté avec succès !";
        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout du service :" << query.lastError().text();
        return false;
    }
}

// Modifier un service
bool Service::modifier(QString id) {
    // Vérifier que l'ID existe déjà
    if (!existeDeja(id)) {
        qDebug() << "Erreur : L'ID n'existe pas !";
        return false;
    }

    // Vérifier que la priorité est un nombre valide entre 0 et 1
    bool ok;
    double prioriteDouble = priorite.toDouble(&ok);
    if (!ok || prioriteDouble < 0 || prioriteDouble > 1) { // Priorité entre 0 et 1
        qDebug() << "Erreur : La priorité doit être un nombre entre 0 et 1 !";
        return false;
    }

    // Vérifier que la cible est "enfant" ou "adulte"
    if (cible.toLower() != "enfant" && cible.toLower() != "adulte") {
        qDebug() << "Erreur : La cible doit être 'enfant' ou 'adulte' !";
        return false;
    }

    // Vérifier que le type est "homme" ou "femme"
    if (type.toLower() != "homme" && type.toLower() != "femme") {
        qDebug() << "Erreur : Le type doit être 'homme' ou 'femme' !";
        return false;
    }

    // Vérifier que le statut est 0 ou 1
    if (statut != "0" && statut != "1") {
        qDebug() << "Erreur : Le statut doit être 0 ou 1 !";
        return false;
    }

    // Exécuter la requête SQL
    QSqlQuery query;
    query.prepare("UPDATE SERVICES SET TYPE=:type, CIBLE=:cible, STATUT=:statut, PRIORITE=:priorite "
                  "WHERE ID_SERVICE=:id");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":cible", cible);
    query.bindValue(":statut", statut);
    query.bindValue(":priorite", priorite);

    if (query.exec()) {
        qDebug() << "Service modifié avec succès !";
        return true;
    } else {
        qDebug() << "Erreur lors de la modification du service :" << query.lastError().text();
        return false;
    }
}

// Supprimer un service (méthode statique)
bool Service::supprimer(QString id) {
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICES WHERE ID_SERVICE=:id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Service supprimé avec succès !";
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression du service :" << query.lastError().text();
        return false;
    }
}

// Vérifier si un service existe déjà (méthode statique)
bool Service::existeDeja(QString id) {
    QSqlQuery query;
    query.prepare("SELECT ID_SERVICE FROM SERVICES WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return true; // L'ID existe déjà
    }
    return false; // L'ID n'existe pas
}

// Afficher tous les services (méthode statique)
QSqlQueryModel* Service::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SERVICES");
    return model;
}
QSqlQueryModel* Service::rechercherParId(QString id) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM SERVICES WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);
    query.exec();
    model->setQuery(std::move(query));
    return model;
}
QSqlQueryModel* Service::trierParPriorite() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SERVICES ORDER BY PRIORITE DESC");
    return model;
}
QSqlQueryModel* Service::statistiquesDemandes() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM STATS_DEMANDES ORDER BY NBR_DEMANDES DESC");
    return model;
}
void Service::enregistrerHistorique(QString id, QString action, QString ancienStatut, QString nouveauStatut)
{
    QSqlQuery query;
    query.prepare("INSERT INTO HISTORIQUE_SERVICES (ID_SERVICE, TYPE_ACTION, ANCIEN_STATUT, NOUVEAU_STATUT) "
                  "VALUES (:id, :action, :ancien, :nouveau)");
    query.bindValue(":id", id);
    query.bindValue(":action", action);
    query.bindValue(":ancien", ancienStatut);
    query.bindValue(":nouveau", nouveauStatut);
    query.exec();
}
QSqlQueryModel* Service::afficherHistorique()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM HISTORIQUE_SERVICES ORDER BY DATE_ACTION DESC");
    return model;
}


