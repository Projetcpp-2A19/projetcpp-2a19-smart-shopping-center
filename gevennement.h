#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QSqlQueryModel>
#include "employee.h"
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class GEvennement; }
QT_END_NAMESPACE

class GEvennement : public QMainWindow
{
    Q_OBJECT

public:
    explicit GEvennement(QWidget *parent = nullptr);
    ~GEvennement();
    bool authentifierUtilisateur();



private slots:
    void on_pushButton_ajouter_clicked();
    void afficher();

    void on_pushButton_afficher_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_Modifier_clicked();
    void on_pushButton_Extraire_clicked();
    void on_pushButton_rechercher_clicked();
    void on_pushButton_trier_clicked();
    void motDePasseOublie();
    void envoyerSMSCode(const QString &phoneNumber, const QString &resetCode);




private:
    Ui::GEvennement *ui;
    Employee Etmp; // Objet employé
    void loadImages(); // Charger les images (photo et logo)
};

#endif // GEVENNEMENT_H
