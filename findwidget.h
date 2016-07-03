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
    QString getReplaceString();
    bool getSearchDirection();
    void setReplace(bool);

signals:
    void findSignal();
    void replaceSignal();
    void replaceAllSignal();

private slots:
    void setSearchString(QString);
    void setSearchDirection(bool);
    void setReplaceString(QString);

private:
    Ui::findWidget *ui;
    QString SearchStr;
    bool isdown;
    bool isreplace;
    QString replaceStr;
};

#endif // FINDWIDGET_H
