#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Service
{
public:
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

    // Méthodes CRUD
    bool ajouter();
    bool modifier(QString id);
    bool supprimer(QString id);
    static QSqlQueryModel* afficher();

private:
    QString id;
    QString type;
    QString cible;
    QString statut;
    QString priorite;
};

#endif // SERVICE_H
