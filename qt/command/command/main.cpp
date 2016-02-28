#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //w.resize(QApplication::desktop()->availableGeometry().size());
    //w.resize(QApplication::desktop()->width(), QApplication::desktop()->height());
    //w.setWindowFlags(w.windowFlags());
    //w.setWindowState(Qt::WindowMaximized);
    //w.showMaximized();
    w.setGeometry(0, 5, QApplication::desktop()->width(), (QApplication::desktop()->height()-10));
    w.show();

    return a.exec();
}
