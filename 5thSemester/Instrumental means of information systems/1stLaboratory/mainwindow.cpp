#include "mainwindow.h"

#include <QMainWindow>

#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>

#include <QLabel>

#include <QDebug>

#include <QPainter>

#include <QGraphicsItem>

#include <QtDebug>
#include <QMouseEvent>

#include <QLabel>

#include <QDebug>

#include <QGridLayout>
#include <QLineEdit>

#include <QPushButton>

#include <iostream>

#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrinterInfo>

/**
  Конструктор отрисоввает окно при его запустке
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Устанавниваем размер окна
    setMinimumSize(800, 600);

    // Сеточка для окошка
    this->gridLayout = new QGridLayout();

    QLabel *labelTitle = new QLabel("Title");
    this->gridLayout->addWidget(labelTitle,0,0,1,2);

    QLineEdit *lineEditGroup = new QLineEdit;
    this->gridLayout->addWidget(lineEditGroup,1,0,1,1);

    // Кнопка
    QPushButton *pushButtonPrint = new QPushButton("Печать");
    this->gridLayout->addWidget(pushButtonPrint,0,4,1,1);

    // Подключение кнопки
    connect(pushButtonPrint, SIGNAL(clicked(bool)), this, SLOT(printOnAPrinter()));

    // Отдать на отрисовку элемент
    QWidget *widget = new QWidget(this);
    widget->setLayout(this->gridLayout);
    this->setCentralWidget(widget);
}

/**
  печатает что-то
 * @brief MainWindow::printOnAPrinter
 * @return
 */
void MainWindow::printOnAPrinter()
{
    qDebug() << "Debug: " << "мессадж";

    // Фторая формочка
    Dial *w = new Dial();
    w->show();
}

/**
  Кувадла для объекта
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{

}
