#include "dial.h"

Dial::Dial(QWidget *parent) : QMainWindow(parent)
{
    // Устанавниваем размер окна
    setMinimumSize(800, 600);

    QGridLayout *gridLayout = new QGridLayout();

    // Кнопка
    QPushButton *pushButton = new QPushButton("Печать");
    gridLayout->addWidget(pushButton,0,0,1,1);

    connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(preview()));

    // На отрисовку
    QWidget *widget = new QWidget(this);
    widget->setLayout(gridLayout);
    this->setCentralWidget(widget);
}

void Dial::preview()
{
    QFile f("page.html");

    if(!f.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Debug: " << "ФАЙЛ НЕ ОТКРЬ|ЛСЯ!!!!";
        return;
    }

    QString html = f.readAll();
    html.replace(QString("%group%"), QString("Группа"));
    html.replace(QString("%facult%"), QString("Факультет"));

    View *w = new View(this, html);
    w->show();
}
