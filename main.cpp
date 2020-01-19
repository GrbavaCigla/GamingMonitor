#include "login.h"
#include "dashboard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dashboard w(NULL);
    Login w;
    w.showFullScreen();
    return a.exec();
}
