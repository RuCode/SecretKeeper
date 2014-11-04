#ifndef QCREATECHILDITEMBOX_H
#define QCREATECHILDITEMBOX_H

#include <QDialog>
#include <QMessageBox>

#include "_application.h"

namespace Ui {
class QCreateChildItemBox;
}

class QCreateChildItemBox : public QDialog
{
    Q_OBJECT

public:
    eResultBox resultBox;
    QString currentName;
    QString currentPassword;
    explicit QCreateChildItemBox(QWidget *parent = 0);
    ~QCreateChildItemBox();

private slots:
    void on_pushButton_Save_clicked();

    void on_pushButton_Hide_clicked();

    void on_pushButton_GenPass_clicked();

private:
    Ui::QCreateChildItemBox *ui;
    bool VerifyCorrectData();
    QString GeneratePassword();
};

#endif // QCREATECHILDITEMBOX_H
