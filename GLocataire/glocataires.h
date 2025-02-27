#ifndef GLOCATAIRES_H
#define GLOCATAIRES_H

#include <QMainWindow>

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

private:
    Ui::GLocataire *ui;
};
#endif // GLOCATAIRES_H
