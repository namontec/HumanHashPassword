#pragma once

#include <QtWidgets>
#include <iostream>

class PasswordWidget : public QWidget
{
  Q_OBJECT
public:
  explicit  PasswordWidget(QString caption, bool hideText = false, int timerInterval = 0, QWidget *parent = nullptr);
  QString   text();
  void      setText(QString text);
  void      setPlaceholderText(QString placeholder);
  void      killClearTimer();

signals:
  void      pressedEnter();
  void      pressedCtrlEnter();

public slots:
  void      slotWriteLength();
  void      slotStartClearTimer();

protected:
  virtual void timerEvent(QTimerEvent* tEvent);
  virtual void keyPressEvent(QKeyEvent *keyEvent);

private:
//  QProgressBar progressBar_;
  QLineEdit*  lineEdit_;
  QLabel*     labelCounter_;
  int         timerInterval_;
  int         timerId_ = 0;
};


