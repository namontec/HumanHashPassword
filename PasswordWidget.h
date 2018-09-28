#pragma once

#include <QtWidgets>

class PasswordWidget : public QWidget
{
  Q_OBJECT
public:
  explicit PasswordWidget(QString caption, QWidget *parent = nullptr);
  QString text();

signals:

public slots:
  void slotWriteLength();

private:
//  QProgressBar progressBar_;
  QLineEdit* lineEdit_;
  QLabel* labelCounter_;
};


