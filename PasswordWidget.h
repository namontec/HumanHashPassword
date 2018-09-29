#pragma once

#include <QtWidgets>

class PasswordWidget : public QWidget
{
  Q_OBJECT
public:
  explicit  PasswordWidget(QString caption, bool hideText = false, int timerInterval = 0, QWidget *parent = nullptr);
  QString   text();
  void      setText(QString text);

signals:

public slots:
  void      slotWriteLength();
  void      slotStartClearTimer();

protected:
  virtual void timerEvent(QTimerEvent* tEvent);

private:
//  QProgressBar progressBar_;
  QLineEdit*  lineEdit_;
  QLabel*     labelCounter_;
  int         timerInterval_;
  int         timerId_;
};


