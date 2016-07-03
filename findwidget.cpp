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
    setSearchDirection(1);
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(setSearchString(QString)));
    connect(ui->replaceLine, SIGNAL(textChanged(QString)), this, SLOT(setReplaceString(QString)));
    connect(ui->radioButton_2, SIGNAL(toggled(bool)), this, SLOT(setSearchDirection(bool)));

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SIGNAL(findSignal()));
    connect(ui->replaceButton, SIGNAL(clicked(bool)), this, SIGNAL(replaceSignal()));
    connect(ui->replaceAllButton, SIGNAL(clicked(bool)), this, SIGNAL(replaceAllSignal()));
    setWindowFlags(Qt::CustomizeWindowHint |Qt::WindowCloseButtonHint| Qt::WindowStaysOnTopHint);
    setModal(false);
    ui->pushButton->setFocus();
}

findWidget::~findWidget(){
    delete ui;
}

void findWidget::setSearchString(QString srch){
    SearchStr = srch;
}

QString findWidget::getSearchString(){
    return SearchStr;
}

void findWidget::setReplaceString(QString rplc){
    replaceStr = rplc;
}

QString findWidget::getReplaceString(){
    return replaceStr;
}

void findWidget::setSearchDirection(bool down){
    isdown=down;
}

bool findWidget::getSearchDirection(){
    return isdown;
}

void findWidget::setReplace(bool replace){
    if(replace)
        this->setFixedSize(340,194);
    else
        this->setFixedSize(340, 115);
    ui->replaceAllButton->setEnabled(replace);
    ui->replaceAllButton->setVisible(replace);
    ui->replaceButton->setEnabled(replace);
    ui->replaceButton->setVisible(replace);
    ui->replaceLine->setEnabled(replace);
    ui->replaceLine->setVisible(replace);

}
