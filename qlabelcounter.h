#ifndef QLABELCOUNTER_H
#define QLABELCOUNTER_H

#include <QtWidgets>

class QLabelCounter : public QLabel
{
Q_OBJECT
public:
  QLabelCounter();

public slots:
    void setCount(QString string);
};

#endif // QLABELCOUNTER_H
