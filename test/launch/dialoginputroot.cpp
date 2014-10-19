#include "dialoginputroot.h"
#include "ui_dialoginputroot.h"

DialogInputRoot::DialogInputRoot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInputRoot)
{
    ui->setupUi(this);
}

DialogInputRoot::~DialogInputRoot()
{
    delete ui;
}

void DialogInputRoot::on_pushButton_clicked()
{
    RootNameString = ui->lineEdit->text();
    close();
}
