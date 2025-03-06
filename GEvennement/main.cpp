#include "gevennement.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GEvennement w;
    w.show();
    return a.exec();
}
