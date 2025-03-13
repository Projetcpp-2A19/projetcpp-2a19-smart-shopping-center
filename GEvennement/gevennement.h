#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include <QMainWindow>
#include <QLabel>
#include <QSqlQueryModel>


#include <QtCharts> // Include Qt Charts


QT_BEGIN_NAMESPACE
namespace Ui {
class GEvennement;
}
QT_END_NAMESPACE

class GEvennement : public QMainWindow
{
    Q_OBJECT

public:
    explicit GEvennement(QWidget *parent = nullptr);
    ~GEvennement();

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Supprimer_clicked();
    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_Modifier_clicked();


    void onSearchInitiated();
    void onSortChanged(int index);




    void on_pushButton_Statistique_clicked();

private:
    Ui::GEvennement *ui;  // UI pointer
    QSqlQueryModel *model; // SQL query model to handle event data

    // Function to display events in the list or table view
    void showEvennements();

    // This stores the name of the selected event (used for update/delete)
    QString selectedEventNom;

    // Declaration of the ajout() method
    void ajout(const QString& nom, const QString& capacite, const QString& type,
               const QString& prix, const QDate& dateDebut, const QDate& dateFin, const QString& lieu);

    void supprimer(const QString& nom);
    void modifier(const QString& nom, const QString& capacite, const QString& type,
                  const QString& prix, const QDate& dateDebut, const QDate& dateFin, const QString& lieu);


    void exportToPDF();

    int countEvents();
    void showEventsChart();


};

#endif // GEVENNEMENT_H
