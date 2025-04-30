#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employee
{
private:
    QString ID_EMP, EMAIL, NOM, POSTE, EMBAUCHE, MDP, ID_EMPREINTE;
    int SALAIRE, TELEPHONE;

public:
    // Constructeur par défaut
    Employee()
    {
        ID_EMP = "";
        SALAIRE = 0;
        EMAIL = "";
        NOM = "";
        TELEPHONE = 0;
        POSTE = "";
        EMBAUCHE = "";
        MDP = "";
    }

    // Constructeur avec paramètres
    Employee(QString id, int salaire, QString email, QString nom, int telephone, QString poste,
             QString embauche, QString mdp)
    {
        ID_EMP = id;
        SALAIRE = salaire;
        EMAIL = email;
        NOM = nom;
        TELEPHONE = telephone;
        POSTE = poste;
        EMBAUCHE = embauche;
        MDP = mdp;
    }

    // Getters
    QString getID_EMP() { return ID_EMP; }
    QString getEMAIL() { return EMAIL; }
    QString getNOM() { return NOM; }
    QString getPOSTE() { return POSTE; }
    QString getEMBAUCHE() { return EMBAUCHE; }
    QString getMDP() { return MDP; }
    int getSALAIRE() { return SALAIRE; }
    int getTELEPHONE() { return TELEPHONE; }

    // Setters
    void setEMAIL(QString e) { EMAIL = e; }
    void setNOM(QString n) { NOM = n; }
    void setPOSTE(QString p) { POSTE = p; }
    void setEMBAUCHE(QString d) { EMBAUCHE = d; }
    void setMDP(QString m) { MDP = m; }
    void setSALAIRE(int s) { SALAIRE = s; }
    void setTELEPHONE(int t) { TELEPHONE = t; }

    // Méthodes
    bool ajouter();
    bool supprimer(QString);
    QSqlQueryModel *afficher();
    bool modifier(QString);
};

#endif // EMPLOYEE_H
