#ifndef GLOCATAIRES_H
#define GLOCATAIRES_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QLabel>

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

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_Modifier_clicked();

private:
    Ui::GLocataire *ui;
    QSqlQueryModel *model;            // Model to fetch and hold data
    QLabel *lbl_Image_Display;        // Label for the main image
    QLabel *lbl_Logo_Display;         // Label for the logo
    QString selectedTel;  // This will store the tel for the selected item
};

#endif // GLOCATAIRES_H
