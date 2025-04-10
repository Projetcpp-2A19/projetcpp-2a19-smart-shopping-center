#include "gevennement.h"
#include "ui_gevennement.h"
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>



GEvennement::GEvennement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GEvennement)
{
    ui->setupUi(this);
    connect(ui->pushButton_exporter_boutiques, &QPushButton::clicked, this, &GEvennement::on_pushButton_exporter_boutiques_clicked);



    // Configuration initiale
    ui->tableWidget_Boutique->setColumnCount(10);
    QStringList headers = {"ID", "Nom", "Type", "Localisation", "Surface", "Montant", "État", "Horaire", "ID_EMPLOYE", "ID_LOCATAIRE" };
    ui->tableWidget_Boutique->setHorizontalHeaderLabels(headers);

    chargerBoutiques();
}

GEvennement::~GEvennement()
{
    delete ui;
}

void GEvennement::chargerBoutiques()
{
    ui->tableWidget_Boutique->setRowCount(0);
    QList<Boutique> boutiques = Boutique::getAll();

    for (const Boutique &b : boutiques) {
        int row = ui->tableWidget_Boutique->rowCount();
        ui->tableWidget_Boutique->insertRow(row);

        ui->tableWidget_Boutique->setItem(row, 0, new QTableWidgetItem(b.getId()));
        ui->tableWidget_Boutique->setItem(row, 1, new QTableWidgetItem(b.getNom()));
        ui->tableWidget_Boutique->setItem(row, 2, new QTableWidgetItem(b.getType()));
        ui->tableWidget_Boutique->setItem(row, 3, new QTableWidgetItem(b.getLocalisation()));
        ui->tableWidget_Boutique->setItem(row, 4, new QTableWidgetItem(QString::number(b.getSurface())));
        ui->tableWidget_Boutique->setItem(row, 5, new QTableWidgetItem(QString::number(b.getMontant())));
        ui->tableWidget_Boutique->setItem(row, 6, new QTableWidgetItem(b.getEtat()));
        ui->tableWidget_Boutique->setItem(row, 7, new QTableWidgetItem(b.getHoraire()));
        ui->tableWidget_Boutique->setItem(row, 8, new QTableWidgetItem(b.getIdEmploye())); // ID Employé
        ui->tableWidget_Boutique->setItem(row, 9, new QTableWidgetItem(b.getIdLocataire())); // ID Locataire
    }
}

void GEvennement::afficherBoutique(const Boutique &b)
{
    ui->line_NOMboutique->setText(b.getNom());
    ui->line_TYPEboutique->setText(b.getType());
    ui->line_LOCALISATIONboutique->setText(b.getLocalisation());

    // Correction ici : Utiliser setText() pour QLineEdit
    ui->line_SURFACEboutique->setText(QString::number(b.getSurface()));
    ui->line_MONTANTboutique->setText(QString::number(b.getMontant()));

    ui->comboBox_ETATboutique->setCurrentText(b.getEtat());
    ui->timeEdit_HORAIRE->setTime(QTime::fromString(b.getHoraire()));
    ui->line_IDEMPboutique->setText(b.getIdEmploye());
    ui->line_IDLOCATAIREboutique->setText(b.getIdLocataire());
}

void GEvennement::viderFormulaire()
{
    ui->line_NOMboutique->clear();
    ui->line_TYPEboutique->clear();
    ui->line_LOCALISATIONboutique->clear();
    ui->line_SURFACEboutique->setText(0);
    ui->line_MONTANTboutique->setText(0);
    ui->comboBox_ETATboutique->setCurrentIndex(0);
    ui->timeEdit_HORAIRE->setTime(QTime(8,0));
    ui->line_IDEMPboutique->clear();            // Effacer le champ ID Employé
    ui->line_IDLOCATAIREboutique->clear();
}

Boutique GEvennement::lireFormulaire() const
{
    Boutique b;
    b.setNom(ui->line_NOMboutique->text().trimmed());
    b.setType(ui->line_TYPEboutique->text().trimmed());
    b.setLocalisation(ui->line_LOCALISATIONboutique->text().trimmed());
    b.setSurface(ui->line_SURFACEboutique->text().toDouble());
    b.setMontant(ui->line_MONTANTboutique->text().toDouble());
    b.setEtat(ui->comboBox_ETATboutique->currentText());
    b.setHoraire(ui->timeEdit_HORAIRE->time().toString("HH:mm")); // Format de l'heure
    b.setIdEmploye(ui->line_IDEMPboutique->text().trimmed()); // Nouveau champ
    b.setIdLocataire(ui->line_IDLOCATAIREboutique->text().trimmed()); // Nouveau champ

    return b;
}

void GEvennement::on_tableWidget_Boutique_clicked(const QModelIndex &index)
{
    QString id = ui->tableWidget_Boutique->item(index.row(), 0)->text();
    Boutique b = Boutique::getById(id);
    afficherBoutique(b);
}

void GEvennement::on_pushButton_Ajouter_clicked()
{
    Boutique b = lireFormulaire();
    QString errorMessage;

    // Vérification des champs vides
    if (b.getNom().isEmpty() || b.getType().isEmpty() || b.getLocalisation().isEmpty() || b.getIdEmploye().isEmpty() || b.getIdLocataire().isEmpty()) {
        errorMessage += "Veuillez remplir tous les champs obligatoires.\n";
    }

    // Vérification de la surface
    if (b.getSurface() <= 0) {
        errorMessage += "La surface doit être un chiffre positif.\n";
    }

    // Vérification du montant
    if (b.getMontant() <= 0) {
        errorMessage += "Le montant doit être un chiffre positif.\n";
    }
    bool isIdEmployeNumeric = QRegularExpression("^[0-9]+$").match(b.getIdEmploye()).hasMatch();
    if (!isIdEmployeNumeric) {
        errorMessage += "L'ID employé doit contenir uniquement des chiffres.\n";
    }

    // Vérification de l'ID locataire
    bool isIdLocataireNumeric = QRegularExpression("^[0-9]+$").match(b.getIdLocataire()).hasMatch();
    if (!isIdLocataireNumeric) {
        errorMessage += "L'ID locataire doit contenir uniquement des chiffres.\n";
    }

    // Si des erreurs ont été trouvées, afficher le message d'erreur
    if (!errorMessage.isEmpty()) {
        QMessageBox::warning(this, "Erreur", errorMessage);
        return;
    }

    // Validation du nom
    QRegularExpression nomRegex("^[a-zA-Z0-9]{3,}$"); // Minimum 3 caractères, lettres et chiffres
    if (!nomRegex.match(b.getNom()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom de la boutique doit contenir au minimum 3 lettres ou chiffres.");
        return;
    }

    // Validation du type (doit contenir uniquement des lettres)
    QRegularExpression typeRegex("^[a-zA-Z]{3,}$"); // Minimum 3 lettres
    if (!typeRegex.match(b.getType()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le type de la boutique doit contenir au minimum 3 lettres.");
        return;
    }

    if (b.save()) {
        QMessageBox::information(this, "Succès", "Boutique ajoutée avec succès");
        viderFormulaire(); // Efface le formulaire
        chargerBoutiques(); // Recharge la liste des boutiques
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de la boutique");
    }
}
void GEvennement::on_pushButton_Modifier_clicked()
{
    QModelIndex index = ui->tableWidget_Boutique->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une boutique à modifier.");
        return;
    }

    // Lire les données du formulaire
    Boutique b = lireFormulaire();
    QString errorMessage;

    // Vérification des champs vides
    if (b.getNom().isEmpty() || b.getType().isEmpty() || b.getLocalisation().isEmpty() ||
        b.getIdEmploye().isEmpty() || b.getIdLocataire().isEmpty()) {
        errorMessage += "Veuillez remplir tous les champs obligatoires.\n";
    }

    // Vérification de la surface
    if (b.getSurface() <= 0) {
        errorMessage += "La surface doit être un chiffre positif.\n";
    }

    // Vérification du montant
    if (b.getMontant() <= 0) {
        errorMessage += "Le montant doit être un chiffre positif.\n";
    }

    // Vérification de l'ID employé
    bool isIdEmployeNumeric = QRegularExpression("^[0-9]+$").match(b.getIdEmploye()).hasMatch();
    if (!isIdEmployeNumeric) {
        errorMessage += "L'ID employé doit contenir uniquement des chiffres.\n";
    }

    // Vérification de l'ID locataire
    bool isIdLocataireNumeric = QRegularExpression("^[0-9]+$").match(b.getIdLocataire()).hasMatch();
    if (!isIdLocataireNumeric) {
        errorMessage += "L'ID locataire doit contenir uniquement des chiffres.\n";
    }

    // Si des erreurs ont été trouvées, afficher le message d'erreur
    if (!errorMessage.isEmpty()) {
        QMessageBox::warning(this, "Erreur", errorMessage);
        return;
    }

    // Validation du nom
    QRegularExpression nomRegex("^[a-zA-Z0-9]{3,}$"); // Minimum 3 caractères, lettres et chiffres
    if (!nomRegex.match(b.getNom()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom de la boutique doit contenir au minimum 3 lettres ou chiffres.");
        return;
    }

    // Validation du type (doit contenir uniquement des lettres)
    QRegularExpression typeRegex("^[a-zA-Z]{3,}$"); // Minimum 3 lettres
    if (!typeRegex.match(b.getType()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le type de la boutique doit contenir au minimum 3 lettres.");
        return;
    }

    // Récupérer l'ID de la boutique à modifier
    b.setId(ui->tableWidget_Boutique->item(index.row(), 0)->text());

    // Appeler la méthode de modification
    if (b.save()) { // Assurez-vous que la méthode save() gère l'insertion et la mise à jour
        QMessageBox::information(this, "Succès", "Boutique modifiée avec succès");
        viderFormulaire(); // Efface le formulaire
        chargerBoutiques(); // Recharge la liste des boutiques
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de la boutique");
    }
}
void GEvennement::on_pushButton_Supprimer_clicked()
{
    QModelIndex index = ui->tableWidget_Boutique->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une boutique");
        return;
    }

    QString id = ui->tableWidget_Boutique->item(index.row(), 0)->text();
    Boutique b = Boutique::getById(id);

    if (QMessageBox::question(this, "Confirmation",
                              "Voulez-vous vraiment supprimer cette boutique ?") == QMessageBox::Yes) {
        if (b.remove()) {
            QMessageBox::information(this, "Succès", "Boutique supprimée avec succès");
            viderFormulaire();
            chargerBoutiques();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression");
        }
    }
}
void GEvennement::on_pushButton_recherche_boutique_clicked()
{
    QString rechercheId = ui->lineEdit_recherche_id->text().trimmed(); // Récupérer l'ID recherché

    if (rechercheId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID à rechercher.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM boutiques WHERE ID_BOUTIQUE = :id");
    query.bindValue(":id", rechercheId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'effectuer la recherche.");
        return;
    }

    ui->tableWidget_Boutique->clearContents();
    ui->tableWidget_Boutique->setRowCount(0);

    if (query.next()) {
        int row = 0;
        ui->tableWidget_Boutique->insertRow(row);
        ui->tableWidget_Boutique->setItem(row, 0, new QTableWidgetItem(query.value("ID_BOUTIQUE").toString()));
        ui->tableWidget_Boutique->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidget_Boutique->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableWidget_Boutique->setItem(row, 3, new QTableWidgetItem(query.value("LOCALISATION").toString()));
        ui->tableWidget_Boutique->setItem(row, 4, new QTableWidgetItem(query.value("SURFACE").toString()));
        ui->tableWidget_Boutique->setItem(row, 5, new QTableWidgetItem(query.value("MONTANT").toString()));
        ui->tableWidget_Boutique->setItem(row, 6, new QTableWidgetItem(query.value("ETAT").toString()));
        ui->tableWidget_Boutique->setItem(row, 7, new QTableWidgetItem(query.value("HORAIRE_OUVERTURE").toString()));
        ui->tableWidget_Boutique->setItem(row, 8, new QTableWidgetItem(query.value("ID_EMP").toString()));
        ui->tableWidget_Boutique->setItem(row, 9, new QTableWidgetItem(query.value("ID_LOCATAIRE").toString()));

    } else {
        QMessageBox::information(this, "Résultat", "Aucune boutique trouvée avec cet ID.");
    }
}
void GEvennement::on_pushButton_trier_boutiques_clicked()
{
    // Récupérer tous les boutiques
    QSqlQuery query;
    query.prepare("SELECT * FROM boutiques");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les boutiques.");
        return;
    }

    QList<QMap<QString, QVariant>> boutiques;

    while (query.next()) {
        QMap<QString, QVariant> boutique;
        boutique["ID_BOUTIQUE"] = query.value("ID_BOUTIQUE");
        boutique["NOM"] = query.value("NOM");
        boutique["TYPE"] = query.value("TYPE");
        boutique["LOCALISATION"] = query.value("LOCALISATION");
        boutique["SURFACE"] = query.value("SURFACE");
        boutique["MONTANT"] = query.value("MONTANT");
        boutique["ETAT"] = query.value("ETAT");
        boutique["HORAIRE_OUVERTURE"] = query.value("HORAIRE_OUVERTURE");
        boutique["ID_EMP"] = query.value("ID_EMP");
        boutique["ID_LOCATAIRE"] = query.value("ID_LOCATAIRE");


        boutiques.append(boutique);
    }

    // Trier la liste par nom
    std::sort(boutiques.begin(), boutiques.end(), [](const QMap<QString, QVariant>& a, const QMap<QString, QVariant>& b) {
        return a["NOM"].toString() < b["NOM"].toString();
    });

    // Vider le tableau avant de le remplir avec les boutiques triées
    ui->tableWidget_Boutique->clearContents();
    ui->tableWidget_Boutique->setRowCount(0);

    // Insérer les boutiques triées dans le tableau
    int row = 0;
    for (const auto& boutique : boutiques) {
        ui->tableWidget_Boutique->insertRow(row);
        ui->tableWidget_Boutique->setItem(row, 0, new QTableWidgetItem(boutique["ID_BOUTIQUE"].toString()));
        ui->tableWidget_Boutique->setItem(row, 1, new QTableWidgetItem(boutique["NOM"].toString()));
        ui->tableWidget_Boutique->setItem(row, 2, new QTableWidgetItem(boutique["TYPE"].toString()));
        ui->tableWidget_Boutique->setItem(row, 3, new QTableWidgetItem(boutique["LOCALISATION"].toString()));
        ui->tableWidget_Boutique->setItem(row, 4, new QTableWidgetItem(boutique["SURFACE"].toString()));
        ui->tableWidget_Boutique->setItem(row, 5, new QTableWidgetItem(boutique["MONTANT"].toString()));
        ui->tableWidget_Boutique->setItem(row, 6, new QTableWidgetItem(boutique["ETAT"].toString()));
        ui->tableWidget_Boutique->setItem(row, 7, new QTableWidgetItem(boutique["HORAIRE_OUVERTURE"].toString()));
        ui->tableWidget_Boutique->setItem(row, 8, new QTableWidgetItem(boutique["ID_EMP"].toString()));
        ui->tableWidget_Boutique->setItem(row, 9, new QTableWidgetItem(boutique["ID_LOCATAIRE"].toString()));

        row++;
    }

    QMessageBox::information(this, "Succès", "Les boutiques ont été triées par nom.");
}
void GEvennement::on_pushButton_exporter_boutiques_clicked()
{
    // Ouvrir la boîte de dialogue pour choisir le chemin du fichier
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    // Vérifier si l'utilisateur a sélectionné un chemin
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Aucun chemin de fichier sélectionné.");
        return; // Sortir de la méthode si aucun chemin n'est sélectionné
    }

    // Préparer la requête SQL
    QSqlQuery query;
    query.prepare("SELECT ID_BOUTIQUE, NOM, TYPE, LOCALISATION, SURFACE, MONTANT, ETAT, HORAIRE_OUVERTURE, ID_LOCATAIRE, ID_EMP FROM boutiques");

    // Exécuter la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données des boutiques : " + query.lastError().text());
        return; // Sortir de la méthode en cas d'erreur
    }

    // Configurer l'imprimante pour le PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageMargins(QMarginsF(20, 20, 20, 20)); // Marges

    QPainter painter(&printer);
    QFont titleFont("Arial", 16, QFont::Bold);
    QFont headerFont("Arial", 12, QFont::Bold);
    QFont contentFont("Arial", 10);

    // Titre
    painter.setFont(titleFont);
    painter.drawText(200, 50, "Liste des Boutiques");

    // En-têtes de colonnes
    painter.setFont(headerFont);
    int y = 100; // Position verticale pour les en-têtes
    int x = 50;  // Position horizontale pour les colonnes
    int columnWidth = 100; // Largeur des colonnes

    painter.drawText(x, y, "ID");
    painter.drawText(x + columnWidth, y, "Nom");
    painter.drawText(x + 2 * columnWidth, y, "Type");
    painter.drawText(x + 3 * columnWidth, y, "Localisation");
    painter.drawText(x + 4 * columnWidth, y, "Surface");
    painter.drawText(x + 5 * columnWidth, y, "Montant");
    painter.drawText(x + 6 * columnWidth, y, "État");
    painter.drawText(x + 7 * columnWidth, y, "Horaire d'Ouverture");
    painter.drawText(x + 8 * columnWidth, y, "ID Locataire");
    painter.drawText(x + 9 * columnWidth, y, "ID EMP");

    // Dessiner une ligne sous les en-têtes
    painter.drawLine(50, y + 5, 950, y + 5);

    // Dessiner les données des boutiques
    painter.setFont(contentFont);
    y += 20; // Position pour les lignes de données
    while (query.next()) {
        painter.drawText(x, y, query.value("ID_BOUTIQUE").toString());
        painter.drawText(x + columnWidth, y, query.value("NOM").toString());
        painter.drawText(x + 2 * columnWidth, y, query.value("TYPE").toString());
        painter.drawText(x + 3 * columnWidth, y, query.value("LOCALISATION").toString());
        painter.drawText(x + 4 * columnWidth, y, query.value("SURFACE").toString());
        painter.drawText(x + 5 * columnWidth, y, query.value("MONTANT").toString());
        painter.drawText(x + 6 * columnWidth, y, query.value("ETAT").toString());
        painter.drawText(x + 7 * columnWidth, y, query.value("HORAIRE_OUVERTURE").toString());
        painter.drawText(x + 8 * columnWidth, y, query.value("ID_LOCATAIRE").toString());
        painter.drawText(x + 9 * columnWidth, y, query.value("ID_EMP").toString());
        y += 20; // Espacement entre les lignes
    }

    painter.end();
    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
}
