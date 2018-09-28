#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
  passMaster_ = new PasswordWidget("&Master phrase");
  PasswordWidget* passConfirm = new PasswordWidget("Co&nfirm");

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

MainWindow::~MainWindow()
{
  delete passGenerator_;
}

void MainWindow::slotGenerate()
{
  QString password = passGenerator_->GeneratePass(passMaster_->text(), qledWebSite_->text());
  editResult_->setText(password);
}

void MainWindow::slotGenerateCopy()
{

}


