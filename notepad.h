#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QString>
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
    void saveAs();
    void open();
    void about();
    void findWindow();
    void findInText();
    void setFont();

private:
    Ui::Notepad *ui;
    QString openedFile;
    findWidget fWind;
};

#endif // NOTEPAD_H
