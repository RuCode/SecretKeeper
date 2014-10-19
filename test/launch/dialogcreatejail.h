#ifndef DIALOGCREATEJAIL_H
#define DIALOGCREATEJAIL_H

#include <QDialog>
#include <QString>
#include <QByteArray>
#include <QMessageBox>
#include <QDir>
#include <qmath.h>

#include "_warning.h"

namespace Ui {
class DialogCreateJail;
}

class DialogCreateJail : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogCreateJail(QWidget *parent = 0);
    ~DialogCreateJail();

    int     ResultDlg;
    bool    IsCorrectPassword;
    bool    IsOpenJailAuto;
    QString currentPassword;
    QString pathToJail;
    
private slots:

    void on_pushButton_Gen_clicked();

    void on_pushButton_hide_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Save_clicked();

private:
    bool VerifyCorrectData();
    QString GeneratePassword();
    Ui::DialogCreateJail *ui;
};

#endif // DIALOGCREATEJAIL_H
