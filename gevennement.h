#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include "arduino.h"
#include <QMainWindow>
#include <QLabel>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QTimer>
#include <QMessageBox>
#include <QDialog>
#include <QQuickWidget>
#include <QGeoPositionInfoSource>
#include <QGeoServiceProvider>
#include <QQmlContext>
#include <QQmlEngine>
#include "evennement.h"
#include <QStandardItemModel>
#include "calendardialog.h" // Inclure le nouveau fichier d'en-tête

QT_BEGIN_NAMESPACE
namespace Ui
{
class GEvennement;
}
QT_END_NAMESPACE

class GEvennement : public QMainWindow
{
    Q_OBJECT

public:
    GEvennement(QWidget *parent = nullptr);
    ~GEvennement();

private slots:
    void update_label();

    void on_pushButton_Ajouter_clicked();
    void on_pushButton_Supprimer_clicked();
    void on_pushButton_Modifier_clicked();
    void on_pushButton_Modifier_2_clicked();
    void on_pushButton_Modifier_3_clicked();
    void on_pushButton_Rechercher_clicked();
    void on_pushButton_TriType_clicked();
    void on_pushButton_TriDate_clicked();
    void on_pushButton_Retreive_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_lineEdit_Recherche_textChanged(const QString &text);
    void on_pushButton_Dashboard_clicked();
    void on_pushButton_Employes_clicked();
    void on_pushButton_Boutiques_clicked();
    void on_pushButton_Locataires_clicked();
    void on_pushButton_Services_clicked();
    void on_pushButton_Evennements_clicked();
    void on_pushButton_deconnecter_clicked();
    void on_pushButton_PDF_clicked();
    void on_pushButton_Map_clicked();
    void onLocationSelected(double latitude, double longitude);
    void on_pushButton_Calendar_clicked(); // Nouveau slot pour le bouton du calendrier

private:
    Ui::GEvennement *ui; // UI pointer
    Evennement E;
    QStandardItemModel *model; // Changé de QSqlQueryModel à QStandardItemModel
    QQuickWidget *mapWidget;
    QString selectedEventNom;

    void setupUi();
    void generatePDF();
    QString formatDate(const QDateTime &date);
    void populateLocatairesComboBox();
    void initializeMap();

    QChart *createPieChart();
    void showPieChartDialog();
    void exportToPDF(const QModelIndex &index);
    QString tempValueVerif = "";
    QString humdValueVerif = "";
    QLabel* LABEL_temp = nullptr;
    QLabel* LABEL_hum = nullptr;


    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // GEVENNEMENT_H
