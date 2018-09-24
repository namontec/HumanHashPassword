#pragma once

#include <QtWidgets>

class Password : public QWidget
{
  Q_OBJECT
public:
  explicit Password(QString caption, QWidget *parent = nullptr);
  QString text();

signals:

public slots:
  void slotWriteLength();

private:
//  QProgressBar progressBar_;
  QLineEdit* lineEdit_;
  QLabel* labelCounter_;
};


