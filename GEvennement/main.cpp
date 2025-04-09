#include "gevennement.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Établir une connexion à la base de données
    Connection c;
    bool ok = c.createconnect();
    
    // Vérifier si la connexion à la base de données a réussi
    if (!ok) {
        QMessageBox::critical(nullptr, "Erreur de connexion", 
                             "Impossible de se connecter à la base de données.\n"
                             "Assurez-vous que le pilote ODBC est configuré correctement et que le service de base de données est en cours d'exécution.");
        return 1;
    }
    
    GEvennement w;
    w.show();
    return a.exec();
}
