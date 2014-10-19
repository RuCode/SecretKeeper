#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QVariant>
#include <QByteArray>
#include <QCryptographicHash>
#include <QSplitter>
#include <QTextCodec>
#include <QMessageBox>
#include <QFileDialog>

#include "qjailsafekeys.h"
#include "qpasswordkeeper.h"
#include "dialoginputroot.h"
#include "dialogcreatejail.h"
#include "_warning.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool IsOpenJail;
    QPasswordKeeper PassKeeper;
    QJailSafeKeys SafeKeys;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void QuestionOpen();// Предложение открыть хранилище
    void CreateJail();  // Создать хранилище
    void OpenJail();    // Открыть хранилище
    void SaveJail();    // Сохранить
    void SaveAsJail();  // Сохранить как

private slots:
    void on_action_QPasswordKeeper_activated();
    void SelectPassword(QString Description, QString Password);

    void on_action_QSafeFileJail_activated();

    void on_actionNewRoot_activated();

    void on_actionOpenKeeper_activated();

    void on_actionNewKeeper_activated();

    void on_actionSave_activated();

    void on_actionSaveAs_activated();

    void on_actionClose_activated();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
