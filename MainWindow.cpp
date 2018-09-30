#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
  passMaster_  = new PasswordWidget("Master phrase", true, 5 * 60 * 1000);
  passMaster_->setPlaceholderText("11 symbols or more");
  passConfirm_ = new PasswordWidget("Confirm phrase", true, 5 * 60 * 1000);
  qledWebSite_ = new PasswordWidget("Web Site", false);
  editResult_  = new PasswordWidget("Password", false, 10 * 1000);
  connect( passMaster_,  SIGNAL(pressedEnter()),     SLOT(slotGenerate()) );
  connect( passMaster_,  SIGNAL(pressedCtrlEnter()), SLOT(slotGenerateCopy()) );
  connect( passConfirm_, SIGNAL(pressedEnter()),     SLOT(slotGenerate()) );
  connect( passConfirm_, SIGNAL(pressedCtrlEnter()), SLOT(slotGenerateCopy()) );
  connect( qledWebSite_, SIGNAL(pressedEnter()),     SLOT(slotGenerate()) );
  connect( qledWebSite_, SIGNAL(pressedCtrlEnter()), SLOT(slotGenerateCopy()) );
  connect( editResult_,  SIGNAL(pressedEnter()),     SLOT(slotGenerate()) );
  connect( editResult_,  SIGNAL(pressedCtrlEnter()), SLOT(slotGenerateCopy()) );

  QPushButton* qbtnGenerate = new QPushButton("Generate");
  qbtnGenerate->setToolTip("Enter");
  QPushButton* qbtnGenCopy = new QPushButton("Generate and copy");
  qbtnGenCopy->setToolTip(("Ctrl + Enter"));
  connect( qbtnGenerate, SIGNAL(clicked()), SLOT(slotGenerate()) );
  connect( qbtnGenCopy,  SIGNAL(clicked()), SLOT(slotGenerateCopy()) );


  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->addWidget(qbtnGenerate);
  buttonLayout->addWidget(qbtnGenCopy);

  QVBoxLayout* layout = new QVBoxLayout;
  layout->addWidget(passMaster_);
  layout->addWidget(passConfirm_);
  layout->addWidget(qledWebSite_);
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
  QToolTip::showText( sender->mapToGlobal( QPoint( 0, sender->height() / 2) ), warningMessage );
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
    editResult_->killClearTimer();
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





