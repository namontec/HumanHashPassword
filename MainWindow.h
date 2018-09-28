#ifndef WIDGET_H
#define WIDGET_H

//#include <QWidget>
#include <QtWidgets>
#include "PasswordWidget.h"
#include "PassGenerator.h"

class MainWindow : public QWidget
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void showWarning(QString warninMessage);


public slots:
  void slotGenerate();
  void slotGenerateCopy();

private:
  bool checkEqualPhrase();


private:
  PasswordWidget* passMaster_;
  PasswordWidget* passConfirm_;
  QLineEdit*      qledWebSite_;
  QLineEdit*      editResult_;
  PassGenerator*  passGenerator_;
};

#endif // WIDGET_H
