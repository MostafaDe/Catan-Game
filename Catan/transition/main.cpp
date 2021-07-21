#include "mainwindow.h"
#include"transition.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Transition w;
    w.show();
    return a.exec();
}
