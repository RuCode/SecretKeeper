#include "jail/dialogcreate.h"
#include "ui_dialogcreatejail.h"

DialogCreateJail::DialogCreateJail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreateJail)
{
    ui->setupUi(this);
    ui->lineEdit_Path->setText(QApplication::applicationDirPath()+
            QDir::separator()+QString("main.jpk"));
    ResultDlg = 0;
}

DialogCreateJail::~DialogCreateJail()
{
    delete ui;
}

QString DialogCreateJail::GeneratePassword()
{
    int MAX_PASS_LEN = 14;
    QByteArray table;
    table.append("1234567890!@#$%^&*()_+-qwertyuiop[]\asdfghjkl;'zxcvbnm,./QWE"
                 "RTYUIOP{}|ASDFGHJKL:ZXCVBNM<>?");
    QString TmpPassword;
    int rand_pos = 0;

    for (int i = 1; i < MAX_PASS_LEN; ++i)
    {
        rand_pos = rand() % table.count();
        TmpPassword.append(table.at(rand_pos));
    }
    return TmpPassword;
}

void DialogCreateJail::on_pushButton_Gen_clicked()
{
    ui->lineEdit_PassFirst->setText(GeneratePassword());
    ui->lineEdit_PassLast->setText(ui->lineEdit_PassFirst->text());
}

void DialogCreateJail::on_pushButton_hide_clicked()
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

bool DialogCreateJail::VerifyCorrectData()
{
    bool PassFirst = !ui->lineEdit_PassFirst->text().isEmpty();
    bool PassLast = !ui->lineEdit_PassLast->text().isEmpty();
    bool PassEqual = (ui->lineEdit_PassFirst->text() == ui->lineEdit_PassLast->text());

    //******************************************************************************
        #pragma message WARN("Не верное логическое выражение")
    //******************************************************************************

    IsCorrectPassword = PassFirst && PassLast && PassEqual;
    return IsCorrectPassword;
}

void DialogCreateJail::on_pushButton_Cancel_clicked()
{
    ResultDlg = 0;
    close();
}

void DialogCreateJail::on_pushButton_Save_clicked()
{
    if (VerifyCorrectData()) {
        IsOpenJailAuto = ui->checkBox_AutoOpen->isChecked();
        currentPassword = ui->lineEdit_PassFirst->text();
        pathToJail = ui->lineEdit_Path->text();
        ResultDlg = 1;
        close();
    } else {
        QMessageBox::warning(this, tr("Внимание"), tr("Не все данные введены..."), QMessageBox::Ok);
    }
}
