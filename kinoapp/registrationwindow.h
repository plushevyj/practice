#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H
#include <QDialog>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QString>
#include <QtSql>

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    RegistrationWindow();

private:
    QLabel *lbl1;
    QLineEdit *login;
    QGroupBox *box1;
    QHBoxLayout *layout1;
    QSpinBox *age;
    QSlider *slider_age;
    QPushButton *registration;
    QPushButton *back;
    QLabel *lblg;
    QComboBox *genre;

    QHBoxLayout *layout2;
    QGroupBox *box2;
    QRadioButton *genM;
    QRadioButton *genF;

    QVBoxLayout *layout3;
    QGroupBox *box3;
    QLineEdit *password1;
    QLineEdit *password2;


    QCheckBox *agree;

    QHBoxLayout *layout4;
    QVBoxLayout *mainlayout;

    QSqlDatabase db;
    QSqlQuery query;

private slots:
    void AddUser();
};

#endif // REGISTRATIONWINDOW_H
