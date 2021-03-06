#include "PasswordWidget.h"

PasswordWidget::PasswordWidget(const QString& caption, bool hideText, int timerInterval, QWidget *parent)
  : QWidget(parent), timerInterval_(timerInterval)
{
  QLabel* label  = new QLabel(caption);
  lineEdit_  = new QLineEdit;
  labelCounter_ = new QLabel("0");

  label->setBuddy(lineEdit_);
  if (hideText) {
      lineEdit_->setEchoMode(QLineEdit::Password);
  }

  connect(lineEdit_, SIGNAL(textChanged(QString)), SLOT(slotWriteLength()) );
  if (timerInterval != 0) {
  connect(lineEdit_, SIGNAL(textChanged(QString)), SLOT(slotStartClearTimer()) );
  }

  QHBoxLayout* lineEditLayout = new QHBoxLayout;
  lineEditLayout->addWidget(lineEdit_);
  lineEditLayout->addWidget(labelCounter_);

  QVBoxLayout* layout = new QVBoxLayout;
  layout->addWidget(label);
  layout->addLayout(lineEditLayout);
  layout->setMargin(0);
  this->setLayout(layout);
}



QString PasswordWidget::text()
{
  return lineEdit_->text();
}



void PasswordWidget::setText(const QString& text)
{
  lineEdit_->setText(text);
}



void PasswordWidget::setPlaceholderText(const QString& placeholder)
{
  lineEdit_->setPlaceholderText(placeholder);
}



void PasswordWidget::killClearTimer()
{
  if (timerId_ != 0) {
    killTimer(timerId_);
    timerId_ = 0;
  }
}



void PasswordWidget::slotWriteLength()
{
  int passLength = lineEdit_->text().length();
  labelCounter_->setText(QString::number(passLength));
}



void PasswordWidget::slotStartClearTimer()
{
  killClearTimer();

  if (timerInterval_ != 0) {
    timerId_ = startTimer(timerInterval_);
  }
}



void PasswordWidget::timerEvent(QTimerEvent *tEvent)
{
  lineEdit_->clear();
  killTimer(timerId_);
  timerId_ = 0;
}



void PasswordWidget::keyPressEvent(QKeyEvent *keyEvent)
{
  switch (keyEvent->key()) {
  case Qt::Key_Return:
    if (keyEvent->modifiers() & Qt::ControlModifier) {
      emit pressedCtrlEnter();
    }
    else {
      emit pressedEnter();
    }
    break;
  default:
    QWidget::keyPressEvent(keyEvent);
  }
}
