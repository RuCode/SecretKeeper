#include "input/dialogroot.h"
#include "ui_dialogroot.h"

DialogRoot::DialogRoot(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogRoot)
{
    ui->setupUi(this);
}

DialogRoot::~DialogRoot()
{
    delete ui;
}

void DialogRoot::on_pushButton_clicked()
{
    RootNameString = ui->lineEdit->text();
    close();
}
