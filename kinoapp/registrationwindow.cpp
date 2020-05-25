#include "registrationwindow.h"


RegistrationWindow::RegistrationWindow() : QDialog()
{
    lbl1 = new QLabel("Придумайте логин");
    login = new QLineEdit();
    login->setPlaceholderText("Логин");
    login->setMaxLength(20);

    box1 = new QGroupBox("Ваш возраст");
    age = new QSpinBox();
    slider_age = new QSlider(Qt::Horizontal);
    age->setRange(0, 100);
    slider_age->setRange(0,100);
    layout1 = new QHBoxLayout();
    layout1->addWidget(age);
    layout1->addWidget(slider_age);
    box1->setLayout(layout1);
    connect(age, SIGNAL(valueChanged(int)), slider_age, SLOT(setValue(int)));
    connect(slider_age, SIGNAL(valueChanged(int)), age, SLOT(setValue(int)));

    lblg = new QLabel("Любимый жанр");
    genre = new QComboBox();
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

    box2 = new QGroupBox("Пол");
    genM = new QRadioButton("муж");
    genF = new QRadioButton("жен");
    layout2 = new QHBoxLayout();
    layout2->addWidget(genM);
    layout2->addWidget(genF);
    box2->setLayout(layout2);

    box3 = new QGroupBox("Придумайте пароль");
    password1 = new QLineEdit();
    password1->setPlaceholderText("********");
    password2 = new QLineEdit();
    password2->setPlaceholderText("********");
    layout3 = new QVBoxLayout();
    layout3->addWidget(password1);
    layout3->addWidget(password2);
    box3->setLayout(layout3);


    registration = new QPushButton("Зарегистрироваться");
    back = new QPushButton("Назад");
    layout4 = new QHBoxLayout();
    layout4->addWidget(registration);
    layout4->addWidget(back);

    agree = new QCheckBox("Я принимаю условия пользования");

    mainlayout = new QVBoxLayout();
    mainlayout->addWidget(lbl1);
    mainlayout->addWidget(login);
    mainlayout->addWidget(box1);
    mainlayout->addWidget(lblg);
    mainlayout->addWidget(genre);
    mainlayout->addWidget(box2);
    mainlayout->addWidget(box3);
    mainlayout->addWidget(agree);
    mainlayout->addLayout(layout3);
    mainlayout->addWidget(registration);
    setWindowTitle("Регистрация");
    setLayout(mainlayout);

    connect(registration, SIGNAL(clicked()), this, SLOT(AddUser()));
}

void RegistrationWindow::AddUser()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../kinoapp.db");
    db.open();
    query = QSqlQuery(db);

    query.prepare("INSERT INTO users (login, age, gender, password, tags)"
                  "VALUES (:login, :age, :gender, :password, :tags);");
    query.bindValue(":login", login->text());
    query.bindValue(":age", age->value());
    if (genM->isChecked())
        query.bindValue(":gender", "муж");
    else if (genF->isChecked())
        query.bindValue(":gender", "жен");
    query.bindValue(":password", password1->text());
    query.bindValue(":tags", genre->currentText());
    query.exec();
    this->close();
}
