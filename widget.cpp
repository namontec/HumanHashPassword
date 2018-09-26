#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
  passMaster_ = new Password("&Master phrase");
  Password* passConfirm = new Password("Co&nfirm");

  QLabel* qlblWebSite  = new QLabel("&Web Site");
  qledWebSite_  = new QLineEdit;
  qlblWebSite->setBuddy(qledWebSite_);

  QLabel* qlblResult = new QLabel("&Result");
  editResult_  = new QLineEdit;
  qlblResult->setBuddy(editResult_);

  QPushButton* qbtnGenerate = new QPushButton("&Generate");
  QPushButton* qbtnGenCopy = new QPushButton("Generate and &copy");
  connect( qbtnGenerate, SIGNAL(clicked()), SLOT(slotGenerate()) );

  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->addWidget(qbtnGenerate);
  buttonLayout->addWidget(qbtnGenCopy);


  QVBoxLayout* layout = new QVBoxLayout;
  layout->addWidget(passMaster_);
  layout->addWidget(passConfirm);

  layout->addWidget(qlblWebSite);
  layout->addWidget(qledWebSite_);

  layout->addWidget(qlblResult);
  layout->addWidget(editResult_);
  layout->addLayout(buttonLayout);
  layout->addStretch();

  this->setLayout(layout);

  passGenerator_ = new PassGenerator;

}

Widget::~Widget()
{
  delete passGenerator_;
}

void Widget::slotGenerate()
{
  QString password = passGenerator_->GeneratePass(passMaster_->text(), qledWebSite_->text());
  editResult_->setText(password);
}

void Widget::slotGenerateCopy()
{

}


