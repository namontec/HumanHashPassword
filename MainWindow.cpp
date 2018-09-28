#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
  passMaster_  = new PasswordWidget("&Master phrase");
  passConfirm_ = new PasswordWidget("Co&nfirm");

  QLabel* qlblWebSite  = new QLabel("&Web Site");
  qledWebSite_  = new QLineEdit;
  qlblWebSite->setBuddy(qledWebSite_);

  QLabel* qlblResult = new QLabel("&Result");
  editResult_  = new QLineEdit;
  qlblResult->setBuddy(editResult_);

  QPushButton* qbtnGenerate = new QPushButton("&Generate");
  QPushButton* qbtnGenCopy = new QPushButton("Generate and &copy");
  connect( qbtnGenerate, SIGNAL(clicked()), SLOT(slotGenerate()) );
  connect( qbtnGenCopy,  SIGNAL(clicked()), SLOT(slotGenerateCopy()) );

  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->addWidget(qbtnGenerate);
  buttonLayout->addWidget(qbtnGenCopy);


  QVBoxLayout* layout = new QVBoxLayout;
  layout->addWidget(passMaster_);
  layout->addWidget(passConfirm_);

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



void MainWindow::showWarning(QString warningMessage)
{
  QWidget *sender = qobject_cast<QWidget*>( QObject::sender() );
  QToolTip::showText( sender->mapToGlobal( QPoint( 0, 0 ) ), warningMessage );
}



void MainWindow::slotGenerate()
{
  if (checkPhrase()){
    QString password = passGenerator_->GeneratePass(passMaster_->text(), qledWebSite_->text());
    editResult_->setText(password);
  }
}



void MainWindow::slotGenerateCopy()
{
  if (checkPhrase()){
    QString password = passGenerator_->GeneratePass(passMaster_->text(), qledWebSite_->text());
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(password);
    editResult_->setText("<Copied to clipboard>");
  }
}



bool MainWindow::checkPhrase()
{
  bool phrasesEqual = ( passMaster_->text() == passConfirm_->text() );
  bool phraseZero   = ( passMaster_->text().length() == 0 );
  if (!phrasesEqual) {
    showWarning("Phrases are not equal");
    return false;
  }
  else if (phraseZero){
    showWarning("Empty phrase is not secure");
    return false;
  }
  else return true;
}





