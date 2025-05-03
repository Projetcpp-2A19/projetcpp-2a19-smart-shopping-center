
#include "gemploye.h"
#include "ui_gemploye.h"
#include <QMessageBox>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDialog>           // Pour créer une boîte de dialogue personnalisée
#include <QFormLayout>       // Pour structurer les champs de saisie dans la boîte de dialogue
#include <QLineEdit>         // Pour les champs de saisie de texte
#include <QPushButton>       // Pour les boutons dans la boîte de dialogue
#include <QHBoxLayout>
#include <QRegularExpression>
#include <QPrinter>
#include <QTextDocument>
#include <QSqlQuery>
#include <QFileDialog>
#include<QPdfWriter>
#include <QInputDialog>
#include <QBuffer>
#include <QPainter>

#include <QImage>
#include<arduino.h>
#include <qthread.h>
#include<qtimer.h>

#include"glocataires.h"
#include"gevennement.h"

#include "gboutique.h"

gemploye::gemploye(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gemploye)
{
    ui->setupUi(this);


    // Activer l'adaptation des images à la taille des labels
    ui->lbl_Logo_Display->setScaledContents(true);
    ui->lbl_Logo_Display->setScaledContents(true);

    // Charger l'image principale
    QString imagePath = QCoreApplication::applicationDirPath() + "/photo.jpg";
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        ui->lbl_Logo_Display->setPixmap(pixmap);
    } else {
        //QMessageBox::warning(this, "Erreur", "Impossible de charger l'image : " + imagePath);
    }
    ui->lbl_Logo_Display->setAlignment(Qt::AlignCenter);

    // Charger le logo
    QString logoPath = QCoreApplication::applicationDirPath() + "/logo.gif";
    QPixmap logoPixmap(logoPath);
    if (!logoPixmap.isNull()) {
        ui->lbl_Logo_Display->setPixmap(logoPixmap);
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de charger le logo : " + logoPath);
    }
    ui->lbl_Logo_Display->setAlignment(Qt::AlignCenter);
}

gemploye::~gemploye()
{
    delete ui;
}
void gemploye::on_pushButton_ajouter_clicked()
{
    QString id = ui->lineEdit_id->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString poste = ui->lineEdit_poste->text().trimmed();
    QString embauche = ui->lineEdit_embauche->text().trimmed();
    QString mdp = ui->lineEdit_mdp->text().trimmed();

    // Vérification si les champs obligatoires sont remplis
    if (id.isEmpty() || email.isEmpty() || nom.isEmpty() || poste.isEmpty() || embauche.isEmpty() || mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Vérification du format du nom
    QRegularExpression regexNom("^[A-Z][a-zA-Z]*$");
    if (!regexNom.match(nom).hasMatch())
    {
        QMessageBox::warning(this, "Erreur", "Le nom doit commencer par une majuscule et contenir uniquement des lettres.");
        return;
    }

    // Vérification de l'email
    if (!email.contains("@") || email.startsWith("@") || email.endsWith("@")) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un email valide contenant '@'.");
        return;
    }

    // Vérification du numéro de téléphone
    QRegularExpression regexTel("^\\d{8}$");
    if (!regexTel.match(ui->lineEdit_telephone->text().trimmed()).hasMatch())
    {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    bool salaireOk, telephoneOk;
    int salaire = ui->lineEdit_salaire->text().toInt(&salaireOk);
    int telephone = ui->lineEdit_telephone->text().toInt(&telephoneOk);

    if (!salaireOk) {
        QMessageBox::warning(this, "Erreur", "Le salaire doit être un nombre valide.");
        return;
    }

    // Création de l'objet Employee avec les données de l'utilisateur et la photo
    Employee e(id, salaire, email, nom, telephone, poste, embauche, mdp);

    // Tentative d'ajout de l'employé
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");

        // Rafraîchissement des champs après ajout
        ui->lineEdit_id->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_poste->clear();
        ui->lineEdit_embauche->clear();
        ui->lineEdit_mdp->clear();
        ui->lineEdit_telephone->clear();
        ui->lineEdit_salaire->clear();

        // Optionnel : mettre le focus sur le premier champ pour un nouvel ajout
        ui->lineEdit_id->setFocus();
    } else {
        QMessageBox::warning(this, "Erreur", "L'ajout a échoué !");
    }
}




void gemploye::afficher()
{
    QSqlQuery query;
    query.prepare("SELECT ID_EMP, NOM, EMAIL, TELEPHONE, POSTE, EMBAUCHE, SALAIRE,MDP FROM employes");

    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", "Impossible d'afficher les employés : ");
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID_EMP").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("EMAIL").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("TELEPHONE").toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("POSTE").toString()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("EMBAUCHE").toString()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("SALAIRE").toString()));
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(query.value("MDP").toString()));
        row++;
    }
}

void gemploye::on_pushButton_afficher_clicked()
{
    afficher();
}
void gemploye::on_pushButton_supprimer_clicked()
{
    QString id = ui->lineEdit_id_2->text().trimmed(); // Récupération et suppression des espaces inutiles

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer l'ID de l'employé à supprimer.");
        return;
    }

    // Vérification si l'ID existe dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM employes WHERE ID_EMP = :id");
    checkQuery.bindValue(":id", id);

    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification de l'ID : " );
        return;
    }

    checkQuery.next();
    if (checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucun employé trouvé avec cet ID.");
        return;
    }

    // Demande de confirmation avant suppression
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmation", "Voulez-vous vraiment supprimer cet employé ?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM employes WHERE ID_EMP = :id");
        deleteQuery.bindValue(":id", id);

        if (deleteQuery.exec()) {
            QMessageBox::information(this, "Succès", "Employé supprimé avec succès !");
            ui->lineEdit_id->clear(); // Effacement du champ ID après suppression
            afficher(); // Mise à jour de l'affichage après suppression
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression : " );
        }
    }
}
void gemploye::on_pushButton_Modifier_clicked()
{
    QString id = ui->lineEdit_id_2->text().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer l'ID de l'employé à modifier.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT NOM, EMAIL, POSTE, EMBAUCHE, MDP, SALAIRE, TELEPHONE FROM employes WHERE ID_EMP = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Aucun employé trouvé avec cet ID.");
        return;
    }

    QString nom = query.value(0).toString();
    QString email = query.value(1).toString();
    QString poste = query.value(2).toString();
    QString embauche = query.value(3).toString();
    QString mdp = query.value(4).toString();
    int salaire = query.value(5).toInt();
    int telephone = query.value(6).toInt();

    QDialog dialog(this);
    QFormLayout form(&dialog);

    QLineEdit lineNom(nom);
    QLineEdit lineEmail(email);
    QLineEdit linePoste(poste);
    QLineEdit lineEmbauche(embauche);
    QLineEdit lineMdp(mdp);
    QLineEdit lineSalaire(QString::number(salaire));
    QLineEdit lineTelephone(QString::number(telephone));

    form.addRow("Nom:", &lineNom);
    form.addRow("Email:", &lineEmail);
    form.addRow("Poste:", &linePoste);
    form.addRow("Date Embauche:", &lineEmbauche);
    form.addRow("Mot de passe:", &lineMdp);
    form.addRow("Salaire:", &lineSalaire);
    form.addRow("Téléphone:", &lineTelephone);

    QPushButton btnOk("Modifier", &dialog);
    QPushButton btnCancel("Annuler", &dialog);
    QHBoxLayout buttons;
    buttons.addWidget(&btnOk);
    buttons.addWidget(&btnCancel);
    form.addRow(&buttons);

    QObject::connect(&btnOk, &QPushButton::clicked, &dialog, &QDialog::accept);
    QObject::connect(&btnCancel, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        nom = lineNom.text().trimmed();
        email = lineEmail.text().trimmed();
        poste = linePoste.text().trimmed();
        embauche = lineEmbauche.text().trimmed();
        mdp = lineMdp.text().trimmed();
        QString salaireStr = lineSalaire.text().trimmed();
        QString telephoneStr = lineTelephone.text().trimmed();

        // ==== CONTRÔLE DE SAISIE ====
        if (nom.isEmpty() || email.isEmpty() || poste.isEmpty() || embauche.isEmpty() || mdp.isEmpty() || salaireStr.isEmpty() || telephoneStr.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
            return;
        }

        // Vérification du format du nom
        QRegularExpression regexNom("^[A-Z][a-zA-Z]*$");
        if (!regexNom.match(nom).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "Le nom doit commencer par une majuscule et contenir uniquement des lettres.");
            return;
        }

        // Vérification de l'email
        if (!email.contains("@") || email.startsWith("@") || email.endsWith("@")) {
            QMessageBox::warning(this, "Erreur", "Veuillez entrer un email valide contenant '@'.");
            return;
        }

        // Vérification du numéro de téléphone
        QRegularExpression regexTel("^\\d{8}$");
        if (!regexTel.match(telephoneStr).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
            return;
        }

        bool salaireOk, telephoneOk;
        salaire = salaireStr.toInt(&salaireOk);
        telephone = telephoneStr.toInt(&telephoneOk);

        if (!salaireOk) {
            QMessageBox::warning(this, "Erreur", "Le salaire doit être un nombre valide.");
            return;
        }
        // ==== FIN CONTRÔLE SAISIE ====

        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE employes SET NOM = :nom, EMAIL = :email, POSTE = :poste, "
                            "EMBAUCHE = :embauche, MDP = :mdp, SALAIRE = :salaire, TELEPHONE = :telephone "
                            "WHERE ID_EMP = :id");

        updateQuery.bindValue(":id", id);
        updateQuery.bindValue(":nom", nom);
        updateQuery.bindValue(":email", email);
        updateQuery.bindValue(":poste", poste);
        updateQuery.bindValue(":embauche", embauche);
        updateQuery.bindValue(":mdp", mdp);
        updateQuery.bindValue(":salaire", salaire);
        updateQuery.bindValue(":telephone", telephone);

        if (updateQuery.exec()) {
            QMessageBox::information(this, "Succès", "Employé modifié avec succès !");
            afficher(); // Met à jour l'affichage
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la modification !");
        }
    }
}

  // Inclure cette ligne pour pouvoir utiliser QPageSize


void gemploye::on_pushButton_Extraire_clicked()
{
    QString id = ui->lineEdit_id_2->text().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer l'ID de l'employé à exporter.");
        return;
    }

    // Récupération des données de l'employé depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT ID_EMP, NOM, EMAIL, TELEPHONE, POSTE, EMBAUCHE, SALAIRE FROM employes WHERE ID_EMP = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données de l'employé.");
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "Erreur", "Aucun employé trouvé avec cet ID.");
        return;
    }

    QString nom = query.value("NOM").toString();
    QString email = query.value("EMAIL").toString();
    QString telephone = query.value("TELEPHONE").toString();
    QString poste = query.value("POSTE").toString();
    QString embauche = query.value("EMBAUCHE").toString();
    QString salaire = query.value("SALAIRE").toString();

    // Sélection du fichier de sortie PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) {
        return;
    }

    // Création du document HTML pour le PDF
    QTextDocument doc;
    QString html = "<html>";
    html += "<head><style>"
            "body { font-family: Arial, sans-serif; font-size: 12pt; color: #333333; margin: 30px; }"
            "h1 { text-align: center; color: #007bff; font-size: 24pt; }"
            "table { width: 100%; border-collapse: collapse; margin-top: 20px; }"
            "th, td { padding: 10px; text-align: left; }"
            "th { background-color: #f2f2f2; font-size: 14pt; }"
            "td { font-size: 12pt; }"
            "tr:nth-child(even) { background-color: #f9f9f9; }"
            "footer { font-size: 10pt; color: #777777; text-align: center; margin-top: 40px; }"
            "</style></head>";
    html += "<body>";
    html += "<h1>Informations sur l'Employé</h1>";
    // Retirer l'image pour tester
    html += "<tr><td><b>ID :</b></td><td>" + id + "</td></tr>";
    html += "<tr><td><b>Nom :</b></td><td>" + nom + "</td></tr>";
    html += "<tr><td><b>Email :</b></td><td>" + email + "</td></tr>";
    html += "<tr><td><b>Téléphone :</b></td><td>" + telephone + "</td></tr>";
    html += "<tr><td><b>Poste :</b></td><td>" + poste + "</td></tr>";
    html += "<tr><td><b>Embauche :</b></td><td>" + embauche + "</td></tr>";
    html += "<tr><td><b>Salaire :</b></td><td>" + salaire + " DT</td></tr>";
    html += "<footer>Document généré par le système GEmployées</footer>";
    html += "</body></html>";

    doc.setHtml(html);

    // Création et configuration de l'imprimante PDF
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageMargins(QMarginsF(20, 20, 20, 20)); // Marges personnalisées

    // Vérification avant d'imprimer
    if (!doc.isEmpty()) {
        // Impression du document HTML dans le fichier PDF
        doc.print(&printer);

        // Message de confirmation
        QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès et enregistré à l'emplacement suivant : " + filePath);
    } else {
        QMessageBox::critical(this, "Erreur", "Le document est vide. Vérifiez les données.");
    }
}
void gemploye::on_pushButton_rechercher_clicked()
{
    // Récupérer le nom à rechercher depuis le champ de texte (par exemple, ui->lineEdit_nom_recherche)
    QString nomRecherche = ui->lineEdit_nom_recherche->text().trimmed();

    if (nomRecherche.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom à rechercher.");
        return;
    }

    // Préparer la requête pour rechercher l'employé par nom
    QSqlQuery query;
    query.prepare("SELECT ID_EMP, NOM, EMAIL, TELEPHONE, POSTE, EMBAUCHE, SALAIRE FROM employes WHERE NOM LIKE :nom");
    query.bindValue(":nom", "%" + nomRecherche + "%"); // Recherche par nom avec correspondance partielle

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche de l'employé.");
        return;
    }

    if (!query.next()) {
        QMessageBox::information(this, "Résultat", "Aucun employé trouvé avec ce nom.");
        return;
    }

    QString id = query.value("ID_EMP").toString();
    QString nom = query.value("NOM").toString();
    QString email = query.value("EMAIL").toString();
    QString telephone = query.value("TELEPHONE").toString();
    QString poste = query.value("POSTE").toString();
    QString embauche = query.value("EMBAUCHE").toString();
    QString salaire = query.value("SALAIRE").toString();

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->insertRow(0);

    // Remplir la ligne avec les données de l'employé
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(id));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(nom));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(email));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(telephone));
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem(poste));
    ui->tableWidget->setItem(0, 5, new QTableWidgetItem(embauche));
    ui->tableWidget->setItem(0, 6, new QTableWidgetItem(salaire));
}
void gemploye::on_pushButton_trier_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT ID_EMP, NOM, EMAIL, TELEPHONE, POSTE, EMBAUCHE, SALAIRE FROM employes ORDER BY NOM ASC");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du tri des employés.");
        return;
    }

    // Effacer l'ancien contenu du tableau
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        QString id = query.value("ID_EMP").toString();
        QString nom = query.value("NOM").toString();
        QString email = query.value("EMAIL").toString();
        QString telephone = query.value("TELEPHONE").toString();
        QString poste = query.value("POSTE").toString();
        QString embauche = query.value("EMBAUCHE").toString();
        QString salaire = query.value("SALAIRE").toString();

        // Ajouter une nouvelle ligne
        ui->tableWidget->insertRow(row);

        // Remplir la ligne avec les données triées
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(nom));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(email));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(telephone));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(poste));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(embauche));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(salaire));

        row++; // Passer à la ligne suivante
    }

    QMessageBox::information(this, "Succès", "Liste triée par ordre alphabétique.");
}
#include <QPainter>
#include <QDialog>
#include <QVBoxLayout>
#include <QtMath> // pour sin/cos

void gemploye::on_pushButton_stats_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT POSTE, COUNT(*) FROM employes GROUP BY POSTE");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les statistiques.");
        return;
    }

    QMap<QString, int> statsMap;
    int total = 0;

    while (query.next()) {
        QString poste = query.value(0).toString();
        int count = query.value(1).toInt();
        statsMap[poste] = count;
        total += count;
    }

    if (statsMap.isEmpty()) {
        QMessageBox::information(this, "Statistiques", "Aucun employé trouvé dans la base de données.");
        return;
    }

    // Classe widget locale pour le dessin
    class PieWidget : public QWidget {
    public:
        PieWidget(QMap<QString, int> data, QWidget *parent = nullptr)
            : QWidget(parent), statsMap(data), animation(this)
        {
            // Générer des couleurs aléatoires
            for (int i = 0; i < statsMap.size(); ++i) {
                colors.append(QColor::fromRgb(rand() % 256, rand() % 256, rand() % 256));
            }

            // Initialiser l'animation de rotation
            animation.setTargetObject(this);
            animation.setPropertyName("angle");
            animation.setStartValue(0);
            animation.setEndValue(360);
            animation.setDuration(2000); // 2 secondes
            animation.setLoopCount(-1); // Animation continue
            animation.start();
        }

        int angle() const {
            return m_angle;
        }

        void setAngle(int angle) {
            m_angle = angle;
            update(); // Redessiner le widget à chaque changement d'angle
        }

    protected:
        void paintEvent(QPaintEvent *) override {
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing);

            int total = 0;
            for (auto v : statsMap)
                total += v;

            QRectF rect(100, 50, 300, 300);
            double startAngle = 0.0;
            int index = 0;

            QFont font = painter.font();
            font.setBold(true);
            painter.setFont(font);

            for (auto it = statsMap.begin(); it != statsMap.end(); ++it, ++index) {
                double angleSpan = 360.0 * it.value() / total;

                // Animation: rotation en fonction de l'angle
                painter.setBrush(colors[index]);
                painter.drawPie(rect, int((startAngle + m_angle) * 16), int(angleSpan * 16));

                // Affichage du % au centre du secteur
                double midAngle = startAngle + angleSpan / 2;
                double radians = qDegreesToRadians(midAngle);
                double radius = 150 / 2.0;

                double cx = rect.center().x() + radius * qCos(radians);
                double cy = rect.center().y() - radius * qSin(radians);

                QString percentage = QString::number((100.0 * it.value()) / total, 'f', 1) + "%";
                painter.setPen(Qt::white);
                painter.drawText(QPointF(cx - 10, cy + 5), percentage);

                // Légende
                painter.setPen(Qt::black);
                painter.setBrush(colors[index]);
                painter.drawRect(30, 370 + index * 25, 15, 15);
                painter.drawText(50, 385 + index * 25, QString("%1 (%2)").arg(it.key()).arg(it.value()));

                startAngle += angleSpan;
            }
        }

    private:
        QMap<QString, int> statsMap;
        QList<QColor> colors;
        QPropertyAnimation animation;
        int m_angle = 0;
    };

    // Affichage du graphique
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des employés");
    dialog->resize(500, 500);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    PieWidget *pieWidget = new PieWidget(statsMap);
    layout->addWidget(pieWidget);
    dialog->setLayout(layout);
    dialog->exec();
}

#include "arduino.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QInputDialog>



void gemploye::on_pushButton_ajouter_id_empreinte_clicked()
{
    bool ok;

    // Afficher une boîte de dialogue pour que l'utilisateur entre l'ID de l'empreinte
    QString fingerprintID = QInputDialog::getText(nullptr, "Rechercher empreinte",
                                                  "Entrez l'ID de l'empreinte :", QLineEdit::Normal, "", &ok);

    if (ok && !fingerprintID.isEmpty()) {
        // Créer une instance de la classe Arduino
        Arduino arduino;
        int connectionStatus = arduino.connect_arduino();  // Connexion à l'Arduino

        if (connectionStatus == -1) {
            // Si aucun Arduino n'est détecté, afficher une erreur et sortir de la fonction
            showMessage("Erreur", "Aucune carte Arduino détectée.", QMessageBox::Critical);
            return;
        }

        QThread::msleep(1500);

        // Recherche de l'ID dans la base de données
        QSqlQuery query;
        query.prepare("SELECT * FROM EMPLOYES WHERE ID_EMPREINTE = :id");
        query.bindValue(":id", fingerprintID);

        if (!query.exec()) {
            // Si une erreur d'exécution de la requête SQL survient
            showMessage("Erreur SQL", "Erreur d'accès à la base de données : " + query.lastError().text(), QMessageBox::Critical);
            //arduino.close_arduino(); // Fermer la connexion Arduino
            return;
        }

        if (query.next()) {
            // Si l'ID d'empreinte est trouvé dans la base de données
            showMessage("Succès", "Empreinte trouvée !", QMessageBox::Information);
            // Envoie le message "Empreinte trouvée" à l'Arduino (sans caractères spéciaux)
            arduino.write_to_arduino("Empreinte trouvee\n");
        } else {
            // Si l'ID d'empreinte n'est pas trouvé
            showMessage("Erreur", "Empreinte non trouvée.", QMessageBox::Warning);
            // Envoie le message "Empreinte non trouvée" à l'Arduino (sans caractères spéciaux)
            arduino.write_to_arduino("Empreinte non trouvee\n");
        }

        // Fermer la connexion série après l'envoi du message
        //arduino.close_arduino();
    } else {
        // Si l'utilisateur annule ou laisse vide, afficher un message d'information
        showMessage("Annulation", "Recherche d'empreinte annulée.", QMessageBox::Information);
    }
}

void gemploye::showMessage(const QString& title, const QString& message, QMessageBox::Icon icon)
{
    // Cette fonction centralise l'affichage des messages, ce qui permet de réduire la duplication de code
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setIcon(icon);
    msgBox.exec();
}
void gemploye::on_pushButton_deconnecter_clicked()
{
    // Déconnexion
    QMessageBox::information(this, "Déconnexion", "À bientôt!");
    close();
}



