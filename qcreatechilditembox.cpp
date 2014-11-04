#include "qcreatechilditembox.h"
#include "ui_qcreatechilditembox.h"

QCreateChildItemBox::QCreateChildItemBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QCreateChildItemBox)
{
    ui->setupUi(this);
    resultBox = rbCancel;
    this->setWindowTitle(tr("Создание новой записи"));
}

bool QCreateChildItemBox::VerifyCorrectData()
{
    bool bPass = !ui->lineEdit_Pass->text().isEmpty();
    bool bName = !ui->lineEdit_Name->text().isEmpty();
    bool isCorrect = (!ui->lineEdit_Pass->text().isEmpty() &&
                      !ui->lineEdit_Name->text().isEmpty());
    return bPass && bName && isCorrect;
}

QString QCreateChildItemBox::GeneratePassword()
{
    return sysGeneratePassword();
}

QCreateChildItemBox::~QCreateChildItemBox()
{
    delete ui;
}

void QCreateChildItemBox::on_pushButton_Hide_clicked()
{
    if (ui->lineEdit_Pass->echoMode() == QLineEdit::Normal)
    {
        ui->lineEdit_Pass->setEchoMode(QLineEdit::Password);
    } else {
        ui->lineEdit_Pass->setEchoMode(QLineEdit::Normal);
    }
}

void QCreateChildItemBox::on_pushButton_GenPass_clicked()
{
    ui->lineEdit_Pass->setText(GeneratePassword());
}

void QCreateChildItemBox::on_pushButton_Save_clicked()
{
    if (VerifyCorrectData()) {
        resultBox = rbOk;
        currentName = ui->lineEdit_Name->text();
        currentPassword = ui->lineEdit_Pass->text();
        close();
    } else {
        int MsgBoxResult = QMessageBox::warning(
                    this,
                    tr("Внимание"),
                    tr("Вы не ввели все необходиммые данные, продолжить ввод?"),
                    QMessageBox::Ok, QMessageBox::Cancel);
        if (MsgBoxResult == QMessageBox::Cancel) {
            close();
        }
    }
}
