#include "aboutwidget.h"
#include "ui_aboutwidget.h"
#include <QDesktopWidget>
#include <QRect>
#include <QPoint>


aboutWidget::aboutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutWidget)
{
    ui->setupUi(this);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint cent = rect.center();
    cent.setX(cent.x()-this->width()/2);
    cent.setY(cent.y()-this->height()/2);
    move(cent);
}

aboutWidget::~aboutWidget()
{
    delete ui;
}

void aboutWidget::on_pushButton_clicked()
{
    this->close();
}
