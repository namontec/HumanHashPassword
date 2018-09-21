#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel* qlblMaster  = new QLabel("&Master phrase");
    QLineEdit* qledMaster  = new QLineEdit;
    qlblMaster->setBuddy(qledMaster);
    qledMaster->setEchoMode(QLineEdit::Password);

    QLabel* qlblConfirm = new QLabel("&Confirm");
    QLineEdit* qledConfirm = new QLineEdit;
    qlblConfirm->setBuddy(qledConfirm);
    qledConfirm->setEchoMode(QLineEdit::Password);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(qlblMaster);
    layout->addWidget(qledMaster);
    layout->addWidget(qlblConfirm);
    layout->addWidget(qledConfirm);
    this->setLayout(layout);
}

Widget::~Widget()
{

}
