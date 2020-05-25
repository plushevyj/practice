#ifndef ENTERWINDOW_H
#define ENTERWINDOW_H
#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QtWidgets>
#include <QBoxLayout>
#include <QtSql>
#include "registrationwindow.h"
#include "appwindow.h"
#include "adminwindow.h"

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);

private:
    QLabel *lbl1;
    QLineEdit *login;
    QLineEdit *password;
    QPushButton *enter;
    QPushButton *regbutton;

    QHBoxLayout *layout1;
    QVBoxLayout *layout2;

    QSqlDatabase db;
    QSqlQuery query;

    RegistrationWindow *regwindow;
    AppWindow *appwindow;
    AdminWindow *adminwindow;

private slots:
    void OpenRegWindow();
    void CheckUser();
    void OpenAppForUser(QString user_id);
    void OpenAppForAdmin(QString user_id);


};
#endif // ENTERWINDOW_H
