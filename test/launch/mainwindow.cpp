#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QObject::connect(ui->treeWidget, SIGNAL(itemActivated(QTreeWidgetItem*,int)),
                        &PassKeeper, SLOT(itemActivated(QTreeWidgetItem*,int)));

    QObject::connect(&PassKeeper, SIGNAL(SelectPassword(QString, QString)),
                        this, SLOT(SelectPassword(QString, QString)));


    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    IsOpenJail = false;

/*

    QSplitter * splitter = new QSplitter(this);

    splitter->addWidget(ui->treeWidget); */

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SelectPassword(QString Description, QString Password)
{
    ui->lineEdit_Name->setText(Description);
    ui->lineEdit_Pass->setText(Password);

    QByteArray HashArray;
    HashArray.append(Password);
    QByteArray hash = QCryptographicHash::hash(HashArray, QCryptographicHash::Sha1);
    ui->lineEdit_Sha1->setText(hash.toHex());
    hash = QCryptographicHash::hash(HashArray, QCryptographicHash::Md5);
    ui->lineEdit_md5->setText(hash.toHex());
}

void MainWindow::on_action_QPasswordKeeper_activated()
{
    PassKeeper.Test();
    PassKeeper.UpdateTreeVidget(ui->treeWidget);
}

void MainWindow::on_action_QSafeFileJail_activated()
{
    SafeKeys.Test();
}

void MainWindow::QuestionOpen()
{
    int ResDlg = QMessageBox::question(this, tr("Вопрос"),
                                       tr("Нет открытого хранилища, открыть?"),
                                       QMessageBox::Yes | QMessageBox::No);
    if (ResDlg == QMessageBox::Yes)
    {
        on_actionOpenKeeper_activated();
    }
}

void MainWindow::on_actionNewRoot_activated()
{
    if (IsOpenJail) {
        DialogInputRoot RootInputDlg;
        RootInputDlg.exec();
        PassKeeper.NewRoot(RootInputDlg.RootNameString);
        PassKeeper.UpdateTreeVidget(ui->treeWidget);
        PassKeeper.SaveToFile();
    } else {
        QuestionOpen();
    }
}

//****************************************************************************//
//                                                                            //
// Функции меню главного окна                                                 //
//                                                                            //
//****************************************************************************//

void MainWindow::on_actionNewKeeper_activated()
{
    CreateJail();
}

void MainWindow::on_actionOpenKeeper_activated()
{
    OpenJail();
}

void MainWindow::on_actionSave_activated()
{
    if (IsOpenJail) {
        SaveJail();
    } else {
        QuestionOpen();
    }
}

void MainWindow::on_actionSaveAs_activated()
{
    if (IsOpenJail) {
        SaveAsJail();
    } else {
        QuestionOpen();
    }
}

void MainWindow::on_actionClose_activated()
{
    if (IsOpenJail) {
        PassKeeper.SaveToFile();
    }
    close();
}


//****************************************************************************//
//                                                                            //
// Основные функции                                                           //
//                                                                            //
//****************************************************************************//

void MainWindow::CreateJail()
{
    PassKeeper.SaveToFile();
    DialogCreateJail CreateJailDlg;
    CreateJailDlg.exec();
    if (CreateJailDlg.ResultDlg == 1)
    {
        if (!CreateJailDlg.IsCorrectPassword)
        {
            QMessageBox::warning(this, tr("Error"), tr("Error IsCorrectedPassword"), QMessageBox::Ok);
            exit(0);
        }
        IsOpenJail = true;
        PassKeeper.Clear();
        PassKeeper.Password = CreateJailDlg.currentPassword;
        PassKeeper.SaveToFile(CreateJailDlg.pathToJail);
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Error result"), QMessageBox::Ok);
    }
}

void MainWindow::OpenJail()
{
    PassKeeper.SaveToFile();
    QStringList fileNames;
    QFileDialog dialog;
    dialog.setFilter(tr("Файлы хранилища (*.jpk)"));
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();
        PassKeeper.LoadFromFile(fileNames[0]);
        PassKeeper.UpdateTreeVidget(ui->treeWidget);
        IsOpenJail = true;
    }
}

void MainWindow::SaveJail()
{
    PassKeeper.SaveToFile();
}

void MainWindow::SaveAsJail()
{
    //******************************************************************************
#pragma message WARN("Нужен другой дилалог")
#pragma message WARN("Нужна проверка открытого файла")
    //******************************************************************************
    QFileDialog dialog;
    dialog.setFilter(tr("Файлы хранилища (*.jpk)"));
    QString fileName = dialog.getSaveFileName();
    if (fileName.isEmpty())
    {
        PassKeeper.SaveToFile(fileName);
        PassKeeper.UpdateTreeVidget(ui->treeWidget);
        IsOpenJail = true;
    }
}
