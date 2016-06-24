#include "notepad.h"
#include "ui_notepad.h"
#include "aboutwidget.h"
#include "findwidget.h"
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    connect(ui->actionExit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(open()));
    connect(ui->actionSave_as, SIGNAL(triggered(bool)), this, SLOT(saveAs()));
    connect(ui->actionUndo, SIGNAL(triggered(bool)), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered(bool)), ui->textEdit, SLOT(redo()));
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(about()));
    connect(ui->actionFind, SIGNAL(triggered(bool)), this, SLOT(findWindow()));
    connect(ui->actionFont, SIGNAL(triggered(bool)), this, SLOT(setFont()));
    connect(&fWind, SIGNAL(findSignal()), this, SLOT(findInText()));
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::save()
{
    if(openedFile!=""){
        QFile file(openedFile);
        if(!file.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this, tr("Error"),"",tr("Can not write file"));
            return;
        } else {
            QTextStream in(&file);
            in << ui->textEdit->toPlainText();
            in.flush();
            file.close();
        }
    } else Notepad::saveAs();
}

void Notepad::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName();
    if(fileName!=""){
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this, tr("Error"), "", tr("Can not write file"));
            return;
        } else {
            QTextStream in(&file);
            in<<ui->textEdit->toPlainText();
            in.flush();
            file.close();
        }
    }
}

void Notepad::open()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName != ""){
        QFile inputFile(fileName);
        if(!inputFile.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this,tr("Error"),"",tr("Can notopen file"));
        } else {
            QString buffer;
            QTextStream in(&inputFile);
            buffer = in.readAll();
            inputFile.close();
            ui->textEdit->setPlainText(buffer);
        }
    }
}

void Notepad::about(){
    aboutWidget *w = new aboutWidget;
    w->show();
}

void Notepad::findWindow(){
    fWind.show();
}

void Notepad::findInText(){
    this->focusWidget();
    QString searchString = fWind.getSearchString();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
}

void Notepad::setFont(){
    ui->textEdit->setFont(QFontDialog::getFont(0, ui->textEdit->font()));
}
