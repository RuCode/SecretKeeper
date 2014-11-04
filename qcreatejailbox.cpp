#include "qcreatejailbox.h"
#include "ui_qcreatejailbox.h"

QCreateJailBox::QCreateJailBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QCreateJailBox)
{
    ui->setupUi(this);
    ui->lineEdit_Path->setText(
                    QApplication::applicationDirPath()+QDir::separator()+QString("main.jpk")
                );
    resultBox = rbError;
    this->setWindowTitle(tr("Создание хранилища"));
}

QCreateJailBox::~QCreateJailBox()
{
    delete ui;
}

QString QCreateJailBox::GeneratePassword()
{
    return sysGeneratePassword();
}

bool QCreateJailBox::VerifyCorrectData()
{
    bool PassFirst = !ui->lineEdit_PassFirst->text().isEmpty();
    bool PassLast = !ui->lineEdit_PassLast->text().isEmpty();
    bool PassEqual = (ui->lineEdit_PassFirst->text() == ui->lineEdit_PassLast->text());
    isCorrectPassword = (!ui->lineEdit_PassFirst->text().isEmpty() &&
                         !ui->lineEdit_PassLast->text().isEmpty());
    return PassFirst && PassLast && PassEqual && isCorrectPassword;
}

void QCreateJailBox::on_pushButton_Save_clicked()
{
    if (VerifyCorrectData()) {
        isOpenJailAuto = ui->checkBox_AutoOpen->isChecked();
        currentPassword = ui->lineEdit_PassFirst->text();
        pathToJail = ui->lineEdit_Path->text();
        resultBox = rbOk;
        close();
    } else {
        QMessageBox::warning(this, tr("Внимание"), tr("Не все данные введены..."), QMessageBox::Ok);
    }
}

void QCreateJailBox::on_pushButton_Cancel_clicked()
{
    resultBox = rbCancel;
    close();
}

void QCreateJailBox::on_pushButton_Path_clicked()
{
    QFileDialog dialog;
    dialog.setNameFilter(tr("Файлы хранилища (*.jpk)"));
    QString fileName = dialog.getSaveFileName();
    if (!fileName.isEmpty())
    {
        ui->lineEdit_Path->setText(fileName);
    }
}

void QCreateJailBox::on_pushButton_Gen_clicked()
{
    QString newPass = GeneratePassword();
    ui->lineEdit_PassFirst->setText(newPass);
    ui->lineEdit_PassLast->setText(newPass);
}

void QCreateJailBox::on_pushButton_hide_clicked()
{
    if (ui->lineEdit_PassFirst->echoMode() == QLineEdit::Normal)
    {
        ui->lineEdit_PassFirst->setEchoMode(QLineEdit::Password);
        ui->lineEdit_PassLast->setEchoMode(QLineEdit::Password);
    } else {
        ui->lineEdit_PassFirst->setEchoMode(QLineEdit::Normal);
        ui->lineEdit_PassLast->setEchoMode(QLineEdit::Normal);
    }
}

void QCreateJailBox::on_lineEdit_PassFirst_returnPressed()
{
    on_pushButton_Gen_clicked();
}
