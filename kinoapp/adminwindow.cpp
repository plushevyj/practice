#include "adminwindow.h"

AdminWindow::AdminWindow(QString admin_id) : QMainWindow()
{
    area = new QWidget;
    setCentralWidget(area);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../kinoapp.db");
    db.open();
    query1 = QSqlQuery(db);
    query1.exec("SELECT * FROM admins WHERE id = '" + admin_id + "';");
    query1.first();

    login = new QLabel("Администратор: " + query1.value(1).toString());
    exit = new QPushButton("Выход");
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    layout1 = new QBoxLayout(QBoxLayout::RightToLeft);
    layout1->addWidget(exit);
    layout1->addWidget(login);
    layout1->addStretch(1);


    nametable = new QLabel("История операций пользователей");
    table = new QTableView(this);
    model = new QSqlRelationalTableModel(this);
    model->setTable("operations_history");
    model->select();
    table->setModel(model);
    table->horizontalHeader()->setStretchLastSection(true);
    scroll = new QScrollBar(Qt::Horizontal);

    otchet = new QPushButton("Перейти к отчету");
    history = new QVBoxLayout();
    history->addWidget(scroll);
    history->addWidget(nametable);
    history->addWidget(table);
    history->addWidget(otchet);

    filmsLayout = new QVBoxLayout();
    films = new QListWidget();
    films->addItems({"Титаник", "Мстители", "Аватар", "Крестный отец", "Дэдпул"});
    filmsLayout->addWidget(films);
    filmsLayout->addStretch(1);


    layout2 = new QHBoxLayout();
    layout2->addWidget(films);
    layout2->addLayout(history);

    menubar = new QMenuBar();
    CreateMenuBar();




    mainlayout = new QVBoxLayout();
    mainlayout->addLayout(layout1);
    mainlayout->addLayout(layout2);
    mainlayout->setMenuBar(menubar);


    setWindowTitle("KINOAPP");
    area->setLayout(mainlayout);
}

void AdminWindow::CreateMenuBar()
{
    QMenu *main = new QMenu("&Меню");
    main->addAction("&Профиль");
    main->addAction("&Новый прокат фильма");
    QMenu* subMenu = new QMenu("&Отчетность", main);
    main->addMenu(subMenu);
    subMenu->addAction("&Сборы фильмов");
    subMenu->addAction("&Отчет об истории операций пользователей");
    main->addAction("&Выход", this, SLOT(close()));

    menubar->addMenu(main);
    QMenu * help = new QMenu("&О программе");
    help->addAction("&О Qt");
    help->addAction("&Помощь");
    menubar->addMenu(help);

}
