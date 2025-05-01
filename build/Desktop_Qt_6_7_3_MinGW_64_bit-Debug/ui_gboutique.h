/********************************************************************************
** Form generated from reading UI file 'gboutique.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GBOUTIQUE_H
#define UI_GBOUTIQUE_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gboutique
{
public:
    QWidget *centralwidget;
    QFrame *frame_10;
    QLabel *label;
    QPushButton *pushButton_Modifier;
    QLabel *label_TITLE;
    QLabel *lbl_Image_Display;
    QTableWidget *tableWidget_Boutique;
    QFrame *frame_gestions;
    QPushButton *pushButton_Dashboard;
    QPushButton *pushButton_Employes;
    QPushButton *pushButton_Boutiques;
    QPushButton *pushButton_Locataires;
    QPushButton *pushButton_Services;
    QPushButton *pushButton_Evennements;
    QPushButton *pushButton_deconnecter;
    QLabel *lbl_Logo_Display;
    QFrame *frame_9;
    QPushButton *pushButton_Ajouter;
    QPushButton *pushButton_Supprimer;
    QFrame *frame;
    QLineEdit *line_NOMboutique;
    QLineEdit *line_TYPEboutique;
    QLineEdit *line_SURFACEboutique;
    QLabel *label_HORAIRE;
    QLineEdit *line_LOCALISATIONboutique;
    QLineEdit *line_MONTANTboutique;
    QTimeEdit *timeEdit_HORAIRE;
    QComboBox *comboBox_ETATboutique;
    QLineEdit *line_IDLOCATAIREboutique;
    QLineEdit *line_IDEMPboutique;
    QLineEdit *lineEdit_recherche_id;
    QPushButton *pushButton_recherche_boutique;
    QPushButton *pushButton_trier_boutiques;
    QPushButton *pushButton_exporter_boutiques;
    QPushButton *pushButton_vider_formulaire;
    QPushButton *pushButton_Afficher;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layoutPrincipal;
    QLineEdit *line_IDLOCATAIREboutique_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gboutique)
    {
        if (gboutique->objectName().isEmpty())
            gboutique->setObjectName("gboutique");
        gboutique->resize(1549, 881);
        gboutique->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background: #f0c1cd;  \n"
"}\n"
"\n"
"\n"
""));
        gboutique->setAnimated(true);
        centralwidget = new QWidget(gboutique);
        centralwidget->setObjectName("centralwidget");
        frame_10 = new QFrame(centralwidget);
        frame_10->setObjectName("frame_10");
        frame_10->setGeometry(QRect(-10, 0, 1571, 31));
        frame_10->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: rgb(0, 162, 198);\n"
"    border: 2px solid #00a2c6;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}\n"
""));
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame_10);
        label->setObjectName("label");
        label->setGeometry(QRect(1500, -10, 61, 51));
        label->setPixmap(QPixmap(QString::fromUtf8("build/Desktop_Qt_6_7_3_MinGW_64_bit-Debug/debug/notif.png")));
        label->setScaledContents(true);
        pushButton_Modifier = new QPushButton(centralwidget);
        pushButton_Modifier->setObjectName("pushButton_Modifier");
        pushButton_Modifier->setGeometry(QRect(530, 690, 121, 31));
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
        label_TITLE->setGeometry(QRect(200, 30, 581, 81));
        label_TITLE->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 36pt \"Imprint MT Shadow\";\n"
"    color: rgb(0, 162, 198);\n"
"    text-shadow: 2px 2px 4px rgba(0, 0, 0, 80); /* Ajout d'un effet d'ombre */\n"
"}\n"
""));
        lbl_Image_Display = new QLabel(centralwidget);
        lbl_Image_Display->setObjectName("lbl_Image_Display");
        lbl_Image_Display->setEnabled(true);
        lbl_Image_Display->setGeometry(QRect(670, 30, 151, 121));
        lbl_Image_Display->setPixmap(QPixmap(QString::fromUtf8("../../../photo.jpg")));
        lbl_Image_Display->setScaledContents(true);
        tableWidget_Boutique = new QTableWidget(centralwidget);
        if (tableWidget_Boutique->columnCount() < 10)
            tableWidget_Boutique->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Boutique->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget_Boutique->setObjectName("tableWidget_Boutique");
        tableWidget_Boutique->setGeometry(QRect(510, 260, 371, 271));
        tableWidget_Boutique->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    border: 1px solid #bfbfbf;\n"
"    gridline-color: #dcdcdc;\n"
"    background-color: white;\n"
"    alternate-background-color: #f9f9f9;\n"
"    selection-background-color: #0096D6;\n"
"    selection-color: white;\n"
"    color: black; /* texte noir */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #00ACC1; /* couleur de l'en-t\303\252te */\n"
"    color: black;              /* texte noir */\n"
"    padding: 5px;\n"
"    border: 1px solid #dddddd;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"    border: 1px solid #e0e0e0;\n"
"    color: black; /* texte noir */\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #0096D6;\n"
"    color: white; /* texte blanc quand s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f0f0f0;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #cccccc;\n"
" "
                        "   min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
""));
        tableWidget_Boutique->horizontalHeader()->setCascadingSectionResizes(false);
        frame_gestions = new QFrame(centralwidget);
        frame_gestions->setObjectName("frame_gestions");
        frame_gestions->setGeometry(QRect(0, 10, 191, 821));
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
        pushButton_deconnecter->setGeometry(QRect(0, 730, 181, 51));
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
        lbl_Logo_Display->setGeometry(QRect(0, -10, 181, 91));
        lbl_Logo_Display->setPixmap(QPixmap(QString::fromUtf8("build/Desktop_Qt_6_7_3_MinGW_64_bit-Debug/debug/logo.gif")));
        lbl_Logo_Display->setScaledContents(true);
        frame_9 = new QFrame(frame_gestions);
        frame_9->setObjectName("frame_9");
        frame_9->setGeometry(QRect(120, 540, 120, 80));
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_Ajouter = new QPushButton(centralwidget);
        pushButton_Ajouter->setObjectName("pushButton_Ajouter");
        pushButton_Ajouter->setGeometry(QRect(530, 570, 121, 31));
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
        pushButton_Supprimer->setGeometry(QRect(530, 630, 121, 31));
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
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(220, 120, 271, 571));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 3px solid grey;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"     border-radius: 10px;\n"
"    background-color:  rgb(0, 162, 198);\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        line_NOMboutique = new QLineEdit(frame);
        line_NOMboutique->setObjectName("line_NOMboutique");
        line_NOMboutique->setGeometry(QRect(40, 20, 191, 26));
        line_NOMboutique->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;               /* fond blanc */\n"
"    color: black;                    /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        line_TYPEboutique = new QLineEdit(frame);
        line_TYPEboutique->setObjectName("line_TYPEboutique");
        line_TYPEboutique->setGeometry(QRect(40, 70, 191, 26));
        line_TYPEboutique->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;               /* fond blanc */\n"
"    color: black;                    /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        line_SURFACEboutique = new QLineEdit(frame);
        line_SURFACEboutique->setObjectName("line_SURFACEboutique");
        line_SURFACEboutique->setGeometry(QRect(40, 170, 191, 26));
        line_SURFACEboutique->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;               /* fond blanc */\n"
"    color: black;                    /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        label_HORAIRE = new QLabel(frame);
        label_HORAIRE->setObjectName("label_HORAIRE");
        label_HORAIRE->setGeometry(QRect(40, 430, 141, 31));
        line_LOCALISATIONboutique = new QLineEdit(frame);
        line_LOCALISATIONboutique->setObjectName("line_LOCALISATIONboutique");
        line_LOCALISATIONboutique->setGeometry(QRect(40, 120, 191, 26));
        line_LOCALISATIONboutique->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;               /* fond blanc */\n"
"    color: black;                    /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        line_MONTANTboutique = new QLineEdit(frame);
        line_MONTANTboutique->setObjectName("line_MONTANTboutique");
        line_MONTANTboutique->setGeometry(QRect(40, 220, 191, 26));
        line_MONTANTboutique->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;               /* fond blanc */\n"
"    color: black;                    /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        timeEdit_HORAIRE = new QTimeEdit(frame);
        timeEdit_HORAIRE->setObjectName("timeEdit_HORAIRE");
        timeEdit_HORAIRE->setGeometry(QRect(40, 480, 118, 29));
        timeEdit_HORAIRE->setStyleSheet(QString::fromUtf8("QTimeEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;         /* fond blanc */\n"
"    color: black;              /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        comboBox_ETATboutique = new QComboBox(frame);
        comboBox_ETATboutique->addItem(QString());
        comboBox_ETATboutique->addItem(QString());
        comboBox_ETATboutique->setObjectName("comboBox_ETATboutique");
        comboBox_ETATboutique->setGeometry(QRect(40, 370, 191, 28));
        comboBox_ETATboutique->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;        /* fond blanc */\n"
"    color: black;             /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: white;        /* fond de la liste d\303\251roulante */\n"
"    color: black;             /* texte noir dans la liste */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        line_IDLOCATAIREboutique = new QLineEdit(frame);
        line_IDLOCATAIREboutique->setObjectName("line_IDLOCATAIREboutique");
        line_IDLOCATAIREboutique->setGeometry(QRect(40, 270, 191, 26));
        line_IDLOCATAIREboutique->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;               /* fond blanc */\n"
"    color: black;                    /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        line_IDEMPboutique = new QLineEdit(frame);
        line_IDEMPboutique->setObjectName("line_IDEMPboutique");
        line_IDEMPboutique->setGeometry(QRect(40, 320, 191, 26));
        line_IDEMPboutique->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;               /* fond blanc */\n"
"    color: black;                    /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        lineEdit_recherche_id = new QLineEdit(centralwidget);
        lineEdit_recherche_id->setObjectName("lineEdit_recherche_id");
        lineEdit_recherche_id->setGeometry(QRect(510, 130, 191, 26));
        lineEdit_recherche_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;               /* fond blanc */\n"
"    color: black;                    /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        pushButton_recherche_boutique = new QPushButton(centralwidget);
        pushButton_recherche_boutique->setObjectName("pushButton_recherche_boutique");
        pushButton_recherche_boutique->setGeometry(QRect(740, 130, 121, 29));
        pushButton_recherche_boutique->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_trier_boutiques = new QPushButton(centralwidget);
        pushButton_trier_boutiques->setObjectName("pushButton_trier_boutiques");
        pushButton_trier_boutiques->setGeometry(QRect(510, 190, 161, 29));
        pushButton_trier_boutiques->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_exporter_boutiques = new QPushButton(centralwidget);
        pushButton_exporter_boutiques->setObjectName("pushButton_exporter_boutiques");
        pushButton_exporter_boutiques->setGeometry(QRect(730, 630, 121, 29));
        pushButton_exporter_boutiques->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_vider_formulaire = new QPushButton(centralwidget);
        pushButton_vider_formulaire->setObjectName("pushButton_vider_formulaire");
        pushButton_vider_formulaire->setGeometry(QRect(410, 710, 84, 29));
        pushButton_vider_formulaire->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_Afficher = new QPushButton(centralwidget);
        pushButton_Afficher->setObjectName("pushButton_Afficher");
        pushButton_Afficher->setGeometry(QRect(730, 570, 121, 31));
        pushButton_Afficher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(910, 70, 601, 671));
        layoutPrincipal = new QVBoxLayout(verticalLayoutWidget);
        layoutPrincipal->setObjectName("layoutPrincipal");
        layoutPrincipal->setContentsMargins(0, 0, 0, 0);
        line_IDLOCATAIREboutique_2 = new QLineEdit(centralwidget);
        line_IDLOCATAIREboutique_2->setObjectName("line_IDLOCATAIREboutique_2");
        line_IDLOCATAIREboutique_2->setGeometry(QRect(570, 740, 281, 30));
        line_IDLOCATAIREboutique_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 11pt \"Segoe UI\";\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;               /* fond blanc */\n"
"    color: black;                    /* texte noir */\n"
"    selection-background-color: darkgray;\n"
"}\n"
""));
        gboutique->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gboutique);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1549, 25));
        gboutique->setMenuBar(menubar);
        statusbar = new QStatusBar(gboutique);
        statusbar->setObjectName("statusbar");
        gboutique->setStatusBar(statusbar);

        retranslateUi(gboutique);

        QMetaObject::connectSlotsByName(gboutique);
    } // setupUi

    void retranslateUi(QMainWindow *gboutique)
    {
        gboutique->setWindowTitle(QCoreApplication::translate("gboutique", "GEvennement", nullptr));
        label->setText(QString());
        pushButton_Modifier->setText(QCoreApplication::translate("gboutique", "Modifier", nullptr));
        label_TITLE->setText(QCoreApplication::translate("gboutique", "Gestion des boutiques", nullptr));
        lbl_Image_Display->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Boutique->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("gboutique", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Boutique->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("gboutique", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Boutique->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("gboutique", "type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Boutique->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("gboutique", "localisation", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Boutique->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("gboutique", "surface", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Boutique->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("gboutique", "montant", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Boutique->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("gboutique", "etat", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Boutique->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("gboutique", "horaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Boutique->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("gboutique", "ID_employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Boutique->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("gboutique", "ID_locataire", nullptr));
        pushButton_Dashboard->setText(QCoreApplication::translate("gboutique", "Dashboard", nullptr));
        pushButton_Employes->setText(QCoreApplication::translate("gboutique", "Employ\303\251s", nullptr));
        pushButton_Boutiques->setText(QCoreApplication::translate("gboutique", "Boutiques", nullptr));
        pushButton_Locataires->setText(QCoreApplication::translate("gboutique", "Locataires", nullptr));
        pushButton_Services->setText(QCoreApplication::translate("gboutique", "Services", nullptr));
        pushButton_Evennements->setText(QCoreApplication::translate("gboutique", "Evennements", nullptr));
        pushButton_deconnecter->setText(QCoreApplication::translate("gboutique", "se d\303\251connecter", nullptr));
        lbl_Logo_Display->setText(QString());
        pushButton_Ajouter->setText(QCoreApplication::translate("gboutique", "Ajouter", nullptr));
        pushButton_Supprimer->setText(QCoreApplication::translate("gboutique", "Supprimer", nullptr));
        line_NOMboutique->setPlaceholderText(QCoreApplication::translate("gboutique", "            NOM", nullptr));
        line_TYPEboutique->setPlaceholderText(QCoreApplication::translate("gboutique", "             TYPE", nullptr));
        line_SURFACEboutique->setPlaceholderText(QCoreApplication::translate("gboutique", "         SURFACE", nullptr));
        label_HORAIRE->setText(QCoreApplication::translate("gboutique", "Horaire ouverture", nullptr));
        line_LOCALISATIONboutique->setPlaceholderText(QCoreApplication::translate("gboutique", "      LOCALISATION", nullptr));
        line_MONTANTboutique->setPlaceholderText(QCoreApplication::translate("gboutique", "         MONTANT", nullptr));
        comboBox_ETATboutique->setItemText(0, QCoreApplication::translate("gboutique", "actif", nullptr));
        comboBox_ETATboutique->setItemText(1, QCoreApplication::translate("gboutique", "inactif", nullptr));

        comboBox_ETATboutique->setCurrentText(QCoreApplication::translate("gboutique", "actif", nullptr));
        line_IDLOCATAIREboutique->setPlaceholderText(QCoreApplication::translate("gboutique", "      ID LOCATAIRE", nullptr));
        line_IDEMPboutique->setPlaceholderText(QCoreApplication::translate("gboutique", "       ID EMPLOYE", nullptr));
        lineEdit_recherche_id->setPlaceholderText(QCoreApplication::translate("gboutique", "Rechercher par ID", nullptr));
        pushButton_recherche_boutique->setText(QCoreApplication::translate("gboutique", "rechercher", nullptr));
        pushButton_trier_boutiques->setText(QCoreApplication::translate("gboutique", "Trier par nom", nullptr));
        pushButton_exporter_boutiques->setText(QCoreApplication::translate("gboutique", "PDF", nullptr));
        pushButton_vider_formulaire->setText(QCoreApplication::translate("gboutique", "vider", nullptr));
        pushButton_Afficher->setText(QCoreApplication::translate("gboutique", "Afficher", nullptr));
        line_IDLOCATAIREboutique_2->setPlaceholderText(QCoreApplication::translate("gboutique", "        Entrez l'id locataire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gboutique: public Ui_gboutique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GBOUTIQUE_H
