#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qnetworkaccessmanager.h"
#include "service.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Ajouter_clicked();
    void on_pushButton_Modifier_clicked();
    void on_pushButton_Supprimer_clicked();
    void on_pushButton_Afficher_clicked();
    void viderChamps();
    void on_pushButton_Rechercher_clicked();
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_pushButton_ExporterPDF_clicked();
    void on_comboBox_2_currentIndexChanged(int index);
    void on_pushButton_Historique_clicked();
    void sauvegarderHistoriqueDansFichier(QString id, QString action, QString ancienStatut, QString nouveauStatut);
    void sauvegarderHistoriqueSuppression(QString id, QString type, QString cible, QString statut, QString priorite);
    void on_pushButton_deconnecter_clicked();




    void on_pushButton_TestWebhook_clicked();

private:
    Ui::MainWindow *ui;
    Service service;  // Objet de la classe Service

    QNetworkAccessManager* manager;
    void envoyerNotification(QString id, QString statut, QString priorite, QString type, QString cible);

};

#endif // MAINWINDOW_H
