#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel* qlblMaster  = new QLabel("&Master phrase");
    QLineEdit* qledMaster  = new QLineEdit;
    QLabelCounter* qlblMasterCount = new QLabelCounter();
    qlblMaster->setBuddy(qledMaster);
    qledMaster->setEchoMode(QLineEdit::Password);
    connect(qledMaster, SIGNAL(textChanged(QString)), qlblMasterCount ,SLOT(setCount(QString)) );

    QHBoxLayout* hbMasterLayout = new QHBoxLayout;
    hbMasterLayout->addWidget(qledMaster);
    hbMasterLayout->addWidget(qlblMasterCount);


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

    QPushButton* qbtnGenerate = new QPushButton("Generate\n[Enter]");
    QPushButton* qbtnGenCopy = new QPushButton("Generate and copy\n[Ctrl+Enter]");

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(qbtnGenerate);
    buttonLayout->addWidget(qbtnGenCopy);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(qlblMaster);
    layout->addLayout(hbMasterLayout);
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


