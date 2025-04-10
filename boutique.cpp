#include "boutique.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Boutique::Boutique() : SURFACE(0), MONTANT(0) {}

Boutique::Boutique(QString nom, QString type, QString localisation,
                   double surface, double montant, QString etat, QString horaire) :
    NOM(nom), TYPE(type), LOCALISATION(localisation),
    SURFACE(surface), MONTANT(montant), ETAT(etat), HORAIRE(horaire) {}

bool Boutique::save()
{
    QSqlQuery query;

    if (ID_BOUTIQUE.isEmpty()) {
        // Insertion
        query.prepare("INSERT INTO boutiques (NOM, TYPE, LOCALISATION, SURFACE, MONTANT, ETAT, HORAIRE_OUVERTURE, ID_EMP, ID_LOCATAIRE) "
                      "VALUES (:nom, :type, :localisation, :surface, :montant, :etat, :horaire, :id_employe, :id_locataire)");
    } else {
        // Mise à jour
        query.prepare("UPDATE boutiques SET NOM = :nom, TYPE = :type, LOCALISATION = :localisation, "
                      "SURFACE = :surface, MONTANT = :montant, ETAT = :etat, HORAIRE_OUVERTURE = :horaire, "
                      "ID_EMP = :id_employe, ID_LOCATAIRE = :id_locataire WHERE id_boutique = :id_boutique");
        query.bindValue(":id_boutique", ID_BOUTIQUE);
    }

    query.bindValue(":nom", NOM);
    query.bindValue(":type", TYPE);
    query.bindValue(":localisation", LOCALISATION);
    query.bindValue(":surface", SURFACE);
    query.bindValue(":montant", MONTANT);
    query.bindValue(":etat", ETAT);
    query.bindValue(":horaire", HORAIRE);
    query.bindValue(":id_employe", ID_EMPLOYE); // Nouveau champ
    query.bindValue(":id_locataire", ID_LOCATAIRE); // Nouveau champ

    if (!query.exec()) {
        qDebug() << "Erreur lors de la sauvegarde:" << query.lastError().text();
        return false;
    }

    if (ID_BOUTIQUE.isEmpty()) {
        ID_BOUTIQUE = query.lastInsertId().toString();
    }

    return true;
}
bool Boutique::remove()
{
    if (ID_BOUTIQUE.isEmpty()) return false;

    QSqlQuery query;
    query.prepare("DELETE FROM boutiques WHERE ID_BOUTIQUE = :id");
    query.bindValue(":id", ID_BOUTIQUE);

    return query.exec();
}

QList<Boutique> Boutique::getAll()
{
    QList<Boutique> boutiques;
    QSqlQuery query("SELECT * FROM boutiques ORDER BY NOM");

    while (query.next()) {
        Boutique b;
        b.ID_BOUTIQUE = query.value("ID_BOUTIQUE").toString();
        b.NOM = query.value("NOM").toString();
        b.TYPE = query.value("TYPE").toString();
        b.LOCALISATION = query.value("LOCALISATION").toString();
        b.SURFACE = query.value("SURFACE").toDouble();
        b.MONTANT = query.value("MONTANT").toDouble();
        b.ETAT = query.value("ETAT").toString();
        b.HORAIRE = query.value("HORAIRE_OUVERTURE").toString();
        b.ID_EMPLOYE = query.value("ID_EMP").toString(); // Récupérer ID Employé
        b.ID_LOCATAIRE = query.value("ID_LOCATAIRE").toString(); // Récupérer ID Locataire

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
        b.ID_BOUTIQUE = query.value("ID_BOUTIQUE").toString();
        b.NOM = query.value("NOM").toString();
        b.TYPE = query.value("TYPE").toString();
        b.LOCALISATION = query.value("LOCALISATION").toString();
        b.SURFACE = query.value("SURFACE").toDouble();
        b.MONTANT = query.value("MONTANT").toDouble();
        b.ETAT = query.value("ETAT").toString();
        b.HORAIRE = query.value("HORAIRE_OUVERTURE").toString();
        b.ID_EMPLOYE = query.value("ID_EMP").toString(); // Récupérer ID Employé
        b.ID_LOCATAIRE = query.value("ID_LOCATAIRE").toString(); // Récupérer ID Locataire

    }

    return b;
}
