#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QSqlQueryModel>
#include "employee.h"
#include <QImage>
#include"glocataires.h"
namespace Ui {
class dashboard;
}

class dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();
private slots:

    void on_pushButton_Locataires_clicked();

    void on_pushButton_Evennements_clicked();
    void on_pushButton_Employes_clicked();

    void on_pushButton_Boutiques_clicked();
    void on_pushButton_Services_clicked();


private:
    Ui::dashboard *ui;
};

#endif // DASHBOARD_H
