#ifndef EVENNEMENT_H
#define EVENNEMENT_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>

class Evennement {
private:
    QString nom;
    QString capacite;
    QString type;
    QString prix;
    QDate dateDebut;
    QDate dateFin;
    QString lieu;
    QString ID_LOCATAIRE;
    QString IDENTIFIANT;
    
    bool verifierConnexion() const {
        if (!QSqlDatabase::database().isValid()) {
            qDebug() << "La connexion à la base de données n'est pas valide!";
            return false;
        }
        return true;
    }

public:
    // Constructors
    Evennement();
    Evennement(const QString& nom, const QString& capacite, const QString& type,
               const QString& prix, const QDate& dateDebut, const QDate& dateFin,
               const QString& lieu, const QString& idLocataire, const QString& identifiant);

    // Getters
    QString getNom() const;
    QString getCapacite() const;
    QString getType() const;
    QString getPrix() const;
    QDate getDateDebut() const;
    QDate getDateFin() const;
    QString getLieu() const;
    QString getIDLocataire() const;
    QString getIdentifiant() const;  // Added getter for IDENTIFIANT

    // Setters
    void setNom(const QString& nom);
    void setCapacite(const QString& capacite);
    void setType(const QString& type);
    void setPrix(const QString& prix);
    void setDateDebut(const QDate& dateDebut);
    void setDateFin(const QDate& dateFin);
    void setLieu(const QString& lieu);
    void setIDLocataire(const QString& idLocataire);
    void setIdentifiant(const QString& identifiant);  // Added setter for IDENTIFIANT

    // CRUD Methods
    void showEvennements(QTableView *tableView);

    QString toString() const;

    bool ajout(QString nom, QString capacite, QString type, QString prix, QDate dateDebut, QDate dateFin, QString lieu, QString idLocataire, QString IDENTIFIANT);

    bool supprimer(QString nom, QTableView *tableView);

    bool modifier(QString nom, QString nouveauNom, QString capacite, QString type,
                 QString prix, QDate dateDebut, QDate dateFin,
                 QString lieu, QString idLocataire);







};

#endif // EVENNEMENT_H
