/********************************************************************************
** Form generated from reading UI file 'gemploye.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEMPLOYE_H
#define UI_GEMPLOYE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gemploye
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_poste;
    QDateTimeEdit *lineEdit_embauche;
    QLabel *label;
    QLineEdit *lineEdit_telephone;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_mdp;
    QLineEdit *lineEdit_salaire;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_afficher;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_Modifier;
    QLineEdit *lineEdit_id_2;
    QPushButton *pushButton_Extraire;
    QLabel *label_TITLE;
    QFrame *frame_gestions;
    QPushButton *pushButton_Dashboard;
    QPushButton *pushButton_Employes;
    QPushButton *pushButton_Boutiques;
    QPushButton *pushButton_Locataires;
    QPushButton *pushButton_Services;
    QPushButton *pushButton_Evennements;
    QPushButton *pushButton_deconnecter;
    QLabel *lbl_Logo_Display;
    QFrame *frame_3;
    QTableWidget *tableWidget;
    QPushButton *pushButton_rechercher;
    QLineEdit *lineEdit_nom_recherche;
    QPushButton *pushButton_trier;
    QPushButton *pushButton_stats;
    QPushButton *pushButton_ajouter_id_empreinte;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gemploye)
    {
        if (gemploye->objectName().isEmpty())
            gemploye->setObjectName("gemploye");
        gemploye->resize(1000, 750);
        gemploye->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background: #f0c1cd;  \n"
"}\n"
"\n"
"\n"
""));
        gemploye->setAnimated(true);
        centralwidget = new QWidget(gemploye);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(190, 90, 271, 641));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 3px solid grey;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"     border-radius: 10px;\n"
"    background-color:  rgb(0, 162, 198);\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_nom = new QLineEdit(frame);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(40, 90, 191, 26));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_email = new QLineEdit(frame);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(40, 140, 191, 26));
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_poste = new QLineEdit(frame);
        lineEdit_poste->setObjectName("lineEdit_poste");
        lineEdit_poste->setGeometry(QRect(40, 240, 191, 26));
        lineEdit_poste->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_embauche = new QDateTimeEdit(frame);
        lineEdit_embauche->setObjectName("lineEdit_embauche");
        lineEdit_embauche->setGeometry(QRect(40, 310, 191, 31));
        lineEdit_embauche->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_embauche->setStyleSheet(QString::fromUtf8("QDateTimeEdit  {\n"
"	font: 8pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 280, 151, 31));
        label->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_telephone = new QLineEdit(frame);
        lineEdit_telephone->setObjectName("lineEdit_telephone");
        lineEdit_telephone->setGeometry(QRect(40, 190, 191, 26));
        lineEdit_telephone->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_id = new QLineEdit(frame);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(40, 40, 191, 26));
        lineEdit_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_mdp = new QLineEdit(frame);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(50, 400, 191, 26));
        lineEdit_mdp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_salaire = new QLineEdit(frame);
        lineEdit_salaire->setObjectName("lineEdit_salaire");
        lineEdit_salaire->setGeometry(QRect(50, 360, 191, 26));
        lineEdit_salaire->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_ajouter = new QPushButton(frame);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(10, 440, 121, 31));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #00a2c6, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        pushButton_afficher = new QPushButton(frame);
        pushButton_afficher->setObjectName("pushButton_afficher");
        pushButton_afficher->setGeometry(QRect(140, 440, 121, 31));
        pushButton_afficher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #00a2c6, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        pushButton_supprimer = new QPushButton(frame);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(140, 520, 121, 31));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #00a2c6, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        pushButton_Modifier = new QPushButton(frame);
        pushButton_Modifier->setObjectName("pushButton_Modifier");
        pushButton_Modifier->setGeometry(QRect(10, 520, 121, 31));
        pushButton_Modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #00a2c6, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        lineEdit_id_2 = new QLineEdit(frame);
        lineEdit_id_2->setObjectName("lineEdit_id_2");
        lineEdit_id_2->setGeometry(QRect(20, 480, 221, 26));
        lineEdit_id_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_Extraire = new QPushButton(frame);
        pushButton_Extraire->setObjectName("pushButton_Extraire");
        pushButton_Extraire->setGeometry(QRect(70, 570, 121, 29));
        pushButton_Extraire->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #00a2c6, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        label_TITLE = new QLabel(centralwidget);
        label_TITLE->setObjectName("label_TITLE");
        label_TITLE->setGeometry(QRect(190, 20, 741, 81));
        label_TITLE->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 36pt \"Imprint MT Shadow\";\n"
"    color: rgb(0, 162, 198);\n"
"    text-shadow: 2px 2px 4px rgba(0, 0, 0, 80); /* Ajout d'un effet d'ombre */\n"
"}\n"
""));
        frame_gestions = new QFrame(centralwidget);
        frame_gestions->setObjectName("frame_gestions");
        frame_gestions->setGeometry(QRect(0, 0, 181, 751));
        frame_gestions->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: rgb(0, 162, 198);\n"
"    border: 2px solid #00a2c6;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}\n"
""));
        frame_gestions->setFrameShape(QFrame::Shape::StyledPanel);
        frame_gestions->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_Dashboard = new QPushButton(frame_gestions);
        pushButton_Dashboard->setObjectName("pushButton_Dashboard");
        pushButton_Dashboard->setGeometry(QRect(0, 100, 181, 51));
        pushButton_Dashboard->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 16pt \"Segoe UI\";\n"
"    color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: #00a2c6;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    font: 18pt \"Segoe UI\"; /* Agrandir le texte au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* pas de bordure pour un bouton plat */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* rendre le bouton par d\303\251faut plus visible */\n"
"}\n"
""));
        pushButton_Employes = new QPushButton(frame_gestions);
        pushButton_Employes->setObjectName("pushButton_Employes");
        pushButton_Employes->setGeometry(QRect(0, 150, 181, 51));
        pushButton_Employes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 16pt \"Segoe UI\";\n"
"    color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: #00a2c6;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    font: 18pt \"Segoe UI\"; /* Agrandir le texte au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* pas de bordure pour un bouton plat */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* rendre le bouton par d\303\251faut plus visible */\n"
"}\n"
""));
        pushButton_Boutiques = new QPushButton(frame_gestions);
        pushButton_Boutiques->setObjectName("pushButton_Boutiques");
        pushButton_Boutiques->setGeometry(QRect(0, 200, 181, 51));
        pushButton_Boutiques->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 16pt \"Segoe UI\";\n"
"    color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: #00a2c6;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    font: 18pt \"Segoe UI\"; /* Agrandir le texte au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* pas de bordure pour un bouton plat */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* rendre le bouton par d\303\251faut plus visible */\n"
"}\n"
""));
        pushButton_Locataires = new QPushButton(frame_gestions);
        pushButton_Locataires->setObjectName("pushButton_Locataires");
        pushButton_Locataires->setGeometry(QRect(0, 250, 181, 51));
        pushButton_Locataires->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 16pt \"Segoe UI\";\n"
"    color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: #00a2c6;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    font: 18pt \"Segoe UI\"; /* Agrandir le texte au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* pas de bordure pour un bouton plat */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* rendre le bouton par d\303\251faut plus visible */\n"
"}\n"
""));
        pushButton_Services = new QPushButton(frame_gestions);
        pushButton_Services->setObjectName("pushButton_Services");
        pushButton_Services->setGeometry(QRect(0, 300, 181, 51));
        pushButton_Services->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 16pt \"Segoe UI\";\n"
"    color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: #00a2c6;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    font: 18pt \"Segoe UI\"; /* Agrandir le texte au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* pas de bordure pour un bouton plat */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* rendre le bouton par d\303\251faut plus visible */\n"
"}\n"
""));
        pushButton_Evennements = new QPushButton(frame_gestions);
        pushButton_Evennements->setObjectName("pushButton_Evennements");
        pushButton_Evennements->setGeometry(QRect(0, 350, 181, 51));
        pushButton_Evennements->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 16pt \"Segoe UI\";\n"
"    color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: #00a2c6;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    font: 18pt \"Segoe UI\"; /* Agrandir le texte au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* pas de bordure pour un bouton plat */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* rendre le bouton par d\303\251faut plus visible */\n"
"}\n"
""));
        pushButton_deconnecter = new QPushButton(frame_gestions);
        pushButton_deconnecter->setObjectName("pushButton_deconnecter");
        pushButton_deconnecter->setGeometry(QRect(0, 600, 181, 51));
        pushButton_deconnecter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  \n"
"    font: 9pt \"Segoe UI\";\n"
"    color: rgb(255, 255, 255);\n"
"    border-radius: 6px;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    font: 12pt \"Segoe UI\"; /* Agrandir le texte au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* pas de bordure pour un bouton plat */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* rendre le bouton par d\303\251faut plus visible */\n"
"}\n"
""));
        lbl_Logo_Display = new QLabel(frame_gestions);
        lbl_Logo_Display->setObjectName("lbl_Logo_Display");
        lbl_Logo_Display->setGeometry(QRect(0, 0, 181, 91));
        lbl_Logo_Display->setPixmap(QPixmap(QString::fromUtf8("build/Desktop_Qt_6_7_3_MinGW_64_bit-Debug/debug/logo.gif")));
        lbl_Logo_Display->setScaledContents(true);
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(180, -10, 811, 31));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: rgb(0, 162, 198);\n"
"    border: 2px solid #00a2c6;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}\n"
""));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(470, 170, 521, 321));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #f5f5f5;  /* Fond gris clair pour le tableau */\n"
"    border-radius: 10px;         /* Coins arrondis pour un effet moderne */\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur de texte sombre */\n"
"    border: 1px solid #ddd;  /* Bordure gris clair */\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 12px;\n"
"    border-bottom: 1px solid #e0e0e0;  /* S\303\251parateurs fins entre les lignes */\n"
"    transition: background-color 0.3s ease;  /* Transition douce au survol */\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #007bff;  /* Bleu vif lorsque l'\303\251l\303\251ment est s\303\251lectionn\303\251 */\n"
"    color: white;                /* Texte en blanc lorsqu'un \303\251l\303\251ment est s\303\251lectionn\303\251 */\n"
"    border: 1px solid #0056b3;   /* Bordure bleu fonc\303\251 quand s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
""
                        "    background-color: #B3D4FF;  /* Bleu clair lorsqu'on survole la cellule */\n"
"    cursor: pointer;            /* Curseur main pour indiquer l'interaction */\n"
"}\n"
"\n"
"QTableWidget::horizontalHeader {\n"
"    background-color: #0056b3;  /* Bleu fonc\303\251 pour l'en-t\303\252te */\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 12px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    border-radius: 8px 8px 0 0;  /* Coins arrondis en haut */\n"
"}\n"
"\n"
"QTableWidget::horizontalHeader::section {\n"
"    padding: 10px;\n"
"    border-right: 2px solid #4a90e2;  /* Lignes de s\303\251paration claires entre les colonnes */\n"
"}\n"
"\n"
"QTableWidget::horizontalHeader::item {\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::verticalHeader {\n"
"    background-color: #0056b3;  /* M\303\252me bleu fonc\303\251 pour l'en-t\303\252te vertical */\n"
"    color: white;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::verticalH"
                        "eader::section {\n"
"    border-right: 2px solid #4a90e2;  /* S\303\251parateur vertical l\303\251ger */\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QTableWidget::item:focus {\n"
"    border: 1px solid #007bff;  /* Bordure bleue claire lorsque l'\303\251l\303\251ment est en focus */\n"
"}\n"
"\n"
"QTableWidget::item:checked {\n"
"    background-color: #007bff;  /* Bleu clair quand l'\303\251l\303\251ment est s\303\251lectionn\303\251 */\n"
"    color: white;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #0056b3;\n"
"    border: none;\n"
"}\n"
""));
        pushButton_rechercher = new QPushButton(centralwidget);
        pushButton_rechercher->setObjectName("pushButton_rechercher");
        pushButton_rechercher->setGeometry(QRect(660, 130, 121, 31));
        pushButton_rechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #00a2c6, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        lineEdit_nom_recherche = new QLineEdit(centralwidget);
        lineEdit_nom_recherche->setObjectName("lineEdit_nom_recherche");
        lineEdit_nom_recherche->setGeometry(QRect(460, 130, 171, 26));
        lineEdit_nom_recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: black;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_trier = new QPushButton(centralwidget);
        pushButton_trier->setObjectName("pushButton_trier");
        pushButton_trier->setGeometry(QRect(860, 130, 121, 31));
        pushButton_trier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #00a2c6, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        pushButton_stats = new QPushButton(centralwidget);
        pushButton_stats->setObjectName("pushButton_stats");
        pushButton_stats->setGeometry(QRect(520, 500, 171, 31));
        pushButton_stats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #00a2c6, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        pushButton_ajouter_id_empreinte = new QPushButton(centralwidget);
        pushButton_ajouter_id_empreinte->setObjectName("pushButton_ajouter_id_empreinte");
        pushButton_ajouter_id_empreinte->setGeometry(QRect(780, 510, 171, 31));
        pushButton_ajouter_id_empreinte->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #00a2c6, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        gemploye->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gemploye);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        gemploye->setMenuBar(menubar);
        statusbar = new QStatusBar(gemploye);
        statusbar->setObjectName("statusbar");
        gemploye->setStatusBar(statusbar);

        retranslateUi(gemploye);

        QMetaObject::connectSlotsByName(gemploye);
    } // setupUi

    void retranslateUi(QMainWindow *gemploye)
    {
        gemploye->setWindowTitle(QCoreApplication::translate("gemploye", "gemploye", nullptr));
        lineEdit_nom->setPlaceholderText(QCoreApplication::translate("gemploye", "            NOM", nullptr));
        lineEdit_email->setText(QString());
        lineEdit_email->setPlaceholderText(QCoreApplication::translate("gemploye", "         email", nullptr));
        lineEdit_poste->setPlaceholderText(QCoreApplication::translate("gemploye", "            poste", nullptr));
        label->setText(QCoreApplication::translate("gemploye", "date_embauche", nullptr));
        lineEdit_telephone->setPlaceholderText(QCoreApplication::translate("gemploye", "      num_t\303\251l\303\251phone", nullptr));
        lineEdit_id->setText(QString());
        lineEdit_id->setPlaceholderText(QCoreApplication::translate("gemploye", "               ID", nullptr));
        lineEdit_mdp->setPlaceholderText(QCoreApplication::translate("gemploye", "            mdp", nullptr));
        lineEdit_salaire->setPlaceholderText(QCoreApplication::translate("gemploye", "            salaire", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("gemploye", "Ajouter", nullptr));
        pushButton_afficher->setText(QCoreApplication::translate("gemploye", "afficher", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("gemploye", "Supprimer", nullptr));
        pushButton_Modifier->setText(QCoreApplication::translate("gemploye", "modifier", nullptr));
        lineEdit_id_2->setText(QString());
        lineEdit_id_2->setPlaceholderText(QCoreApplication::translate("gemploye", "   SAISIR ID \303\240 TRAITER", nullptr));
        pushButton_Extraire->setText(QCoreApplication::translate("gemploye", "Extraire", nullptr));
        label_TITLE->setText(QCoreApplication::translate("gemploye", "Gestion des utilisateurs", nullptr));
        pushButton_Dashboard->setText(QCoreApplication::translate("gemploye", "Dashboard", nullptr));
        pushButton_Employes->setText(QCoreApplication::translate("gemploye", "Employ\303\251s", nullptr));
        pushButton_Boutiques->setText(QCoreApplication::translate("gemploye", "Boutiques", nullptr));
        pushButton_Locataires->setText(QCoreApplication::translate("gemploye", "Locataires", nullptr));
        pushButton_Services->setText(QCoreApplication::translate("gemploye", "Services", nullptr));
        pushButton_Evennements->setText(QCoreApplication::translate("gemploye", "Evennements", nullptr));
        pushButton_deconnecter->setText(QCoreApplication::translate("gemploye", "se d\303\251connecter", nullptr));
        lbl_Logo_Display->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("gemploye", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("gemploye", "NOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("gemploye", "EMAIL", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("gemploye", "NUM_TEL", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("gemploye", "POSTE", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("gemploye", "DATE_EMBAUCHE", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("gemploye", "SALAIRE", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("gemploye", "MDP", nullptr));
        pushButton_rechercher->setText(QCoreApplication::translate("gemploye", "Chercher", nullptr));
        lineEdit_nom_recherche->setPlaceholderText(QCoreApplication::translate("gemploye", "TAPER UN NOM ", nullptr));
        pushButton_trier->setText(QCoreApplication::translate("gemploye", "Trier", nullptr));
        pushButton_stats->setText(QCoreApplication::translate("gemploye", "stat", nullptr));
        pushButton_ajouter_id_empreinte->setText(QCoreApplication::translate("gemploye", "empreinte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gemploye: public Ui_gemploye {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEMPLOYE_H
