#ifndef DIALOGCHILD_H
#define DIALOGCHILD_H

#include <QDialog>
#include "_warning.h"

//******************************************************************************
    #pragma message WARN("Не правильный заголовок")
//******************************************************************************

namespace Ui {
class DialogChild;
}

class DialogChild : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogChild(QWidget *parent = 0);
    ~DialogChild();
    
private:
    Ui::DialogChild *ui;
};

#endif // DIALOGCHILD_H
