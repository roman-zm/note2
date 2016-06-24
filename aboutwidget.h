#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>

namespace Ui {
class aboutWidget;
}

class aboutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit aboutWidget(QWidget *parent = 0);
    ~aboutWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::aboutWidget *ui;
};

#endif // ABOUTWIDGET_H
