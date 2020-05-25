#include "loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QDialog(parent)
{
    lbl1 = new QLabel("Авторизация");

    login = new QLineEdit();
    login->setPlaceholderText("Логин");
    login->setMaxLength(20);

    password = new QLineEdit();
    password->setPlaceholderText("Пароль");
    password->setEchoMode(QLineEdit::Password);
    password->setMaxLength(20);

    enter = new QPushButton("Вход");
    regbutton = new QPushButton("Регистрация");

    layout1 = new QHBoxLayout();
    layout1->addWidget(enter);
    layout1->addWidget(regbutton);

    layout2 = new QVBoxLayout();
    layout2->addWidget(lbl1);
    layout2->addWidget(login);
    layout2->addWidget(password);
    layout2->addLayout(layout1);

    setWindowTitle("KINOAPP");
    setLayout(layout2);

    connect(regbutton, SIGNAL(clicked()), this, SLOT(OpenRegWindow()));
    connect(enter, SIGNAL(clicked()), this, SLOT(CheckUser()));
}

void LoginWindow::CheckUser()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../kinoapp.db");
    db.open();
    query = QSqlQuery(db);
    query.exec("SELECT * FROM users WHERE login = '" + login->text() + "';");
    if (query.next())
    {
        if (password->text() == query.value(4).toString())
//            qDebug() << login->text() << endl << password->text();
            emit OpenAppForUser(query.value(0).toString());
    }
    else
    {
        query.exec("SELECT * FROM admins WHERE login = '" + login->text() + "';");
        if (query.next())
            if (password->text() == query.value(2).toString())
                emit OpenAppForAdmin(query.value(0).toString());
    }
//    this->close();
}

void LoginWindow::OpenRegWindow()
{
    regwindow = new RegistrationWindow();
    regwindow->open();
}

void LoginWindow::OpenAppForUser(QString user_id)
{
    appwindow = new AppWindow(user_id);
    appwindow->open();
}

void LoginWindow::OpenAppForAdmin(QString user_id)
{
    adminwindow = new AdminWindow(user_id);
    adminwindow->show();
}
