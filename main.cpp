#include "notepad.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notepad note;
    note.show();

    note.resize(600, 500);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint cent = rect.center();
    cent.setX(cent.x()-note.width()/2);
    cent.setY(cent.y()-note.height()/2);
    note.move(cent);


    return a.exec();
}
