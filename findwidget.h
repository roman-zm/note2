#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QDialog>

namespace Ui {
class findWidget;
}

class findWidget : public QDialog
{
    Q_OBJECT

public:
    explicit findWidget(QWidget *parent = 0 );
    ~findWidget();
    QString getSearchString();
    bool getSearchDirection();

signals:
    void findSignal();

private slots:
    void setSearchString();
    void setSearchDirection();

private:
    Ui::findWidget *ui;
    QString SearchStr;
    bool isdown;
};

#endif // FINDWIDGET_H
