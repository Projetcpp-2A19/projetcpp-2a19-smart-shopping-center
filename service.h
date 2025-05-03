#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Service {
public:
    // Constructeurs
    Service();
    Service(QString id, QString type, QString cible, QString statut, QString priorite);

    // Getters
    QString getId() const;
    QString getType() const;
    QString getCible() const;
    QString getStatut() const;
    QString getPriorite() const;

    // Setters
    void setId(QString id);
    void setType(QString type);
    void setCible(QString cible);
    void setStatut(QString statut);
    void setPriorite(QString priorite);

    // Méthodes pour interagir avec la base de données
    bool ajouter();
    bool modifier(QString id);

    // Méthodes statiques
    static bool supprimer(QString id);
    static bool existeDeja(QString id);
    static QSqlQueryModel* afficher();
    static QSqlQueryModel* rechercherParId(QString id);
    static QSqlQueryModel* trierParPriorite();
    static QSqlQueryModel* statistiquesDemandes();
    static void enregistrerHistorique(QString id, QString action, QString ancienStatut, QString nouveauStatut);
    static QSqlQueryModel* afficherHistorique();








private:
    QString id;
    QString type;
    QString cible;
    QString statut;
    QString priorite;
};

#endif // SERVICE_H
