/********************************************************************************
** Form generated from reading UI file 'gevennement.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEVENNEMENT_H
#define UI_GEVENNEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QLineEdit *line_PRIXevent;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *line_TYPEevent;
    QLineEdit *line_IDevent;
    QLineEdit *lineEdit_IDENTIFIANT;
    QComboBox *comboBox_LOC;
    QDateEdit *dateEditDebut;
    QDateEdit *dateEditFin;
    QLineEdit *line_LIEU;
    QPushButton *pushButton_Map;
    QLineEdit *line_LOCATIONevent;
    QLineEdit *line_CAPACITEevent;
    QFrame *frame_5;
    QLineEdit *line_NOMevent_2;
    QLineEdit *line_PRIXevent_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *line_TYPEevent_2;
    QLineEdit *line_IDevent_2;
    QLineEdit *lineEdit_IDENTIFIANT_2;
    QComboBox *comboBox_LOC_2;
    QDateEdit *dateEditDebut_2;
    QDateEdit *dateEditFin_2;
    QLineEdit *line_LIEU_2;
    QPushButton *pushButton_Map_2;
    QLineEdit *line_LOCATIONevent_2;
    QLineEdit *line_CAPACITEevent_2;
    QPushButton *pushButton_Ajouter;
    QPushButton *pushButton_Supprimer;
    QPushButton *pushButton_Modifier;
    QLabel *label_TITLE;
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
    QTableView *tableView;
    QFrame *frame_4;
    QLineEdit *lineEdit_Recherche;
    QPushButton *pushButton_Rechercher;
    QPushButton *pushButton_TriType;
    QPushButton *pushButton_TriDate;
    QPushButton *pushButton_Retreive;
    QPushButton *pushButton_PDF;
    QPushButton *pushButton_Modifier_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GEvennement)
    {
        if (GEvennement->objectName().isEmpty())
            GEvennement->setObjectName("GEvennement");
        GEvennement->resize(1116, 759);
        GEvennement->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background: #f0c1cd;  \n"
"}\n"
"\n"
"\n"
""));
        GEvennement->setAnimated(true);
        centralwidget = new QWidget(GEvennement);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(190, 120, 301, 561));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 3px solid grey;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"     border-radius: 10px;\n"
"    background-color:  rgb(0, 162, 198);\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        line_NOMevent = new QLineEdit(frame);
        line_NOMevent->setObjectName("line_NOMevent");
        line_NOMevent->setGeometry(QRect(40, 50, 191, 26));
        line_NOMevent->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_PRIXevent = new QLineEdit(frame);
        line_PRIXevent->setObjectName("line_PRIXevent");
        line_PRIXevent->setGeometry(QRect(40, 310, 191, 26));
        line_PRIXevent->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 110, 91, 31));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 170, 91, 31));
        line_TYPEevent = new QLineEdit(frame);
        line_TYPEevent->setObjectName("line_TYPEevent");
        line_TYPEevent->setGeometry(QRect(40, 80, 191, 26));
        line_TYPEevent->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_IDevent = new QLineEdit(frame);
        line_IDevent->setObjectName("line_IDevent");
        line_IDevent->setEnabled(false);
        line_IDevent->setGeometry(QRect(40, 20, 191, 26));
        line_IDevent->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_IDENTIFIANT = new QLineEdit(frame);
        lineEdit_IDENTIFIANT->setObjectName("lineEdit_IDENTIFIANT");
        lineEdit_IDENTIFIANT->setGeometry(QRect(40, 390, 191, 26));
        lineEdit_IDENTIFIANT->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        comboBox_LOC = new QComboBox(frame);
        comboBox_LOC->setObjectName("comboBox_LOC");
        comboBox_LOC->setGeometry(QRect(40, 350, 191, 26));
        comboBox_LOC->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        dateEditDebut = new QDateEdit(frame);
        dateEditDebut->setObjectName("dateEditDebut");
        dateEditDebut->setGeometry(QRect(40, 140, 181, 26));
        dateEditFin = new QDateEdit(frame);
        dateEditFin->setObjectName("dateEditFin");
        dateEditFin->setGeometry(QRect(40, 200, 181, 26));
        line_LIEU = new QLineEdit(frame);
        line_LIEU->setObjectName("line_LIEU");
        line_LIEU->setGeometry(QRect(40, 240, 141, 26));
        line_LIEU->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_Map = new QPushButton(frame);
        pushButton_Map->setObjectName("pushButton_Map");
        pushButton_Map->setGeometry(QRect(180, 240, 61, 31));
        pushButton_Map->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        line_LOCATIONevent = new QLineEdit(frame);
        line_LOCATIONevent->setObjectName("line_LOCATIONevent");
        line_LOCATIONevent->setGeometry(QRect(40, 270, 181, 26));
        line_LOCATIONevent->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_CAPACITEevent = new QLineEdit(frame);
        line_CAPACITEevent->setObjectName("line_CAPACITEevent");
        line_CAPACITEevent->setGeometry(QRect(40, 270, 191, 26));
        line_CAPACITEevent->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        frame_5 = new QFrame(frame);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(0, 0, 301, 561));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 3px solid grey;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"     border-radius: 10px;\n"
"    background-color:  rgb(0, 162, 198);\n"
"}"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        line_NOMevent_2 = new QLineEdit(frame_5);
        line_NOMevent_2->setObjectName("line_NOMevent_2");
        line_NOMevent_2->setGeometry(QRect(60, 70, 191, 26));
        line_NOMevent_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_PRIXevent_2 = new QLineEdit(frame_5);
        line_PRIXevent_2->setObjectName("line_PRIXevent_2");
        line_PRIXevent_2->setGeometry(QRect(50, 390, 191, 26));
        line_PRIXevent_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        label_3 = new QLabel(frame_5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 160, 91, 31));
        label_4 = new QLabel(frame_5);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 220, 91, 31));
        line_TYPEevent_2 = new QLineEdit(frame_5);
        line_TYPEevent_2->setObjectName("line_TYPEevent_2");
        line_TYPEevent_2->setGeometry(QRect(60, 120, 191, 26));
        line_TYPEevent_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_IDevent_2 = new QLineEdit(frame_5);
        line_IDevent_2->setObjectName("line_IDevent_2");
        line_IDevent_2->setEnabled(false);
        line_IDevent_2->setGeometry(QRect(60, 30, 191, 26));
        line_IDevent_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        lineEdit_IDENTIFIANT_2 = new QLineEdit(frame_5);
        lineEdit_IDENTIFIANT_2->setObjectName("lineEdit_IDENTIFIANT_2");
        lineEdit_IDENTIFIANT_2->setGeometry(QRect(50, 490, 191, 26));
        lineEdit_IDENTIFIANT_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        comboBox_LOC_2 = new QComboBox(frame_5);
        comboBox_LOC_2->setObjectName("comboBox_LOC_2");
        comboBox_LOC_2->setGeometry(QRect(50, 440, 191, 26));
        comboBox_LOC_2->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        dateEditDebut_2 = new QDateEdit(frame_5);
        dateEditDebut_2->setObjectName("dateEditDebut_2");
        dateEditDebut_2->setGeometry(QRect(60, 190, 181, 26));
        dateEditFin_2 = new QDateEdit(frame_5);
        dateEditFin_2->setObjectName("dateEditFin_2");
        dateEditFin_2->setGeometry(QRect(60, 250, 181, 26));
        line_LIEU_2 = new QLineEdit(frame_5);
        line_LIEU_2->setObjectName("line_LIEU_2");
        line_LIEU_2->setGeometry(QRect(50, 300, 141, 26));
        line_LIEU_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_Map_2 = new QPushButton(frame_5);
        pushButton_Map_2->setObjectName("pushButton_Map_2");
        pushButton_Map_2->setGeometry(QRect(190, 300, 61, 31));
        pushButton_Map_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        line_LOCATIONevent_2 = new QLineEdit(frame_5);
        line_LOCATIONevent_2->setObjectName("line_LOCATIONevent_2");
        line_LOCATIONevent_2->setGeometry(QRect(50, 350, 181, 26));
        line_LOCATIONevent_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        line_CAPACITEevent_2 = new QLineEdit(frame_5);
        line_CAPACITEevent_2->setObjectName("line_CAPACITEevent_2");
        line_CAPACITEevent_2->setGeometry(QRect(50, 350, 191, 26));
        line_CAPACITEevent_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_Ajouter = new QPushButton(centralwidget);
        pushButton_Ajouter->setObjectName("pushButton_Ajouter");
        pushButton_Ajouter->setGeometry(QRect(550, 470, 121, 31));
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
        pushButton_Supprimer->setGeometry(QRect(710, 470, 121, 31));
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
        pushButton_Modifier->setGeometry(QRect(880, 470, 131, 31));
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
        label_TITLE->setGeometry(QRect(340, 20, 581, 81));
        label_TITLE->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 36pt \"Imprint MT Shadow\";\n"
"    color: rgb(0, 162, 198);\n"
"    text-shadow: 2px 2px 4px rgba(0, 0, 0, 80); /* Ajout d'un effet d'ombre */\n"
"}\n"
""));
        lbl_Image_Display = new QLabel(centralwidget);
        lbl_Image_Display->setObjectName("lbl_Image_Display");
        lbl_Image_Display->setEnabled(true);
        lbl_Image_Display->setGeometry(QRect(660, 20, 151, 121));
        lbl_Image_Display->setPixmap(QPixmap(QString::fromUtf8("../../../photo.jpg")));
        lbl_Image_Display->setScaledContents(true);
        frame_gestions = new QFrame(centralwidget);
        frame_gestions->setObjectName("frame_gestions");
        frame_gestions->setGeometry(QRect(0, 0, 181, 931));
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
        pushButton_Dashboard->setGeometry(QRect(0, 150, 181, 51));
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
        pushButton_Employes->setGeometry(QRect(0, 200, 181, 51));
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
        pushButton_Boutiques->setGeometry(QRect(0, 250, 181, 51));
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
        pushButton_Locataires->setGeometry(QRect(0, 300, 181, 51));
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
        pushButton_Services->setGeometry(QRect(0, 350, 181, 51));
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
        pushButton_Evennements->setGeometry(QRect(0, 400, 181, 51));
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
        frame_3->setGeometry(QRect(180, -10, 1051, 31));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: rgb(0, 162, 198);\n"
"    border: 2px solid #00a2c6;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}\n"
""));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(510, 200, 521, 241));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
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
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(500, 130, 611, 51));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 3px solid grey;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"     border-radius: 10px;\n"
"    background-color:  rgb(0, 162, 198);\n"
"}"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_Recherche = new QLineEdit(frame_4);
        lineEdit_Recherche->setObjectName("lineEdit_Recherche");
        lineEdit_Recherche->setGeometry(QRect(30, 10, 181, 31));
        lineEdit_Recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton_Rechercher = new QPushButton(frame_4);
        pushButton_Rechercher->setObjectName("pushButton_Rechercher");
        pushButton_Rechercher->setGeometry(QRect(220, 10, 121, 31));
        pushButton_Rechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_TriType = new QPushButton(frame_4);
        pushButton_TriType->setObjectName("pushButton_TriType");
        pushButton_TriType->setGeometry(QRect(370, 10, 101, 31));
        pushButton_TriType->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_TriDate = new QPushButton(frame_4);
        pushButton_TriDate->setObjectName("pushButton_TriDate");
        pushButton_TriDate->setGeometry(QRect(490, 10, 101, 31));
        pushButton_TriDate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_Retreive = new QPushButton(centralwidget);
        pushButton_Retreive->setObjectName("pushButton_Retreive");
        pushButton_Retreive->setGeometry(QRect(550, 510, 121, 31));
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
        pushButton_PDF = new QPushButton(centralwidget);
        pushButton_PDF->setObjectName("pushButton_PDF");
        pushButton_PDF->setGeometry(QRect(710, 510, 121, 31));
        pushButton_PDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_Modifier_2->setObjectName("pushButton_Modifier_2");
        pushButton_Modifier_2->setGeometry(QRect(880, 510, 131, 31));
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
        GEvennement->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GEvennement);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1116, 26));
        GEvennement->setMenuBar(menubar);
        statusbar = new QStatusBar(GEvennement);
        statusbar->setObjectName("statusbar");
        GEvennement->setStatusBar(statusbar);

        retranslateUi(GEvennement);

        QMetaObject::connectSlotsByName(GEvennement);
    } // setupUi

    void retranslateUi(QMainWindow *GEvennement)
    {
        GEvennement->setWindowTitle(QCoreApplication::translate("GEvennement", "GEvennement", nullptr));
        line_NOMevent->setPlaceholderText(QCoreApplication::translate("GEvennement", "            NOM", nullptr));
        line_PRIXevent->setPlaceholderText(QCoreApplication::translate("GEvennement", "             PRIX", nullptr));
        label->setText(QCoreApplication::translate("GEvennement", "Date d\303\251but", nullptr));
        label_2->setText(QCoreApplication::translate("GEvennement", "Date fin", nullptr));
        line_TYPEevent->setPlaceholderText(QCoreApplication::translate("GEvennement", "             TYPE", nullptr));
        line_IDevent->setPlaceholderText(QCoreApplication::translate("GEvennement", "               ID", nullptr));
        lineEdit_IDENTIFIANT->setPlaceholderText(QCoreApplication::translate("GEvennement", "     IDENTIFIANT", nullptr));
        comboBox_LOC->setPlaceholderText(QCoreApplication::translate("GEvennement", "           LOCATAIRES", nullptr));
        line_LIEU->setText(QString());
        line_LIEU->setPlaceholderText(QCoreApplication::translate("GEvennement", "             LIEU", nullptr));
        pushButton_Map->setText(QCoreApplication::translate("GEvennement", "MAP", nullptr));
        line_LOCATIONevent->setPlaceholderText(QCoreApplication::translate("GEvennement", "             LIEU", nullptr));
        line_CAPACITEevent->setPlaceholderText(QCoreApplication::translate("GEvennement", "         CAPACITE", nullptr));
        line_NOMevent_2->setPlaceholderText(QCoreApplication::translate("GEvennement", "            NOM", nullptr));
        line_PRIXevent_2->setPlaceholderText(QCoreApplication::translate("GEvennement", "             PRIX", nullptr));
        label_3->setText(QCoreApplication::translate("GEvennement", "Date d\303\251but", nullptr));
        label_4->setText(QCoreApplication::translate("GEvennement", "Date fin", nullptr));
        line_TYPEevent_2->setPlaceholderText(QCoreApplication::translate("GEvennement", "             TYPE", nullptr));
        line_IDevent_2->setPlaceholderText(QCoreApplication::translate("GEvennement", "               ID", nullptr));
        lineEdit_IDENTIFIANT_2->setPlaceholderText(QCoreApplication::translate("GEvennement", "     IDENTIFIANT", nullptr));
        comboBox_LOC_2->setPlaceholderText(QCoreApplication::translate("GEvennement", "           LOCATAIRES", nullptr));
        line_LIEU_2->setText(QString());
        line_LIEU_2->setPlaceholderText(QCoreApplication::translate("GEvennement", "             LIEU", nullptr));
        pushButton_Map_2->setText(QCoreApplication::translate("GEvennement", "MAP", nullptr));
        line_LOCATIONevent_2->setPlaceholderText(QCoreApplication::translate("GEvennement", "             LIEU", nullptr));
        line_CAPACITEevent_2->setPlaceholderText(QCoreApplication::translate("GEvennement", "         CAPACITE", nullptr));
        pushButton_Ajouter->setText(QCoreApplication::translate("GEvennement", "Ajouter", nullptr));
        pushButton_Supprimer->setText(QCoreApplication::translate("GEvennement", "Supprimer", nullptr));
        pushButton_Modifier->setText(QCoreApplication::translate("GEvennement", "Modifier", nullptr));
        label_TITLE->setText(QCoreApplication::translate("GEvennement", "Gestion des \303\251v\303\251nements", nullptr));
        lbl_Image_Display->setText(QString());
        pushButton_Dashboard->setText(QCoreApplication::translate("GEvennement", "Dashboard", nullptr));
        pushButton_Employes->setText(QCoreApplication::translate("GEvennement", "Employ\303\251s", nullptr));
        pushButton_Boutiques->setText(QCoreApplication::translate("GEvennement", "Boutiques", nullptr));
        pushButton_Locataires->setText(QCoreApplication::translate("GEvennement", "Locataires", nullptr));
        pushButton_Services->setText(QCoreApplication::translate("GEvennement", "Services", nullptr));
        pushButton_Evennements->setText(QCoreApplication::translate("GEvennement", "Evennements", nullptr));
        pushButton_deconnecter->setText(QCoreApplication::translate("GEvennement", "se d\303\251connecter", nullptr));
        lbl_Logo_Display->setText(QString());
        lineEdit_Recherche->setPlaceholderText(QCoreApplication::translate("GEvennement", "   Recherche par id", nullptr));
        pushButton_Rechercher->setText(QCoreApplication::translate("GEvennement", "Rechercher", nullptr));
        pushButton_TriType->setText(QCoreApplication::translate("GEvennement", "Tri Type", nullptr));
        pushButton_TriDate->setText(QCoreApplication::translate("GEvennement", "Tri date", nullptr));
        pushButton_Retreive->setText(QCoreApplication::translate("GEvennement", "Retreive", nullptr));
        pushButton_PDF->setText(QCoreApplication::translate("GEvennement", "PDF", nullptr));
        pushButton_Modifier_2->setText(QCoreApplication::translate("GEvennement", "STAT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GEvennement: public Ui_GEvennement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEVENNEMENT_H
