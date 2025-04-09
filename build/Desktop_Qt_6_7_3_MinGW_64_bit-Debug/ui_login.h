/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QFrame *frame;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(391, 292);
        frame = new QFrame(Dialog);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 20, 301, 201));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_email = new QLineEdit(frame);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(30, 30, 151, 28));
        lineEdit_password = new QLineEdit(frame);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(30, 60, 181, 28));
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton_login = new QPushButton(frame);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(120, 110, 121, 29));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        lineEdit_email->setText(QString());
        lineEdit_password->setText(QString());
        pushButton_login->setText(QCoreApplication::translate("Dialog", "se connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
