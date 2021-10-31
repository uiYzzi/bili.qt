#include "mainwindow-dtk.h"
#include <QApplication>
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(nullptr);
    w.setWindowTitle(QObject::tr("哔哩"));
    QApplication::setWindowIcon(QIcon::fromTheme(":/icon/logo.png"));
    w.show();
    return a.exec();
}
