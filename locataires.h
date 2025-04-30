#ifndef LOCATAIRES_H
#define LOCATAIRES_H

#include <QString>
#include <QStandardItemModel>
#include <QTableView>

class Locataires
{
public:
    // Default constructor
    Locataires();

    // Parametrized constructor
    Locataires(int identifiant, const QString &nom, const QString &tel, const QString &mail,
               const QString &contrat, const QString &statutPaiement, const QString &typeLocataire, double montantLoyer);

    // Method to display locataire data
    QStandardItemModel* showLocataires(QTableView *tableView);

    // CRUD Operations
    bool Ajout(int identifiant, const QString& nom, const QString& tel, const QString& mail,
               const QString& contrat, const QString& statutPaiement, const QString& typeLocataire, double montantLoyer);

    bool Supprimer(int identifiant);

    bool modifier(const QString &identifiant, const QString &nom, const QString &tel,
                              const QString &mail, const QString &contrat, const QString &statutPaiement,
                  const QString &typeLocataire, const QString &montantLoyer);

    bool RetreiveData(int identifiant);

    // Getters
    int getIdentifiant() const;
    QString getNom() const;
    QString getTel() const;
    QString getMail() const;
    QString getContrat() const;
    QString getStatutPaiement() const;
    QString getTypeLocataire() const;
    double getMontantLoyer() const;

    // Setters
    void setIdentifiant(int identifiant);
    void setNom(const QString &nom);
    void setTel(const QString &tel);
    void setMail(const QString &mail);
    void setContrat(const QString &contrat);
    void setStatutPaiement(const QString &statutPaiement);
    void setTypeLocataire(const QString &typeLocataire);
    void setMontantLoyer(double montantLoyer);

    // Convert object to string
    QString toString() const;

private:
    // Member variables
    int identifiant;
    QString nom;
    QString tel;
    QString mail;
    QString contrat;
    QString statutPaiement;
    QString typeLocataire;
    double montantLoyer;
};

#endif // LOCATAIRES_H
