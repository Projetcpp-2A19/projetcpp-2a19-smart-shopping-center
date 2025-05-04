#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QImage>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include"arduino.h"
bool authentifierUtilisateur(const QString& posteAutorise);
void envoyerSMSCode(const QString &phoneNumber, const QString &resetCode);
void motDePasseOublie();

extern Arduino arduino;



#endif // AUTHENTIFICATION_H
