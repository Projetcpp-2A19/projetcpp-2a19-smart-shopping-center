#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include <QMainWindow>
#include "boutique.h"

namespace Ui {
class GEvennement;
}

class GEvennement : public QMainWindow
{
    Q_OBJECT

public:
    explicit GEvennement(QWidget *parent = nullptr);
    ~GEvennement();

private slots:
    void on_pushButton_Ajouter_clicked();
    void on_pushButton_Modifier_clicked();
    void on_pushButton_Supprimer_clicked();
    void on_tableWidget_Boutique_clicked(const QModelIndex &index);
    void on_pushButton_recherche_boutique_clicked();
    void on_pushButton_trier_boutiques_clicked();
    void on_pushButton_exporter_boutiques_clicked();

private:
    Ui::GEvennement *ui;
    void chargerBoutiques();
    void afficherBoutique(const Boutique &b);
    void viderFormulaire();
    Boutique lireFormulaire() const;

};

#endif // GEVENNEMENT_H
