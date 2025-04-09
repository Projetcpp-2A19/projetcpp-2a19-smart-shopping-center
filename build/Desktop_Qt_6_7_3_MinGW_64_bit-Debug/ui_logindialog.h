/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton_Login;
    QLineEdit *lineEdit_Password;
    QLineEdit *lineEdit_Email;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(735, 492);
        pushButton_Login = new QPushButton(Dialog);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setGeometry(QRect(322, 320, 161, 29));
        lineEdit_Password = new QLineEdit(Dialog);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setGeometry(QRect(80, 220, 113, 28));
        lineEdit_Email = new QLineEdit(Dialog);
        lineEdit_Email->setObjectName("lineEdit_Email");
        lineEdit_Email->setGeometry(QRect(80, 180, 113, 28));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("Dialog", "Se connecter", nullptr));
        lineEdit_Password->setText(QCoreApplication::translate("Dialog", "password", nullptr));
        lineEdit_Email->setText(QCoreApplication::translate("Dialog", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
