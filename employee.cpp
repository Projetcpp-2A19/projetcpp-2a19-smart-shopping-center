#include "employee.h"
#include <QBuffer>
#include <QSqlQuery>
#include <QImage>

// Modification de la fonction ajouter pour inclure la photo
bool Employee::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO employes (ID_EMP, SALAIRE, EMAIL, NOM, TELEPHONE, POSTE, EMBAUCHE, MDP) "
                  "VALUES (:id, :salaire, :email, :nom, :telephone, :poste, :embauche, :mdp )");
    query.bindValue(":id", ID_EMP);
    query.bindValue(":salaire", SALAIRE);
    query.bindValue(":email", EMAIL);
    query.bindValue(":nom", NOM);
    query.bindValue(":telephone", TELEPHONE);
    query.bindValue(":poste", POSTE);
    query.bindValue(":embauche", EMBAUCHE);
    query.bindValue(":mdp", MDP);

    // Convertir l'image en QByteArray pour la stocker dans la base de données

    return query.exec();  // Exécuter la requête SQL
}




bool Employee::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM employes WHERE ID_EMP = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel *Employee::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employes");
    return model;
}

bool Employee::modifier(QString id)
{
    QSqlQuery query;
    query.prepare("UPDATE employes SET SALAIRE=:salaire, EMAIL=:email, NOM=:nom, "
                  "TELEPHONE=:telephone, POSTE=:poste, EMBAUCHE=:embauche, MDP=:mdp "
                  "WHERE ID_EMP=:id");
    query.bindValue(":id", id);
    query.bindValue(":salaire", SALAIRE);
    query.bindValue(":email", EMAIL);
    query.bindValue(":nom", NOM);
    query.bindValue(":telephone", TELEPHONE);
    query.bindValue(":poste", POSTE);
    query.bindValue(":embauche", EMBAUCHE);
    query.bindValue(":mdp", MDP);

    return query.exec();
}
