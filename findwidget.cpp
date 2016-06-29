#include "findwidget.h"
#include "ui_findwidget.h"
#include "notepad.h"
#include <QString>

findWidget::findWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findWidget)
{
    ui->setupUi(this);
    setWindowTitle(tr("Find"));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(setSearchString()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(setSearchDirection()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SIGNAL(findSignal()));
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    setWindowModality(Qt::NonModal);

}

findWidget::~findWidget(){
    delete ui;
}

void findWidget::setSearchString(){
    SearchStr = ui->lineEdit->text();
}

QString findWidget::getSearchString(){
    return SearchStr;
}

void findWidget::setSearchDirection(){
    isdown=ui->radioButton_2->isChecked();
}

bool findWidget::getSearchDirection(){
    return isdown;
}
