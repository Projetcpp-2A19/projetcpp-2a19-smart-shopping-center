#ifndef gboutique_H
#define gboutique_H

#include <QMainWindow>
#include "boutique.h"
#include <string>
#include <QSystemTrayIcon>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include "arduino.h"
#include <QRegularExpression>
#include <QMap>


namespace Ui {
class gboutique;
}

class gboutique : public QMainWindow
{
    Q_OBJECT

public:
    explicit gboutique(QWidget *parent = nullptr);
    ~gboutique();


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
    void on_pushButton_deconnecter_clicked();

private:
    Ui::gboutique *ui;
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
    void sendCommandToArduino(const QString &command);
    void checkLocataireExistence(const QString &idLocataire);
    void keyPressEvent(QKeyEvent *event);
    QList<Boutique> toutesBoutiques;
    QMap<QString, int> typeEncoding;
    QMap<QString, int> localisationEncoding;

    QVector<double> normaliserCaracteristiques(const Boutique& b);
    double calculerDistance(const Boutique& a, const Boutique& b);
    QList<Boutique> trouverVoisinsKNN(const Boutique& target, int k = 3);
    void afficherRecommandations();
    void initialiserEncodages();
    double calculerSimilarite(const Boutique& a, const Boutique& b);


};
#endif // gboutique_H
