/********************************************************************************
** Form generated from reading UI file 'gevennement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEVENNEMENT_H
#define UI_GEVENNEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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

class Ui_GEvennement
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *line_NOMevent;
    QLineEdit *line_CAPACITEevent;
    QLineEdit *line_PRIXevent;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *line_TYPEevent;
    QLineEdit *line_IDevent;
    QDateEdit *dateEditDebut;
    QDateEdit *dateEditFin;
    QLineEdit *line_LIEU;
    QComboBox *comboBox_LOC;
    QLineEdit *lineEdit_IDENTIFIANT;
    QLineEdit *line_LOCATIONevent;
    QPushButton *pushButton_Map;
    QFrame *frame_recherche;
    QLineEdit *lineEdit_Recherche;
    QPushButton *pushButton_Rechercher;
    QPushButton *pushButton_TriType;
    QPushButton *pushButton_TriDate;
    QPushButton *pushButton_Ajouter;
    QPushButton *pushButton_Supprimer;
    QPushButton *pushButton_Modifier;
    QLabel *label_titre;
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
    QPushButton *pushButton_PDF;
    QPushButton *pushButton_Modifier_2;
    QPushButton *pushButton_Modifier_3;
    QPushButton *MAP;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GEvennement)
    {
        if (GEvennement->objectName().isEmpty())
            GEvennement->setObjectName(QStringLiteral("GEvennement"));
        GEvennement->resize(1028, 599);
        GEvennement->setStyleSheet(QLatin1String("QMainWindow {\n"
"    background: #f0c1cd;  \n"
"}\n"
"\n"
"\n"
""));
        GEvennement->setAnimated(true);
        centralwidget = new QWidget(GEvennement);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(210, 110, 271, 421));
        frame->setStyleSheet(QLatin1String("QFrame{\n"
"    border: 3px solid grey;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"     border-radius: 10px;\n"
"    background-color:  rgb(0, 162, 198);\n"
"}"));
        frame->setFrameShape(QFrame::NoFrame);
        line_NOMevent = new QLineEdit(frame);
        line_NOMevent->setObjectName(QStringLiteral("line_NOMevent"));
        line_NOMevent->setGeometry(QRect(40, 60, 191, 26));
        line_NOMevent->setStyleSheet(QLatin1String("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_CAPACITEevent = new QLineEdit(frame);
        line_CAPACITEevent->setObjectName(QStringLiteral("line_CAPACITEevent"));
        line_CAPACITEevent->setGeometry(QRect(40, 290, 191, 26));
        line_CAPACITEevent->setStyleSheet(QLatin1String("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_PRIXevent = new QLineEdit(frame);
        line_PRIXevent->setObjectName(QStringLiteral("line_PRIXevent"));
        line_PRIXevent->setGeometry(QRect(40, 330, 191, 26));
        line_PRIXevent->setStyleSheet(QLatin1String("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 140, 91, 31));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 200, 91, 31));
        line_TYPEevent = new QLineEdit(frame);
        line_TYPEevent->setObjectName(QStringLiteral("line_TYPEevent"));
        line_TYPEevent->setGeometry(QRect(40, 100, 191, 26));
        line_TYPEevent->setStyleSheet(QLatin1String("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_IDevent = new QLineEdit(frame);
        line_IDevent->setObjectName(QStringLiteral("line_IDevent"));
        line_IDevent->setEnabled(false);
        line_IDevent->setGeometry(QRect(40, 20, 191, 26));
        line_IDevent->setStyleSheet(QLatin1String("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        dateEditDebut = new QDateEdit(frame);
        dateEditDebut->setObjectName(QStringLiteral("dateEditDebut"));
        dateEditDebut->setGeometry(QRect(10, 170, 251, 22));
        dateEditFin = new QDateEdit(frame);
        dateEditFin->setObjectName(QStringLiteral("dateEditFin"));
        dateEditFin->setGeometry(QRect(10, 230, 251, 22));
        line_LIEU = new QLineEdit(frame);
        line_LIEU->setObjectName(QStringLiteral("line_LIEU"));
        line_LIEU->setGeometry(QRect(40, 260, 191, 26));
        line_LIEU->setStyleSheet(QLatin1String("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        comboBox_LOC = new QComboBox(frame);
        comboBox_LOC->setObjectName(QStringLiteral("comboBox_LOC"));
        comboBox_LOC->setGeometry(QRect(40, 360, 181, 22));
        lineEdit_IDENTIFIANT = new QLineEdit(frame);
        lineEdit_IDENTIFIANT->setObjectName(QStringLiteral("lineEdit_IDENTIFIANT"));
        lineEdit_IDENTIFIANT->setGeometry(QRect(40, 390, 181, 22));
        line_LOCATIONevent = new QLineEdit(frame);
        line_LOCATIONevent->setObjectName(QStringLiteral("line_LOCATIONevent"));
        line_LOCATIONevent->setGeometry(QRect(40, 250, 191, 26));
        line_LOCATIONevent->setStyleSheet(QLatin1String("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_LOCATIONevent->setReadOnly(true);
        pushButton_Map = new QPushButton(frame);
        pushButton_Map->setObjectName(QStringLiteral("pushButton_Map"));
        pushButton_Map->setGeometry(QRect(240, 250, 25, 25));
        pushButton_Map->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    border: none;\n"
"    color: white;\n"
"    border-radius: 12px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}"));
        frame_recherche = new QFrame(centralwidget);
        frame_recherche->setObjectName(QStringLiteral("frame_recherche"));
        frame_recherche->setGeometry(QRect(500, 110, 501, 41));
        frame_recherche->setStyleSheet(QLatin1String("QFrame{\n"
"    border: 3px solid grey;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"    border-radius: 10px;\n"
"    background-color:  rgb(0, 162, 198);\n"
"}"));
        frame_recherche->setFrameShape(QFrame::NoFrame);
        lineEdit_Recherche = new QLineEdit(frame_recherche);
        lineEdit_Recherche->setObjectName(QStringLiteral("lineEdit_Recherche"));
        lineEdit_Recherche->setGeometry(QRect(10, 5, 180, 30));
        lineEdit_Recherche->setStyleSheet(QLatin1String("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_Rechercher = new QPushButton(frame_recherche);
        pushButton_Rechercher->setObjectName(QStringLiteral("pushButton_Rechercher"));
        pushButton_Rechercher->setGeometry(QRect(200, 5, 91, 30));
        pushButton_Rechercher->setStyleSheet(QLatin1String("QPushButton {\n"
"	font: 11pt \"Segoe UI\";\n"
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
"    border: none;\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy;\n"
"}"));
        pushButton_TriType = new QPushButton(frame_recherche);
        pushButton_TriType->setObjectName(QStringLiteral("pushButton_TriType"));
        pushButton_TriType->setGeometry(QRect(300, 5, 91, 30));
        pushButton_TriType->setStyleSheet(QLatin1String("QPushButton {\n"
"	font: 11pt \"Segoe UI\";\n"
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
"    border: none;\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy;\n"
"}"));
        pushButton_TriDate = new QPushButton(frame_recherche);
        pushButton_TriDate->setObjectName(QStringLiteral("pushButton_TriDate"));
        pushButton_TriDate->setGeometry(QRect(400, 5, 91, 30));
        pushButton_TriDate->setStyleSheet(QLatin1String("QPushButton {\n"
"	font: 11pt \"Segoe UI\";\n"
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
"    border: none;\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy;\n"
"}"));
        pushButton_Ajouter = new QPushButton(centralwidget);
        pushButton_Ajouter->setObjectName(QStringLiteral("pushButton_Ajouter"));
        pushButton_Ajouter->setGeometry(QRect(520, 460, 121, 31));
        pushButton_Ajouter->setStyleSheet(QLatin1String("QPushButton {\n"
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
        pushButton_Supprimer->setObjectName(QStringLiteral("pushButton_Supprimer"));
        pushButton_Supprimer->setGeometry(QRect(520, 510, 121, 31));
        pushButton_Supprimer->setStyleSheet(QLatin1String("QPushButton {\n"
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
        pushButton_Modifier->setObjectName(QStringLiteral("pushButton_Modifier"));
        pushButton_Modifier->setGeometry(QRect(670, 510, 121, 31));
        pushButton_Modifier->setStyleSheet(QLatin1String("QPushButton {\n"
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
        label_titre = new QLabel(centralwidget);
        label_titre->setObjectName(QStringLiteral("label_TITLE"));
        label_titre->setGeometry(QRect(190, 20, 581, 81));
        label_titre->setStyleSheet(QLatin1String("QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(500, 161, 501, 261));
        tableView->setStyleSheet(QLatin1String("QTableView {\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #999;\n"
"    selection-background-color: #0078d7;\n"
"    selection-color: white;\n"
"    gridline-color: #ccc;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #e0e0e0;\n"
"    padding: 4px;\n"
"    border: 1px solid #999;\n"
"    font-weight: bold;\n"
"}"));
        lbl_Image_Display = new QLabel(centralwidget);
        lbl_Image_Display->setObjectName(QStringLiteral("lbl_Image_Display"));
        lbl_Image_Display->setEnabled(true);
        lbl_Image_Display->setGeometry(QRect(660, 20, 151, 121));
        lbl_Image_Display->setPixmap(QPixmap(QString::fromUtf8("../../../photo.jpg")));
        lbl_Image_Display->setScaledContents(true);
        frame_gestions = new QFrame(centralwidget);
        frame_gestions->setObjectName(QStringLiteral("frame_gestions"));
        frame_gestions->setGeometry(QRect(0, 0, 181, 571));
        frame_gestions->setStyleSheet(QLatin1String("QFrame {\n"
"    background: rgb(0, 162, 198);\n"
"    border: 2px solid #00a2c6;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}\n"
""));
        frame_gestions->setFrameShape(QFrame::NoFrame);
        pushButton_Dashboard = new QPushButton(frame_gestions);
        pushButton_Dashboard->setObjectName(QStringLiteral("pushButton_Dashboard"));
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
        pushButton_Employes->setObjectName(QStringLiteral("pushButton_Employes"));
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
        pushButton_Boutiques->setObjectName(QStringLiteral("pushButton_Boutiques"));
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
        pushButton_Locataires->setObjectName(QStringLiteral("pushButton_Locataires"));
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
        pushButton_Services->setObjectName(QStringLiteral("pushButton_Services"));
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
        pushButton_Evennements->setObjectName(QStringLiteral("pushButton_Evennements"));
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
        pushButton_deconnecter->setObjectName(QStringLiteral("pushButton_deconnecter"));
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
        lbl_Logo_Display->setObjectName(QStringLiteral("lbl_Logo_Display"));
        lbl_Logo_Display->setGeometry(QRect(0, 0, 181, 91));
        lbl_Logo_Display->setPixmap(QPixmap(QString::fromUtf8("build/Desktop_Qt_6_7_3_MinGW_64_bit-Debug/debug/logo.gif")));
        lbl_Logo_Display->setScaledContents(true);
        frame_2 = new QFrame(frame_gestions);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(120, 540, 120, 80));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(180, -10, 621, 31));
        frame_3->setStyleSheet(QLatin1String("QFrame {\n"
"    background: rgb(0, 162, 198);\n"
"    border: 2px solid #00a2c6;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}\n"
""));
        frame_3->setFrameShape(QFrame::NoFrame);
        pushButton_Retreive = new QPushButton(centralwidget);
        pushButton_Retreive->setObjectName(QStringLiteral("pushButton_Retreive"));
        pushButton_Retreive->setGeometry(QRect(670, 460, 121, 31));
        pushButton_Retreive->setStyleSheet(QLatin1String("QPushButton {\n"
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
        pushButton_PDF = new QPushButton(centralwidget);
        pushButton_PDF->setObjectName(QStringLiteral("pushButton_PDF"));
        pushButton_PDF->setGeometry(QRect(820, 460, 171, 31));
        pushButton_PDF->setStyleSheet(QLatin1String("QPushButton {\n"
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
        pushButton_Modifier_2 = new QPushButton(centralwidget);
        pushButton_Modifier_2->setObjectName(QStringLiteral("pushButton_Modifier_2"));
        pushButton_Modifier_2->setGeometry(QRect(820, 510, 171, 31));
        pushButton_Modifier_2->setStyleSheet(QLatin1String("QPushButton {\n"
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
        pushButton_Modifier_3 = new QPushButton(centralwidget);
        pushButton_Modifier_3->setObjectName(QStringLiteral("pushButton_Modifier_3"));
        pushButton_Modifier_3->setGeometry(QRect(830, 60, 171, 31));
        pushButton_Modifier_3->setStyleSheet(QLatin1String("QPushButton {\n"
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
        MAP = new QPushButton(centralwidget);
        MAP->setObjectName(QStringLiteral("MAP"));
        MAP->setGeometry(QRect(830, 20, 171, 31));
        MAP->setStyleSheet(QLatin1String("QPushButton {\n"
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
        GEvennement->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GEvennement);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1028, 26));
        GEvennement->setMenuBar(menubar);
        statusbar = new QStatusBar(GEvennement);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        GEvennement->setStatusBar(statusbar);

        retranslateUi(GEvennement);

        QMetaObject::connectSlotsByName(GEvennement);
    } // setupUi

    void retranslateUi(QMainWindow *GEvennement)
    {
        GEvennement->setWindowTitle(QApplication::translate("GEvennement", "GEvennement", Q_NULLPTR));
        line_NOMevent->setPlaceholderText(QApplication::translate("GEvennement", "            NOM", Q_NULLPTR));
        line_CAPACITEevent->setPlaceholderText(QApplication::translate("GEvennement", "         CAPACITE", Q_NULLPTR));
        line_PRIXevent->setPlaceholderText(QApplication::translate("GEvennement", "             PRIX", Q_NULLPTR));
        label->setText(QApplication::translate("GEvennement", "Date d\303\251but", Q_NULLPTR));
        label_2->setText(QApplication::translate("GEvennement", "Date fin", Q_NULLPTR));
        line_TYPEevent->setPlaceholderText(QApplication::translate("GEvennement", "             TYPE", Q_NULLPTR));
        line_IDevent->setPlaceholderText(QApplication::translate("GEvennement", "               ID", Q_NULLPTR));
        line_LIEU->setPlaceholderText(QApplication::translate("GEvennement", "         LIEU", Q_NULLPTR));
        comboBox_LOC->setProperty("placeholderText", QVariant(QApplication::translate("GEvennement", "       Choisir Un Locataire", Q_NULLPTR)));
        lineEdit_IDENTIFIANT->setPlaceholderText(QApplication::translate("GEvennement", "         IDENTIFIANT", Q_NULLPTR));
        line_LOCATIONevent->setPlaceholderText(QApplication::translate("GEvennement", "         LOCATION", Q_NULLPTR));
        pushButton_Map->setText(QApplication::translate("GEvennement", "\360\237\223\215", Q_NULLPTR));
        lineEdit_Recherche->setPlaceholderText(QApplication::translate("GEvennement", "Rechercher par identifiant...", Q_NULLPTR));
        pushButton_Rechercher->setText(QApplication::translate("GEvennement", "Rechercher", Q_NULLPTR));
        pushButton_TriType->setText(QApplication::translate("GEvennement", "Tri Type", Q_NULLPTR));
        pushButton_TriDate->setText(QApplication::translate("GEvennement", "Tri Date", Q_NULLPTR));
        pushButton_Ajouter->setText(QApplication::translate("GEvennement", "Ajouter", Q_NULLPTR));
        pushButton_Supprimer->setText(QApplication::translate("GEvennement", "Supprimer", Q_NULLPTR));
        pushButton_Modifier->setText(QApplication::translate("GEvennement", "Modifier", Q_NULLPTR));
        label_titre->setText(QApplication::translate("GEvennement", "Gestion des \303\251v\303\251nements", Q_NULLPTR));
        lbl_Image_Display->setText(QString());
        pushButton_Dashboard->setText(QApplication::translate("GEvennement", "Dashboard", Q_NULLPTR));
        pushButton_Employes->setText(QApplication::translate("GEvennement", "Employ\303\251s", Q_NULLPTR));
        pushButton_Boutiques->setText(QApplication::translate("GEvennement", "Boutiques", Q_NULLPTR));
        pushButton_Locataires->setText(QApplication::translate("GEvennement", "Locataires", Q_NULLPTR));
        pushButton_Services->setText(QApplication::translate("GEvennement", "Services", Q_NULLPTR));
        pushButton_Evennements->setText(QApplication::translate("GEvennement", "Evennements", Q_NULLPTR));
        pushButton_deconnecter->setText(QApplication::translate("GEvennement", "se d\303\251connecter", Q_NULLPTR));
        lbl_Logo_Display->setText(QString());
        pushButton_Retreive->setText(QApplication::translate("GEvennement", "Retreive", Q_NULLPTR));
        pushButton_PDF->setText(QApplication::translate("GEvennement", "PDF", Q_NULLPTR));
        pushButton_Modifier_2->setText(QApplication::translate("GEvennement", "STATISTIQUES", Q_NULLPTR));
        pushButton_Modifier_3->setText(QApplication::translate("GEvennement", "SCAN", Q_NULLPTR));
        MAP->setText(QApplication::translate("GEvennement", "MAP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GEvennement: public Ui_GEvennement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEVENNEMENT_H
