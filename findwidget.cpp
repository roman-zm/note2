#include "findwidget.h"
#include "ui_findwidget.h"
#include "notepad.h"
#include <QString>

findWidget::findWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findWidget)
{
    ui->setupUi(this);
    setWindowTitle(tr("Find"));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(setSearchString()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SIGNAL(findSignal()));

}

findWidget::~findWidget()
{
    delete ui;
}

void findWidget::setSearchString()
{
    SearchStr = ui->lineEdit->text();
}

QString findWidget::getSearchString(){
    return SearchStr;
}
