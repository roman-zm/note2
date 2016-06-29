#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QString>
#include <QPalette>
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
    void findInText();
    void setFont();
    void createFile();
    void setLineWarp(bool);

private:
    Ui::Notepad *ui;
    QString openedFile;
    findWidget fWind;
    QPalette pal;
};

#endif // NOTEPAD_H
