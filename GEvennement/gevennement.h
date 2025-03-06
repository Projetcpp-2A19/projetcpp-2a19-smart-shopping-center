#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include <QMainWindow>
#include <QLabel>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class GEvennement;
}
QT_END_NAMESPACE

class GEvennement : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor & Destructor
    explicit GEvennement(QWidget *parent = nullptr);
    ~GEvennement();

private slots:
    // Slot for the "Ajouter" button (add event)
    void on_pushButton_Ajouter_clicked();

    // Slot for the "Supprimer" button (delete event)
    void on_pushButton_Supprimer_clicked();

    // Slot for handling the event when a row is clicked in the list view
    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_Modifier_clicked();

private:
    Ui::GEvennement *ui;  // UI pointer
    QSqlQueryModel *model; // SQL query model to handle event data

    // Function to display events in the list or table view
    void showEvennements();

    // This stores the name of the selected event (used for update/delete)
    QString selectedEventNom;
};

#endif // GEVENNEMENT_H
