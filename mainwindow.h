#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define MSG_TIMEOUT 3000

#include <QTimer>
#include <QClipboard>
#include <QByteArray>
#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QCoreApplication>
#include <QDesktopServices>
#include <QCryptographicHash>

#include "qconfig.h"
#include "qinputdialog.h"
#include "qcreatejailbox.h"
#include "qcreatechilditembox.h"
#include "qcreaterootitembox.h"
#include "qvectortreewidget.h"
#include "qpassworddialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private:
    bool isOpenJail;
    bool isRootKeyOpen;
    QConfig config;
    // Общие
    void message(QString text);
    void setEnabledControlsAndMenu(bool enabledVal);
    void enabledControlsAndMenu();
    void disabledControlsAndMenu();
    void setEnabledRightControls(bool enabledVal);
    void disabledRightControls();
    void enabledRightControls();
    void updateHashes();
    void getHash(QCryptographicHash::Algorithm cryptographicHash);
    void clearSelection();    
    void questionOpen();
    void copyToClipboard(QString text);
    void updateItemFromRightPanel();
    QString getPassword();
    void openJailFromFile(QString filePath);
    void itemSelected(QTreeWidgetItem *item, int column);
    // Меню файл
    void createJail();
    void openJail();
    void saveJail();
    void saveAsJail();
    // Меню хранилище
    void newRoot();
    void newChild();
    void deleteItem();

private slots:

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_Save_clicked();

    void on_lineEdit_Passwd_editingFinished();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionClose_triggered();

    void on_actionNewRoot_triggered();

    void on_actionNewChild_triggered();

    void on_actionSaveChild_triggered();

    void on_actionDeleteItem_triggered();

    void on_actionCopyToClipbrd_triggered();

    void on_pushButton_clicked();

    void on_actionAboutQt_triggered();

    void on_actionGenHardPass_triggered();

    void on_actionGenEasyPass_triggered();

    void on_actionGetMD5_triggered();

    void on_actionGetSha1_triggered();

    void on_actionGetMD4_triggered();

    void on_actionAbout_triggered();

    void on_actionSendEmail_triggered();

    void on_treeWidget_customContextMenuRequested(const QPoint &pos);

    void on_actionNewjail_triggered();

    void on_treeWidget_itemActivated(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
