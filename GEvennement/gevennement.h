#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GEvennement;
}
QT_END_NAMESPACE

class GEvennement : public QMainWindow
{
    Q_OBJECT

public:
    GEvennement(QWidget *parent = nullptr);
    ~GEvennement();

private:
    Ui::GEvennement *ui;
};
#endif // GEVENNEMENT_H
