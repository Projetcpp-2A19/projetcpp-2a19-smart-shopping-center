#ifndef GEVENNEMENT_H
#define GEVENNEMENT_H

#include <QMainWindow>
#include <QSqlDatabase>      // Pour gérer la connexion à la base de données
#include <QSqlQuery>         // Pour exécuter des requêtes SQL
#include <QSqlError>         // Pour gérer les erreurs SQL
#include <QMessageBox>       // Pour afficher des messages
#include <QTableWidgetItem>  // Pour gérer les éléments du QTableWidget

QT_BEGIN_NAMESPACE
namespace Ui {
class GEvennement;
}
QT_END_NAMESPACE

class GEvennement : public QMainWindow
{
    Q_OBJECT

public:
    GEvennement(QWidget *parent = nullptr); // Constructeur
    ~GEvennement(); // Destructeur

private slots:
    void on_pushButton_Ajouter_clicked(); // Slot pour le bouton "Ajouter"
    void loadBoutiques(); // Slot pour charger et afficher les boutiques
    void on_pushButton_Supprimer_clicked(); // Slot pour le bouton "Supprimer"
    void on_pushButton_Modifier_clicked(); // Slot pour le bouton "Modifier"
void on_tableWidget_Boutique_cellClicked(int row); // Supprimer 'int column'
private:
    Ui::GEvennement *ui; // Interface utilisateur
    QSqlDatabase db; // Objet pour gérer la connexion à la base de données
    int selectedBoutiqueId = -1; // ID de la boutique sélectionnée pour la modification
    void updateBoutique(int id); // Méthode pour mettre à jour une boutique
};

#endif // GEVENNEMENT_H
