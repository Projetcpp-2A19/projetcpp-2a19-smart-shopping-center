#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QPrintDialog>
#include <QTextDocument>
#include <QDateTime>
#include <QSqlQuery>
#include <QWidget>

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
    void on_pushButton_PDF_clicked();  // Pour la génération du PDF

private:
    Ui::GEvennement *ui;
    void generatePDF();  // Fonction pour générer le PDF
    QString formatDate(const QDateTime &date);  // Fonction pour formater la date
    void setupUi();  // Configuration de l'interface utilisateur
};

#endif // GEVENNEMENT_H 
