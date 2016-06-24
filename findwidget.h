#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QWidget>

namespace Ui {
class findWidget;
}

class findWidget : public QWidget
{
    Q_OBJECT

public:
    explicit findWidget(QWidget *parent = 0);
    ~findWidget();
    QString getSearchString();

signals:
    void findSignal();

private slots:
    void setSearchString();

private:
    Ui::findWidget *ui;
    QString SearchStr;
};

#endif // FINDWIDGET_H
