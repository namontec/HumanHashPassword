#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
  Password* passMaster = new Password("&Master phrase");
  Password* passConfirm = new Password("&Confirm");

  QLabel* qlblWebSite  = new QLabel("&Web Site");
  QLineEdit* qledWebSite  = new QLineEdit;
  qlblWebSite->setBuddy(qledWebSite);

  QLabel* qlblResult = new QLabel("&Result");
  QLineEdit* qledResult  = new QLineEdit;
  qlblResult->setBuddy(qledResult);

  QPushButton* qbtnGenerate = new QPushButton("Generate\n[Enter]");
  QPushButton* qbtnGenCopy = new QPushButton("Generate and copy\n[Ctrl+Enter]");

  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->addWidget(qbtnGenerate);
  buttonLayout->addWidget(qbtnGenCopy);


  QVBoxLayout* layout = new QVBoxLayout;
  layout->addWidget(passMaster);
  layout->addWidget(passConfirm);

  layout->addWidget(qlblWebSite);
  layout->addWidget(qledWebSite);

  layout->addWidget(qlblResult);
  layout->addWidget(qledResult);
  layout->addLayout(buttonLayout);
  layout->addStretch();

  this->setLayout(layout);
}

Widget::~Widget()
{

}


