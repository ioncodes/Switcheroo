#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    qRegisterMetaType<QList<Account>>("QList<Account>");
    qRegisterMetaTypeStreamOperators<QList<Account>>("QList<Account>");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
