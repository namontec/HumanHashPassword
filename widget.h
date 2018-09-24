#ifndef WIDGET_H
#define WIDGET_H

//#include <QWidget>
#include <QtWidgets>
#include "password.h"
#include "passgenerator.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void slotGenerate();
    void slotGenerateCopy();

private:
    Password*       passMaster_;
    QLineEdit*      qledWebSite_;
    QLineEdit*      editResult_;
    PassGenerator*  passGenerator_;
};

#endif // WIDGET_H
