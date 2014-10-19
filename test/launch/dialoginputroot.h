#ifndef DIALOGINPUTROOT_H
#define DIALOGINPUTROOT_H

#include <QDialog>
#include <QString>

#include "_warning.h"

namespace Ui {
class DialogInputRoot;
}

class DialogInputRoot : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogInputRoot(QWidget *parent = 0);
    ~DialogInputRoot();
    QString RootNameString;
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogInputRoot *ui;
};

#endif // DIALOGINPUTROOT_H
