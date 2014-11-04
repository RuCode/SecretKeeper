#ifndef QCREATEROOTITEMBOX_H
#define QCREATEROOTITEMBOX_H

#include <QDialog>
#include <QMessageBox>
#include "_application.h"

namespace Ui {
class QCreateRootItemBox;
}

class QCreateRootItemBox : public QDialog
{
    Q_OBJECT

public:
    eResultBox resultBox;
    QString currentName;
    explicit QCreateRootItemBox(QWidget *parent = 0);
    ~QCreateRootItemBox();

private slots:
    void on_pushButton_Save_clicked();

private:
    Ui::QCreateRootItemBox *ui;
};

#endif // QCREATEROOTITEMBOX_H
