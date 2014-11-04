#include "qpassworddialog.h"
#include "ui_qpassworddialog.h"

QPasswordDialog::QPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QPasswordDialog)
{
    ui->setupUi(this);
    resultBox = rbError;
    password = "";
    this->setWindowTitle(tr("Ввод пароля"));
}

QPasswordDialog::~QPasswordDialog()
{
    delete ui;
}

void QPasswordDialog::on_pushButton_Save_clicked()
{
    password = ui->lineEdit->text();
    if (!password.isEmpty()) {
        resultBox = rbOk;
        close();
    } else {
        int MsgBoxResult = QMessageBox::warning(this, tr("Внимание"),
                             tr("Вы не ввели пароль, хотите продолжить ввод?"),
                             QMessageBox::Yes, QMessageBox::Cancel);
        if (MsgBoxResult == QMessageBox::Cancel) {
            close();
        }
    }
}

void QPasswordDialog::on_pushButton_Close_clicked()
{
    close();
}

void QPasswordDialog::on_pushButton_clicked()
{
    if (ui->lineEdit->echoMode() == QLineEdit::Password) {
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}
