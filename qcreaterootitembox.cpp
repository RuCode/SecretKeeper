#include "qcreaterootitembox.h"
#include "ui_qcreaterootitembox.h"

QCreateRootItemBox::QCreateRootItemBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QCreateRootItemBox)
{
    ui->setupUi(this);
    resultBox = rbCancel;
    currentName = "";
    this->setWindowTitle(tr("Создание раздела"));
}

QCreateRootItemBox::~QCreateRootItemBox()
{
    delete ui;
}

void QCreateRootItemBox::on_pushButton_Save_clicked()
{
    currentName = ui->lineEdit->text();
    if (!currentName.isEmpty()) {
        resultBox = rbOk;
        close();
    } else {
        int MsgBoxResult = QMessageBox::warning(this, tr("Внимание"),
                             tr("Вы не ввели название элемента, хотите продолжить ввод?"),
                             QMessageBox::Yes, QMessageBox::Cancel);
        if (MsgBoxResult == QMessageBox::Cancel) {
            close();
        }
    }
}
