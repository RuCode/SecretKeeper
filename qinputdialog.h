#ifndef QINPUTDIALOG_H
#define QINPUTDIALOG_H

#include <QDialog>

#include "_application.h"

namespace Ui {
class QInputDialog;
}

class QInputDialog : public QDialog
{
    Q_OBJECT

public:
    eResultBox resultBox;
    QString text;
    explicit QInputDialog(QWidget *parent = 0);
    ~QInputDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QInputDialog *ui;
};

#endif // QINPUTDIALOG_H
