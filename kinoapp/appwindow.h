#ifndef APPWINDOW_H
#define APPWINDOW_H
#include <QtWidgets>
#include <QDialog>
#include <QBoxLayout>
#include <QGroupBox>
#include <QtSql>

class AppWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AppWindow(QString user_id);

private:

    QHBoxLayout *userInfoLayout;
    QLabel *login;
    QPushButton *exit;


    QHBoxLayout *filterLayout;
    QComboBox *genre;
    QLineEdit *search;
    QGroupBox *box1;

    QVBoxLayout *layoutForRecommendation;
    QGroupBox *box2;


    QHBoxLayout *contentLayout;








    QVBoxLayout *mainlayout;

    QSqlDatabase db;
    QSqlQuery query1;

};

#endif // APPWINDOW_H
