#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QObject>
#include <QTextCodec>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFile>
#include <QtWebKit>
#include <QWebView>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>

class View : public QMainWindow
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0, const QString html = QString());
    QString hmtlCopy;
    QGridLayout *gridLayout;
    QWebView *webViewPRS;

signals:

public slots:
    void print();
};

#endif // VIEW_H
