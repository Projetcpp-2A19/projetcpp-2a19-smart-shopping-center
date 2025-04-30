#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    bool isAuthenticated() const { return authenticated; }

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::LoginDialog *ui;
    bool authenticated;
};

#endif // LOGINDIALOG_H
