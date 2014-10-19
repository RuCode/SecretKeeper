#ifndef DIALOGROOT_H
#define DIALOGROOT_H

#include <QDialog>
#include <QString>

#include "_warning.h"


//******************************************************************************
    #pragma message WARN("Не правильный заголовок")
//******************************************************************************

namespace Ui {
class DialogRoot;
}

class DialogRoot : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRoot(QWidget *parent = 0);
    ~DialogRoot();
    QString RootNameString;
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogRoot *ui;
};

#endif // DIALOGROOT_H
