#include "boutique.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


Boutique::Boutique() : SURFACE(0), MONTANT(0) {}

Boutique::Boutique(QString nom, QString type, QString localisation,
                   double surface, double montant, QString etat, QString horaire) :
    NOM(nom), TYPE(type), LOCALISATION(localisation),
    SURFACE(surface), MONTANT(montant), ETAT(etat), HORAIRE(horaire) {}

bool Boutique::ajouter(const Boutique &b)
{
    QSqlQuery query;
    query.prepare("INSERT INTO boutiques (NOM, TYPE, LOCALISATION, SURFACE, MONTANT, ETAT, HORAIRE_OUVERTURE, ID_EMP, ID_LOCATAIRE) "
                  "VALUES (:nom, :type, :localisation, :surface, :montant, :etat, :horaire, :id_employe, :id_locataire)");
    query.bindValue(":nom", b.getNom());
    query.bindValue(":type", b.getType());
    query.bindValue(":localisation", b.getLocalisation());
    query.bindValue(":surface", b.getSurface());
    query.bindValue(":montant", b.getMontant());
    query.bindValue(":etat", b.getEtat());
    query.bindValue(":horaire", b.getHoraire());
    query.bindValue(":id_employe", b.getIdEmploye());
    query.bindValue(":id_locataire", b.getIdLocataire());

    return query.exec();
}

bool Boutique::modifier(const Boutique &b)
{
    QSqlQuery query;
    query.prepare("UPDATE boutiques SET NOM = :nom, TYPE = :type, LOCALISATION = :localisation, "
                  "SURFACE = :surface, MONTANT = :montant, ETAT = :etat, HORAIRE_OUVERTURE = :horaire, "
                  "ID_EMP = :id_employe, ID_LOCATAIRE = :id_locataire WHERE ID_BOUTIQUE = :id_boutique");
    query.bindValue(":id_boutique", b.getId());
    query.bindValue(":nom", b.getNom());
    query.bindValue(":type", b.getType());
    query.bindValue(":localisation", b.getLocalisation());
    query.bindValue(":surface", b.getSurface());
    query.bindValue(":montant", b.getMontant());
    query.bindValue(":etat", b.getEtat());
    query.bindValue(":horaire", b.getHoraire());
    query.bindValue(":id_employe", b.getIdEmploye());
    query.bindValue(":id_locataire", b.getIdLocataire());

    return query.exec();
}

bool Boutique::supprimer(const QString &id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM boutiques WHERE ID_BOUTIQUE = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QList<Boutique> Boutique::afficher()
{
    QList<Boutique> boutiques;
    QSqlQuery query("SELECT * FROM boutiques ORDER BY NOM");

    while (query.next()) {
        Boutique b;
        b.setId(query.value("ID_BOUTIQUE").toString());
        b.setNom(query.value("NOM").toString());
        b.setType(query.value("TYPE").toString());
        b.setLocalisation(query.value("LOCALISATION").toString());
        b.setSurface(query.value("SURFACE").toDouble());
        b.setMontant(query.value("MONTANT").toDouble());
        b.setEtat(query.value("ETAT").toString());
        b.setHoraire(query.value("HORAIRE_OUVERTURE").toString());
        b.setIdEmploye(query.value("ID_EMP").toString());
        b.setIdLocataire(query.value("ID_LOCATAIRE").toString());

        boutiques.append(b);
    }

    return boutiques;
}
Boutique Boutique::getById(QString id)
{
    Boutique b;
    QSqlQuery query;
    query.prepare("SELECT * FROM boutiques WHERE ID_BOUTIQUE = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        b.setId(query.value("ID_BOUTIQUE").toString());
        b.setNom(query.value("NOM").toString());
        b.setType(query.value("TYPE").toString());
        b.setLocalisation(query.value("LOCALISATION").toString());
        b.setSurface(query.value("SURFACE").toDouble());
        b.setMontant(query.value("MONTANT").toDouble());
        b.setEtat(query.value("ETAT").toString());
        b.setHoraire(query.value("HORAIRE_OUVERTURE").toString());
        b.setIdEmploye(query.value("ID_EMP").toString());
        b.setIdLocataire(query.value("ID_LOCATAIRE").toString());
    }

    return b;
}
