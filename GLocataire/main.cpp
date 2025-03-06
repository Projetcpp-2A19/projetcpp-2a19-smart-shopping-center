#include <QApplication>
#include "glocataires.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GLocataire w;  // Create the GLocataire window
    w.show();      // Show the window

    return a.exec();  // Start the event loop
}
