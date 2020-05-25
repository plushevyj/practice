#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtSql>
#include <QBoxLayout>
#include <QGroupBox>

class AdminWindow : public QMainWindow
{
    Q_OBJECT
public:
    AdminWindow(QString admin_id);

private:
    QWidget *area;

    QLabel *login;
    QPushButton *exit;
    QBoxLayout *layout1;

    QScrollBar *scroll;

    QLabel *nametable;
    QTableView *table;
    QSqlRelationalTableModel *model;
    QPushButton *otchet;
    QListWidget *films;
    QVBoxLayout *filmsLayout;
    QVBoxLayout *history;
    QHBoxLayout *layout2;


    QMenuBar *menubar;
    void CreateMenuBar();





    QVBoxLayout *mainlayout;

    QSqlDatabase db;
    QSqlQuery query1;

};

#endif // ADMINWINDOW_H
