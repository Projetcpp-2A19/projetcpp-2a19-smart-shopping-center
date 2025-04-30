/********************************************************************************
** Form generated from reading UI file 'glocataires.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOCATAIRES_H
#define UI_GLOCATAIRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLocataire
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *line_NOMLoc;
    QLineEdit *line_PhoneLoc;
    QLineEdit *line_CONTRATLoc;
    QLineEdit *line_MAILLoc;
    QLineEdit *line_IDLoc;
    QComboBox *comboBox_StatutPaiement;
    QLineEdit *line_MONTANT_LOYERLOC;
    QLineEdit *line_TYPELoc;
    QLineEdit *line_IDENTIFIANT;
    QPushButton *pushButton_Ajouter;
    QPushButton *pushButton_Supprimer;
    QPushButton *pushButton_Modifier;
    QLabel *label_TITLE;
    QTableView *tableView;
    QLabel *lbl_Image_Display;
    QFrame *frame_gestions;
    QPushButton *pushButton_Dashboard;
    QPushButton *pushButton_Employes;
    QPushButton *pushButton_Boutiques;
    QPushButton *pushButton_Locataires;
    QPushButton *pushButton_Services;
    QPushButton *pushButton_Evennements;
    QPushButton *pushButton_deconnecter;
    QLabel *lbl_Logo_Display;
    QFrame *frame_2;
    QFrame *frame_3;
    QPushButton *pushButton_Retreive;
    QPushButton *stat;
    QPushButton *PDF;
    QPushButton *pushButton_ChatBot;
    QLineEdit *searchLineEdit;
    QComboBox *sortComboBox;
    QLabel *label_tri;
    QPushButton *pushButton_Ouvrir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GLocataire)
    {
        if (GLocataire->objectName().isEmpty())
            GLocataire->setObjectName("GLocataire");
        GLocataire->resize(1261, 638);
        GLocataire->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background: #f0c1cd;  \n"
"}\n"
"\n"
"\n"
""));
        GLocataire->setAnimated(true);
        centralwidget = new QWidget(GLocataire);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(210, 100, 271, 471));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 3px solid grey;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"     border-radius: 10px;\n"
"    background-color:  rgb(0, 162, 198);\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        line_NOMLoc = new QLineEdit(frame);
        line_NOMLoc->setObjectName("line_NOMLoc");
        line_NOMLoc->setGeometry(QRect(40, 60, 191, 26));
        line_NOMLoc->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"    color: black;\n"
"}"));
        line_PhoneLoc = new QLineEdit(frame);
        line_PhoneLoc->setObjectName("line_PhoneLoc");
        line_PhoneLoc->setGeometry(QRect(40, 110, 191, 26));
        line_PhoneLoc->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"    color: black;\n"
"}"));
        line_CONTRATLoc = new QLineEdit(frame);
        line_CONTRATLoc->setObjectName("line_CONTRATLoc");
        line_CONTRATLoc->setGeometry(QRect(40, 220, 191, 26));
        line_CONTRATLoc->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"    color: black;\n"
"}"));
        line_MAILLoc = new QLineEdit(frame);
        line_MAILLoc->setObjectName("line_MAILLoc");
        line_MAILLoc->setGeometry(QRect(40, 160, 191, 26));
        line_MAILLoc->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"    color: black;\n"
"}"));
        line_IDLoc = new QLineEdit(frame);
        line_IDLoc->setObjectName("line_IDLoc");
        line_IDLoc->setEnabled(false);
        line_IDLoc->setGeometry(QRect(40, 20, 191, 26));
        line_IDLoc->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"    color: black;\n"
"}"));
        comboBox_StatutPaiement = new QComboBox(frame);
        comboBox_StatutPaiement->addItem(QString());
        comboBox_StatutPaiement->addItem(QString());
        comboBox_StatutPaiement->setObjectName("comboBox_StatutPaiement");
        comboBox_StatutPaiement->setGeometry(QRect(40, 310, 191, 26));
        comboBox_StatutPaiement->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    color: black;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    color: black;\n"
"    background-color: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"}"));
        line_MONTANT_LOYERLOC = new QLineEdit(frame);
        line_MONTANT_LOYERLOC->setObjectName("line_MONTANT_LOYERLOC");
        line_MONTANT_LOYERLOC->setGeometry(QRect(40, 270, 191, 26));
        line_MONTANT_LOYERLOC->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"    color: black;\n"
"}"));
        line_TYPELoc = new QLineEdit(frame);
        line_TYPELoc->setObjectName("line_TYPELoc");
        line_TYPELoc->setGeometry(QRect(30, 360, 191, 26));
        line_TYPELoc->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"    color: black;\n"
"}"));
        line_IDENTIFIANT = new QLineEdit(frame);
        line_IDENTIFIANT->setObjectName("line_IDENTIFIANT");
        line_IDENTIFIANT->setGeometry(QRect(20, 400, 191, 26));
        line_IDENTIFIANT->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"    color: black;\n"
"}"));
        pushButton_Ajouter = new QPushButton(centralwidget);
        pushButton_Ajouter->setObjectName("pushButton_Ajouter");
        pushButton_Ajouter->setGeometry(QRect(520, 460, 121, 31));
        pushButton_Ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_Supprimer = new QPushButton(centralwidget);
        pushButton_Supprimer->setObjectName("pushButton_Supprimer");
        pushButton_Supprimer->setGeometry(QRect(520, 510, 121, 31));
        pushButton_Supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_Modifier = new QPushButton(centralwidget);
        pushButton_Modifier->setObjectName("pushButton_Modifier");
        pushButton_Modifier->setGeometry(QRect(670, 510, 121, 31));
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
        label_TITLE = new QLabel(centralwidget);
        label_TITLE->setObjectName("label_TITLE");
        label_TITLE->setGeometry(QRect(190, 20, 581, 81));
        label_TITLE->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 36pt \"Imprint MT Shadow\";\n"
"    color: rgb(0, 162, 198);\n"
"    text-shadow: 2px 2px 4px rgba(0, 0, 0, 80); /* Ajout d'un effet d'ombre */\n"
"}\n"
""));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(500, 130, 741, 321));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: white;\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 2px;\n"
"    font: 11pt \"Segoe UI\";\n"
"    color: black;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    color: black;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: rgb(0, 162, 198);\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: rgb(0, 162, 198);\n"
"    color: white;\n"
"    padding: 4px;\n"
"    border: 1px solid #666;\n"
"    font-weight: bold;\n"
"}"));
        lbl_Image_Display = new QLabel(centralwidget);
        lbl_Image_Display->setObjectName("lbl_Image_Display");
        lbl_Image_Display->setEnabled(true);
        lbl_Image_Display->setGeometry(QRect(660, 20, 151, 121));
        lbl_Image_Display->setPixmap(QPixmap(QString::fromUtf8("../photo.jpg")));
        lbl_Image_Display->setScaledContents(true);
        frame_gestions = new QFrame(centralwidget);
        frame_gestions->setObjectName("frame_gestions");
        frame_gestions->setGeometry(QRect(0, 0, 181, 571));
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
        pushButton_deconnecter->setGeometry(QRect(0, 500, 181, 51));
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
        frame_2 = new QFrame(frame_gestions);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(120, 540, 120, 80));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(180, -10, 621, 31));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: rgb(0, 162, 198);\n"
"    border: 2px solid #00a2c6;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}\n"
""));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_Retreive = new QPushButton(centralwidget);
        pushButton_Retreive->setObjectName("pushButton_Retreive");
        pushButton_Retreive->setGeometry(QRect(820, 460, 121, 31));
        pushButton_Retreive->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stat = new QPushButton(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(840, 510, 151, 31));
        stat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        PDF = new QPushButton(centralwidget);
        PDF->setObjectName("PDF");
        PDF->setGeometry(QRect(1040, 510, 151, 31));
        PDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_ChatBot = new QPushButton(centralwidget);
        pushButton_ChatBot->setObjectName("pushButton_ChatBot");
        pushButton_ChatBot->setGeometry(QRect(1030, 80, 141, 41));
        pushButton_ChatBot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    border: none;\n"
"    color: white;\n"
"    padding: 10px 20px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 16px;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}"));
        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(640, 90, 200, 31));
        searchLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: rgb(0, 162, 198);\n"
"    selection-color: white;\n"
"    color: black;\n"
"}"));
        sortComboBox = new QComboBox(centralwidget);
        sortComboBox->setObjectName("sortComboBox");
        sortComboBox->setGeometry(QRect(850, 90, 169, 31));
        sortComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"	font: 11pt \"Segoe UI\";\n"
"    background: white;\n"
"    color: black;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: white;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"}\n"
"\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                                stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
"}\n"
"\n"
"QComboBox:on {\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border-left-width: 1px;\n"
"    border-left-color: dark"
                        "gray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 10px;\n"
"    border-bottom-right-radius: 10px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow-down.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        label_tri = new QLabel(centralwidget);
        label_tri->setObjectName("label_tri");
        label_tri->setGeometry(QRect(860, 60, 131, 21));
        label_tri->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";"));
        label_tri->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_Ouvrir = new QPushButton(centralwidget);
        pushButton_Ouvrir->setObjectName("pushButton_Ouvrir");
        pushButton_Ouvrir->setGeometry(QRect(1040, 460, 151, 31));
        pushButton_Ouvrir->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        GLocataire->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GLocataire);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1261, 26));
        GLocataire->setMenuBar(menubar);
        statusbar = new QStatusBar(GLocataire);
        statusbar->setObjectName("statusbar");
        GLocataire->setStatusBar(statusbar);

        retranslateUi(GLocataire);

        QMetaObject::connectSlotsByName(GLocataire);
    } // setupUi

    void retranslateUi(QMainWindow *GLocataire)
    {
        GLocataire->setWindowTitle(QCoreApplication::translate("GLocataire", "GEvennement", nullptr));
        line_NOMLoc->setPlaceholderText(QCoreApplication::translate("GLocataire", "            NOM", nullptr));
        line_PhoneLoc->setPlaceholderText(QCoreApplication::translate("GLocataire", "             TEL", nullptr));
        line_CONTRATLoc->setText(QString());
        line_CONTRATLoc->setPlaceholderText(QCoreApplication::translate("GLocataire", "          CONTRAT", nullptr));
        line_MAILLoc->setPlaceholderText(QCoreApplication::translate("GLocataire", "             MAIL", nullptr));
        line_IDLoc->setPlaceholderText(QCoreApplication::translate("GLocataire", "               ID", nullptr));
        comboBox_StatutPaiement->setItemText(0, QCoreApplication::translate("GLocataire", "Pay\303\251", nullptr));
        comboBox_StatutPaiement->setItemText(1, QCoreApplication::translate("GLocataire", "Non pay\303\251", nullptr));

        line_MONTANT_LOYERLOC->setPlaceholderText(QCoreApplication::translate("GLocataire", "    MONTANT LOYER", nullptr));
        line_TYPELoc->setPlaceholderText(QCoreApplication::translate("GLocataire", "             TYPE", nullptr));
        line_IDENTIFIANT->setPlaceholderText(QCoreApplication::translate("GLocataire", "          IDENTIFIANT", nullptr));
        pushButton_Ajouter->setText(QCoreApplication::translate("GLocataire", "Ajouter", nullptr));
        pushButton_Supprimer->setText(QCoreApplication::translate("GLocataire", "Supprimer", nullptr));
        pushButton_Modifier->setText(QCoreApplication::translate("GLocataire", "Modifier", nullptr));
        label_TITLE->setText(QCoreApplication::translate("GLocataire", "Gestion des locataires", nullptr));
        lbl_Image_Display->setText(QString());
        pushButton_Dashboard->setText(QCoreApplication::translate("GLocataire", "Dashboard", nullptr));
        pushButton_Employes->setText(QCoreApplication::translate("GLocataire", "Employ\303\251s", nullptr));
        pushButton_Boutiques->setText(QCoreApplication::translate("GLocataire", "Boutiques", nullptr));
        pushButton_Locataires->setText(QCoreApplication::translate("GLocataire", "Locataires", nullptr));
        pushButton_Services->setText(QCoreApplication::translate("GLocataire", "Services", nullptr));
        pushButton_Evennements->setText(QCoreApplication::translate("GLocataire", "Evennements", nullptr));
        pushButton_deconnecter->setText(QCoreApplication::translate("GLocataire", "se d\303\251connecter", nullptr));
        lbl_Logo_Display->setText(QString());
        pushButton_Retreive->setText(QCoreApplication::translate("GLocataire", "Retreive", nullptr));
        stat->setText(QCoreApplication::translate("GLocataire", "STATISTIQUES", nullptr));
        PDF->setText(QCoreApplication::translate("GLocataire", "PDF", nullptr));
        pushButton_ChatBot->setText(QCoreApplication::translate("GLocataire", "ChatBot", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("GLocataire", "Rechercher par nom...", nullptr));
        label_tri->setText(QCoreApplication::translate("GLocataire", "Trier par montant", nullptr));
        pushButton_Ouvrir->setText(QCoreApplication::translate("GLocataire", "ouvrir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GLocataire: public Ui_GLocataire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOCATAIRES_H
