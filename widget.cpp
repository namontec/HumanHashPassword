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

    QLabel* qlblWebSite  = new QLabel("&Web Site");
    QLineEdit* qledWebSite  = new QLineEdit;
    qlblWebSite->setBuddy(qledWebSite);

    QLabel* qlblResult = new QLabel("&Result");
    QLineEdit* qledResult  = new QLineEdit;
    qlblResult->setBuddy(qledResult);

    QPushButton* qbtnGenerate = new QPushButton("Generate");
    QPushButton* qbtnGenCopy = new QPushButton("Generate and copy");

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(qbtnGenerate);
    buttonLayout->addWidget(qbtnGenCopy);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(qlblMaster);
    layout->addWidget(qledMaster);
    layout->addWidget(qlblConfirm);
    layout->addWidget(qledConfirm);
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
