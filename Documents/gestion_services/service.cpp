#include "service.h"
#include <QDebug>
#include <QSqlError>  // Inclure l'en-tête pour QSqlError

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
    QSqlQuery query;
    query.prepare("INSERT INTO SERVICES (ID_SERVICE, TYPE, CIBLE, STATUT, PRIORITE) "
                  "VALUES (:id, :type, :cible, :statut)");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":cible", cible);
    query.bindValue(":statut", statut);

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
    QSqlQuery query;
    query.prepare("UPDATE SERVICES SET TYPE=:type, COLUMN1=:cible, STATUT_PRIORITE=:statut "
                  "WHERE ID_SERVICE=:id");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":cible", cible);
    query.bindValue(":statut", statut);

    if (query.exec()) {
        qDebug() << "Service modifié avec succès !";
        return true;
    } else {
        qDebug() << "Erreur lors de la modification du service :" << query.lastError().text();
        return false;
    }
}

// Supprimer un service
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

// Afficher tous les services
QSqlQueryModel* Service::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SERVICES");
    return model;
}
