#ifndef QPASSWORDDIALOG_H
#define QPASSWORDDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "_application.h"

namespace Ui {
class QPasswordDialog;
}

class QPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    eResultBox resultBox;
    QString password;
    explicit QPasswordDialog(QWidget *parent = 0);
    ~QPasswordDialog();

private slots:
    void on_pushButton_Save_clicked();

    void on_pushButton_Close_clicked();

    void on_pushButton_clicked();

private:
    Ui::QPasswordDialog *ui;
};

#endif // QPASSWORDDIALOG_H
