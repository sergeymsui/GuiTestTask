
#include "mainwindow.h"

#include <QFile>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QApplication::setApplicationDisplayName("Gui Test Task");
    QApplication::setApplicationName("Gui Test Task");
    QApplication::setApplicationVersion("0.0.1");
    QApplication::setOrganizationName("Gui Org.");

    MainWindow w;
    w.show();

    return a.exec();
}
