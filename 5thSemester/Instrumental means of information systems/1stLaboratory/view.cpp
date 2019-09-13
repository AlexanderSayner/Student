#include "view.h"

View::View(QWidget *parent, QString html) : QMainWindow(parent)
{
    // Устанавниваем размер окна
    setMinimumSize(800, 600);

    // Копируется на всякий случай
    this->hmtlCopy = html;

    // Разметка окна
    QGridLayout *gridLayout = new QGridLayout();

    this->webViewPRS = new QWebView(this);

    this->webViewPRS->setHtml(html);

    gridLayout->addWidget(this->webViewPRS,0,0,5,5);

    // Конопка
    QPushButton *pushButton = new QPushButton("Печать");

    gridLayout->addWidget(pushButton,6,5,1,1);

    // Подключить кнопку
    connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(print()));

    // На отрисовку
    QWidget *widget = new QWidget(this);
    widget->setLayout(gridLayout);
    this->setCentralWidget(widget);

}

void View::print()
{
    qDebug() << "Debug: " << "оно должно печатать";

    // Создаем принтер
    QPrinter printer;
    QPrintDialog dialog(&printer, this);

    if(dialog.exec()){
        QTextDocument textDocument;
        textDocument.setHtml(this->hmtlCopy);
        textDocument.print(&printer);
    }

}
