#include "dialogchild.h"
#include "ui_dialogchild.h"

DialogChild::DialogChild(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChild)
{
    ui->setupUi(this);
}

DialogChild::~DialogChild()
{
    delete ui;
}
