#include "notepad.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QTranslator>
#include <QFile>
#include <QDir>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator *qtTrans = new QTranslator;
    qtTrans->load("qt_"+QLocale::system().name(),
                QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    qApp->installTranslator(qtTrans);


    QTranslator *translator = new QTranslator;
    QString fileTr = QApplication::applicationDirPath()+QDir::separator()+QLocale::system().name();
    if(!translator->load(fileTr))
        qApp->exit();
    else
        qApp->installTranslator(translator);

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
