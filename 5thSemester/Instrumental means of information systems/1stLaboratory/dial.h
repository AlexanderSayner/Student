#ifndef DIAL_H
#define DIAL_H

#include <QMainWindow>
#include <QObject>
#include <QMainWindow>
#include <QObject>
#include <QFile>
#include "view.h"

class Dial : public QMainWindow
{
    Q_OBJECT
public:
    explicit Dial(QWidget *parent = nullptr);

signals:

public slots:
    void preview();
};

#endif // DIAL_H
