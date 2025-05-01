#ifndef GEMPLOYE_H
#define GEMPLOYE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QSqlQueryModel>
#include "employee.h"
#include <QImage>
#include"glocataires.h"
QT_BEGIN_NAMESPACE
namespace Ui { class gemploye; }

QT_END_NAMESPACE

class gemploye : public QMainWindow
{
    Q_OBJECT

public:
    explicit gemploye(QWidget *parent = nullptr);
    ~gemploye();
    bool authentifierUtilisateur();
    bool ajouterIDDansBase(QString idEmp, int idEmpreinte);
    void authentifierParEmpreinte();

    QString lireEmpreinteDigitale();


private slots:
    void on_pushButton_ajouter_clicked();
    void afficher();

    void on_pushButton_afficher_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_Modifier_clicked();
    void on_pushButton_Extraire_clicked();
    void on_pushButton_rechercher_clicked();
    void on_pushButton_trier_clicked();
    void envoyerSMSCode(const QString &phoneNumber, const QString &resetCode);
    void on_pushButton_stats_clicked();

    void showMessage(const QString& title, const QString& message, QMessageBox::Icon icon);
    void on_pushButton_ajouter_id_empreinte_clicked();





    void on_pushButton_Locataires_clicked();

    void on_pushButton_Evennements_clicked();

    void on_pushButton_Boutiques_clicked();
private:
    Ui::gemploye *ui;
    Employee Etmp; // Objet employé
    void loadImages(); // Charger les images (photo et logo)
};

#endif // GEMPLOYE_H
