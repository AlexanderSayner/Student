#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

#include <iostream>
#include <view.h>
#include <dial.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGridLayout *gridLayout;
    QLineEdit *lineEditGroup;

public slots:
    void printOnAPrinter();

public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
