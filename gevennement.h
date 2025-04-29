#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include <QMainWindow>
#include "boutique.h"
#include <string>
#include <QSystemTrayIcon>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include "arduino.h"
#include <QRegularExpression>


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
    void on_pushButton_Afficher_clicked();
    void on_pushButton_recherche_boutique_clicked();
    void on_pushButton_trier_boutiques_clicked();
    void on_pushButton_exporter_boutiques_clicked();
    void on_tableWidget_Boutique_clicked(const QModelIndex &index);
    void readFromArduino(); // Si vous utilisez l'héritage de QObject

private:
    Ui::GEvennement *ui;
    void chargerBoutiques();
    void afficherBoutique(const Boutique &b);
    void viderFormulaire();
    Boutique lireFormulaire() const;
    QSystemTrayIcon *trayIcon;
    QList<double> montants;
    void afficherStatistiquesEtatBoutiques();
    QChart *chart;
    QChartView *chartView;
    QPieSeries *series;
    void afficherHistogrammeMontants();
    Arduino *arduino; // Déclaration de l'objet Arduino
    void sendCommandToArduino(const QString &command);
    void checkLocataireExistence(const QString &idLocataire);
    void keyPressEvent(QKeyEvent *event);


};
#endif // GEVENNEMENT_H
