#include "PasswordWidget.h"

PasswordWidget::PasswordWidget(QString caption, QWidget *parent) : QWidget(parent)
{
  QLabel* label  = new QLabel(caption);
  lineEdit_  = new QLineEdit;
  labelCounter_ = new QLabel("0");
//  QProgressBar* progressBar = new QProgressBar;

//  qprbMaster->setRange(0, 11);
//  qprbMaster->resize(0,2);

  label->setBuddy(lineEdit_);
  lineEdit_->setEchoMode(QLineEdit::Password);
  connect(lineEdit_, SIGNAL(textChanged(QString)), SLOT(slotWriteLength()) );

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

void PasswordWidget::slotWriteLength()
{
  int passLength = lineEdit_->text().length();
  labelCounter_->setText(QString::number(passLength));
}
