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
#include <QPalette>
#include <QTextCursor>

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    openedFile="";
    cursor = new QTextCursor(ui->textEdit->textCursor());
    connect(ui->actionExit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(open()));
    connect(ui->actionSave_as, SIGNAL(triggered(bool)), this, SLOT(saveAs(bool)));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save()));
    connect(ui->actionUndo, SIGNAL(triggered(bool)), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered(bool)), ui->textEdit, SLOT(redo()));
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(about()));

    connect(ui->actionReplace, SIGNAL(triggered(bool)), this, SLOT(replaceWindow()));
    connect(ui->actionFind, SIGNAL(triggered(bool)), this, SLOT(findWindow()));
    connect(ui->actionFont, SIGNAL(triggered(bool)), this, SLOT(setFont()));

    connect(&fWind, SIGNAL(findSignal()), this, SLOT(findInText()));
    connect(&fWind, SIGNAL(replaceSignal()), this, SLOT(replaceInText()));
    connect(&fWind, SIGNAL(replaceAllSignal()), this, SLOT(replaceAll()));

    connect(ui->actionFind_next, SIGNAL(triggered(bool)), this, SLOT(findInText()));

    connect(ui->actionCreate, SIGNAL(triggered(bool)), this, SLOT(createFile()));

    connect(ui->actionCut, SIGNAL(triggered(bool)), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered(bool)), ui->textEdit, SLOT(copy()));
    connect(ui->actionSelect_all, SIGNAL(triggered(bool)), ui->textEdit, SLOT(selectAll()));
    connect(ui->actionPaste, SIGNAL(triggered(bool)), ui->textEdit, SLOT(paste()));

    connect(ui->actionLineWrap, SIGNAL(triggered(bool)), this, SLOT(setLineWarp(bool)));

    ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);


    pal = ui->textEdit->palette();
    QColor highlight = pal.color(QPalette::Active, QPalette::Highlight);
    pal.setColor(QPalette::Inactive, QPalette::Highlight, highlight);
    pal.setColor(QPalette::Inactive, QPalette::HighlightedText, Qt::white);
    ui->textEdit->setPalette(pal);
}

Notepad::~Notepad(){
    delete ui;
}

void Notepad::save(){
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
    } else Notepad::saveAs(1);
}

void Notepad::saveAs(bool fromSave){
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
    if(fromSave) openedFile=fileName;
}

void Notepad::open(){
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
    fWind.setReplace(false);
}

void Notepad::replaceWindow(){
    fWind.show();
    fWind.setReplace(true);
}

bool Notepad::findInText(){
    bool findDown;
    QString searchString = fWind.getSearchString();
    findDown = fWind.getSearchDirection();

    if(findDown)
        return ui->textEdit->find(searchString);
    else
        return ui->textEdit->find(searchString, QTextDocument::FindBackward );
}

void Notepad::replaceInText(){
    QString rplcStr = fWind.getReplaceString();
    QString srchStr = fWind.getSearchString();
    if(rplcStr==srchStr) return;
    if(ui->textEdit->textCursor().selectedText()==srchStr)
        ui->textEdit->insertPlainText(rplcStr);
    else
        findInText();
}

void Notepad::replaceAll(){
    while(findInText()) replaceInText();
    QMessageBox::information(this, tr("Replace All"),"Ok",1);
    fWind.close();
}

void Notepad::setFont(){
    ui->textEdit->setFont(QFontDialog::getFont(0, ui->textEdit->font()));
}

void Notepad::createFile(){
    if(openedFile=="") this->save();
    openedFile="";
    ui->textEdit->clear();
}

void Notepad::setLineWarp(bool toggld){
    if(!toggld){
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    } else {
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
    }
}
