#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QString>
#include <QPalette>
#include <QTextCursor>
#include "findwidget.h"

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();

private slots:
    void save();
    void saveAs(bool);
    void open();
    void about();
    void findWindow();
    void replaceWindow();
    bool findInText();
    void replaceInText();
    void setFont();
    void createFile();
    void setLineWarp(bool);
    void replaceAll();

private:
    Ui::Notepad *ui;
    QString openedFile;
    findWidget fWind;
    QPalette pal;
    QTextCursor *cursor;
    bool replaceAllFlag = false;
};

#endif // NOTEPAD_H
