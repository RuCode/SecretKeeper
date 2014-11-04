#ifndef QCREATEJAILBOX_H
#define QCREATEJAILBOX_H

#include <QMessageBox>
#include <QFileDialog>
#include <QDialog>
#include <QDir>

#include "_application.h"

namespace Ui {
class QCreateJailBox;
}

class QCreateJailBox : public QDialog
{
    Q_OBJECT

public:
    eResultBox resultBox;
    bool isCorrectPassword;
    bool isOpenJailAuto;
    QString currentPassword;
    QString pathToJail;
    explicit QCreateJailBox(QWidget *parent = 0);
    ~QCreateJailBox();

private slots:
    void on_pushButton_Save_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Path_clicked();

    void on_pushButton_Gen_clicked();

    void on_pushButton_hide_clicked();

    void on_lineEdit_PassFirst_returnPressed();

private:
    Ui::QCreateJailBox *ui;
    bool VerifyCorrectData();
    QString GeneratePassword();
};

#endif // QCREATEJAILBOX_H
