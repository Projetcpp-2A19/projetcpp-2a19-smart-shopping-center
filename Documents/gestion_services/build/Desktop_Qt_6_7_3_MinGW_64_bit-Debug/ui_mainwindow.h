/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QPushButton *pushButton_Modifier;
    QLineEdit *lineEdit;
    QComboBox *comboBox_tri;
    QFrame *frame_gestions;
    QPushButton *pushButton_Dashboard;
    QPushButton *pushButton_Employes;
    QPushButton *pushButton_Boutiques;
    QPushButton *pushButton_Locataires;
    QPushButton *pushButton_Services;
    QPushButton *pushButton_Evennements;
    QPushButton *pushButton_deconnecter;
    QProgressBar *progressBar;
    QLabel *label_TITLE;
    QPushButton *pushButton_Supprimer;
    QLabel *lbl_Image_Display;
    QFrame *frame;
    QLineEdit *lineEdit_cible;
    QLineEdit *lineEdit_statut;
    QLineEdit *lineEdit_priorite;
    QLineEdit *lineEdit_type;
    QLineEdit *lineEdit_ID;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton_Ajouter;
    QLineEdit *lineEdit_exporter;
    QPushButton *pushButton_Modifier_2;
    QProgressBar *progressBar_2;
    QPushButton *pushButton_Supprimer_2;
    QPushButton *pushButton_Ajouter_2;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName("commandLinkButton");
        commandLinkButton->setGeometry(QRect(530, 150, 101, 41));
        commandLinkButton->setStyleSheet(QString::fromUtf8("QCommandLinkButton {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_Modifier = new QPushButton(centralwidget);
        pushButton_Modifier->setObjectName("pushButton_Modifier");
        pushButton_Modifier->setGeometry(QRect(930, 670, 121, 31));
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
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(500, 200, 191, 26));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 9pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 20px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        comboBox_tri = new QComboBox(centralwidget);
        comboBox_tri->setObjectName("comboBox_tri");
        comboBox_tri->setGeometry(QRect(950, 350, 91, 26));
        frame_gestions = new QFrame(centralwidget);
        frame_gestions->setObjectName("frame_gestions");
        frame_gestions->setGeometry(QRect(0, 40, 181, 891));
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
        pushButton_Dashboard->setGeometry(QRect(0, 40, 181, 51));
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
        pushButton_Employes->setGeometry(QRect(0, 90, 181, 51));
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
        pushButton_Boutiques->setGeometry(QRect(0, 140, 181, 51));
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
        pushButton_Locataires->setGeometry(QRect(0, 190, 181, 51));
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
        pushButton_Services->setGeometry(QRect(0, 240, 181, 51));
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
        pushButton_Evennements->setGeometry(QRect(0, 290, 181, 51));
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
        pushButton_deconnecter->setGeometry(QRect(0, 470, 181, 51));
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
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(940, 620, 118, 23));
        progressBar->setValue(24);
        label_TITLE = new QLabel(centralwidget);
        label_TITLE->setObjectName("label_TITLE");
        label_TITLE->setGeometry(QRect(210, 10, 581, 81));
        label_TITLE->setStyleSheet(QString::fromUtf8("color: rgb(0, 162, 198);\n"
"\n"
"font: 700 27pt \"Segoe UI\";"));
        pushButton_Supprimer = new QPushButton(centralwidget);
        pushButton_Supprimer->setObjectName("pushButton_Supprimer");
        pushButton_Supprimer->setGeometry(QRect(780, 670, 121, 31));
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
        lbl_Image_Display = new QLabel(centralwidget);
        lbl_Image_Display->setObjectName("lbl_Image_Display");
        lbl_Image_Display->setEnabled(true);
        lbl_Image_Display->setGeometry(QRect(890, 170, 151, 121));
        lbl_Image_Display->setPixmap(QPixmap(QString::fromUtf8("../../../photo.jpg")));
        lbl_Image_Display->setScaledContents(true);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(210, 120, 271, 331));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 3px solid grey;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"     border-radius: 10px;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_cible = new QLineEdit(frame);
        lineEdit_cible->setObjectName("lineEdit_cible");
        lineEdit_cible->setGeometry(QRect(40, 120, 191, 26));
        lineEdit_cible->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_statut = new QLineEdit(frame);
        lineEdit_statut->setObjectName("lineEdit_statut");
        lineEdit_statut->setGeometry(QRect(40, 160, 191, 26));
        lineEdit_statut->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_priorite = new QLineEdit(frame);
        lineEdit_priorite->setObjectName("lineEdit_priorite");
        lineEdit_priorite->setGeometry(QRect(40, 200, 191, 26));
        lineEdit_priorite->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_type = new QLineEdit(frame);
        lineEdit_type->setObjectName("lineEdit_type");
        lineEdit_type->setGeometry(QRect(40, 80, 191, 26));
        lineEdit_type->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_ID = new QLineEdit(frame);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(40, 40, 191, 26));
        lineEdit_ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        comboBox = new QComboBox(frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(80, 240, 101, 22));
        comboBox_2 = new QComboBox(frame);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(50, 280, 171, 22));
        pushButton_Ajouter = new QPushButton(centralwidget);
        pushButton_Ajouter->setObjectName("pushButton_Ajouter");
        pushButton_Ajouter->setGeometry(QRect(780, 620, 121, 31));
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
        lineEdit_exporter = new QLineEdit(centralwidget);
        lineEdit_exporter->setObjectName("lineEdit_exporter");
        lineEdit_exporter->setEnabled(false);
        lineEdit_exporter->setGeometry(QRect(930, 310, 101, 26));
        lineEdit_exporter->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 9pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 20px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_Modifier_2 = new QPushButton(centralwidget);
        pushButton_Modifier_2->setObjectName("pushButton_Modifier_2");
        pushButton_Modifier_2->setGeometry(QRect(660, 510, 121, 31));
        pushButton_Modifier_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        progressBar_2 = new QProgressBar(centralwidget);
        progressBar_2->setObjectName("progressBar_2");
        progressBar_2->setGeometry(QRect(670, 460, 118, 23));
        progressBar_2->setValue(24);
        pushButton_Supprimer_2 = new QPushButton(centralwidget);
        pushButton_Supprimer_2->setObjectName("pushButton_Supprimer_2");
        pushButton_Supprimer_2->setGeometry(QRect(510, 510, 121, 31));
        pushButton_Supprimer_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_Ajouter_2 = new QPushButton(centralwidget);
        pushButton_Ajouter_2->setObjectName("pushButton_Ajouter_2");
        pushButton_Ajouter_2->setGeometry(QRect(510, 460, 121, 31));
        pushButton_Ajouter_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(510, 240, 256, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        commandLinkButton->setText(QString());
        pushButton_Modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "trier les services", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Trier les \303\251v\303\251nements ", nullptr));
        pushButton_Dashboard->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        pushButton_Employes->setText(QCoreApplication::translate("MainWindow", "Employ\303\251s", nullptr));
        pushButton_Boutiques->setText(QCoreApplication::translate("MainWindow", "Boutiques", nullptr));
        pushButton_Locataires->setText(QCoreApplication::translate("MainWindow", "Locataires", nullptr));
        pushButton_Services->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        pushButton_Evennements->setText(QCoreApplication::translate("MainWindow", "Evennements", nullptr));
        pushButton_deconnecter->setText(QCoreApplication::translate("MainWindow", "se d\303\251connecter", nullptr));
        label_TITLE->setText(QCoreApplication::translate("MainWindow", "Gestion des services", nullptr));
        pushButton_Supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        lbl_Image_Display->setText(QString());
        lineEdit_cible->setText(QString());
        lineEdit_cible->setPlaceholderText(QCoreApplication::translate("MainWindow", "         CIBLE", nullptr));
        lineEdit_statut->setText(QString());
        lineEdit_statut->setPlaceholderText(QCoreApplication::translate("MainWindow", "         STATUE", nullptr));
        lineEdit_priorite->setText(QString());
        lineEdit_priorite->setPlaceholderText(QCoreApplication::translate("MainWindow", "          Priorite", nullptr));
        lineEdit_type->setText(QString());
        lineEdit_type->setPlaceholderText(QCoreApplication::translate("MainWindow", "             TYPE", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_ID->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_ID->setText(QString());
        lineEdit_ID->setPlaceholderText(QCoreApplication::translate("MainWindow", "               ID", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "disponibilit\303\251", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "1", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("MainWindow", "disponibilit\303\251", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "le service le plus demander", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "le service le moins demander", nullptr));

        pushButton_Ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        lineEdit_exporter->setPlaceholderText(QCoreApplication::translate("MainWindow", "    Exporter", nullptr));
        pushButton_Modifier_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_Supprimer_2->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_Ajouter_2->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
