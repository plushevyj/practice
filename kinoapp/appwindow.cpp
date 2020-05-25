#include "appwindow.h"


AppWindow::AppWindow(QString user_id) : QDialog()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../kinoapp.db");
    db.open();
    query1 = QSqlQuery(db);
    query1.exec("SELECT * FROM users WHERE id = '" + user_id + "';");
    query1.first();

    userInfoLayout = new QHBoxLayout();
    login = new QLabel(query1.value(1).toString());
    exit = new QPushButton("Выход");
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    userInfoLayout->addWidget(login);
    userInfoLayout->addWidget(exit);


    genre = new QComboBox();
    genre->addItem("-ЖАНР ФИЛЬМА-");
    genre->addItem("аниме");
    genre->addItem("боевик");
    genre->addItem("военный");
    genre->addItem("детектив");
    genre->addItem("драма");
    genre->addItem("комедия");
    genre->addItem("мультфильм");
    genre->addItem("приключения");
    genre->addItem("триллер");
    genre->addItem("ужасы");
    genre->addItem("фантиастика");
    search = new QLineEdit();
    search->setPlaceholderText("Поиск фильма");
    search->setMaxLength(20);
    filterLayout = new QHBoxLayout();
    filterLayout->addWidget(genre);
    filterLayout->addWidget(search);
    box1 = new QGroupBox("Фильтр");
    box1->setLayout(filterLayout);


    contentLayout = new QHBoxLayout();





    layoutForRecommendation = new QVBoxLayout();
    box2 = new QGroupBox("Рекомендации");
    box2->setLayout(layoutForRecommendation);




    mainlayout = new QVBoxLayout();
    mainlayout->addLayout(userInfoLayout);
    mainlayout->addWidget(box2);
    mainlayout->addWidget(box1);
    mainlayout->addLayout(contentLayout);

    setWindowTitle("KINOAPP");
    setLayout(mainlayout);


}
