#ifndef GLOCATAIRES_H
#define GLOCATAIRES_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QLabel>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QTableView>
#include <QtCharts>
#include <QPdfWriter>
#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QInputDialog>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslConfiguration>
#include <QtNetwork/QSslCipher>
#include <QtNetwork/QSslKey>
#include <QtNetwork/QSslCertificate>
#include <QtNetwork/QSslError>

#include "locataires.h"

#include "arduino.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class GLocataire;
}
QT_END_NAMESPACE

class GLocataire : public QMainWindow
{
    Q_OBJECT

public:
    GLocataire(QWidget *parent = nullptr);
    ~GLocataire();

    // Method to display locataire data
    void showLocataires();

    //CRUD
    void Ajout();
    void Supprimer();

    bool Modifier(const QString& identifiant, const QString& nom, const QString& tel, const QString& mail,
                  const QString& contrat, const QString& statutPaiement, const QString& type, double montantLoyer);

private slots:
    void on_pushButton_Ajouter_clicked();
    void on_pushButton_Supprimer_clicked();
    void on_pushButton_Modifier_clicked();
    void on_pushButton_Retreive_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_stat_clicked();
    void on_PDF_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void on_sortComboBox_currentIndexChanged(int index);
    void on_pushButton_ChatBot_clicked();
    void on_pushButton_Ouvrir_clicked();  // bouton pour déclencher l'ouverture du moteur si RFID=1
    void on_pushButton_deconnecter_clicked();


private:

    Ui::GLocataire *ui;
    Locataires L;
    QSqlQueryModel *model;
    QLabel *lbl_Image_Display;
    QLabel *lbl_Logo_Display;
    QString selectedTel;
    int identifiant;
    QNetworkAccessManager *networkManager;

    QByteArray data; // Pour stocker les données reçues de l'Arduino (utile pour update_label si besoin)

    void refreshTable();
    void populateFieldsFromSelection(const QModelIndex &index);
    void createPieChart();
    void exportToPDF();
    void filterLocataires(const QString &searchText);
    void sortLocataires(int sortOrder);
    QChart *statsChart;
    QChartView *chartView;
    QSortFilterProxyModel *proxyModel;
    bool locataireExists(int identifiant);
    void sendConfirmationEmail(const QString &recipientEmail, const QString &name);
};

#endif // GLOCATAIRES_H
