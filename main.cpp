#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QApplication::setStyle( QStyleFactory::create("Windows") );
    MainWindow w;
    w.show();
    //qDebug() << QStyleFactory::keys().join(" ");
    return a.exec();
}
