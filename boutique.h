#ifndef BOUTIQUE_H
#define BOUTIQUE_H

#include <QString>
#include <QList>
#include <QSqlQuery>

class Boutique
{
private:
    QString ID_BOUTIQUE;      // Identifiant unique de la boutique
    QString NOM;              // Nom de la boutique
    QString TYPE;             // Type de la boutique
    QString LOCALISATION;     // Localisation de la boutique
    double SURFACE;           // Surface de la boutique
    double MONTANT;           // Montant associé à la boutique
    QString ETAT;             // État de la boutique
    QString HORAIRE;          // Horaire d'ouverture de la boutique
    QString ID_EMPLOYE; // Nouveau champ
    QString ID_LOCATAIRE; // Nouveau champ



public:
    // Constructeurs
    Boutique();
    Boutique(QString nom, QString type, QString localisation,
             double surface, double montant, QString etat, QString horaire);

    // Getters
    QString getId() const { return ID_BOUTIQUE; }
    QString getNom() const { return NOM; }
    QString getType() const { return TYPE; }
    QString getLocalisation() const { return LOCALISATION; }
    double getSurface() const { return SURFACE; }
    double getMontant() const { return MONTANT; }
    QString getEtat() const { return ETAT; }
    QString getHoraire() const { return HORAIRE; }
    QString getIdEmploye() const { return ID_EMPLOYE; }
    QString getIdLocataire() const { return ID_LOCATAIRE; }



    // Setters
    void setId(QString id) { ID_BOUTIQUE = id; }
    void setNom(QString nom) { NOM = nom; }
    void setType(QString type) { TYPE = type; }
    void setLocalisation(QString localisation) { LOCALISATION = localisation; }
    void setSurface(double surface) { SURFACE = surface; }
    void setMontant(double montant) { MONTANT = montant; }
    void setEtat(QString etat) { ETAT = etat; }
    void setHoraire(QString horaire) { HORAIRE = horaire; }
    void setIdEmploye(const QString &id) { ID_EMPLOYE = id; }
    void setIdLocataire(const QString &id) { ID_LOCATAIRE = id; }

    // Méthodes CRUD
    bool save();
    bool remove();
    static QList<Boutique> getAll();
    static Boutique getById(QString id);
};

#endif // BOUTIQUE_H
