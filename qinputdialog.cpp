#include "qinputdialog.h"
#include "ui_qinputdialog.h"

QInputDialog::QInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QInputDialog)
{
    ui->setupUi(this);
    resultBox = rbError;
    text.clear();
    this->setWindowTitle(tr("Ввод"));
}

QInputDialog::~QInputDialog()
{
    delete ui;
}

void QInputDialog::on_pushButton_clicked()
{
    text = ui->lineEdit->text();
    resultBox = rbOk;
    close();
}
