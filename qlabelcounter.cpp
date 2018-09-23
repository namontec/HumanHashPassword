#include "qlabelcounter.h"

QLabelCounter::QLabelCounter()
{
  this->setText("0");
}

void QLabelCounter::setCount(QString string)
{
  this->setText( QString::number( (string.length() )) );
}

