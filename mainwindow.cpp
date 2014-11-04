#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isRootKeyOpen = false;
    isOpenJail = false;
    disabledControlsAndMenu();
    ui->statusBar->clearMessage();
    if (!config.JailPath().isEmpty()) {
        openJailFromFile(config.JailPath());
    }
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(on_treeWidget_customContextMenuRequested(QPoint)));
    message(tr("Инициализация выполнена успешно"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/***************************************************************************************************
 * Переопределённые методы класса
 **************************************************************************************************/

void MainWindow::closeEvent(QCloseEvent *)
{
    if (isOpenJail) {
        saveJail();
    }
}

/***************************************************************************************************
 * Общие функции окна
 **************************************************************************************************/


void MainWindow::message(QString text)
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(text, MSG_TIMEOUT);
}

void MainWindow::questionOpen()
{
    qDebug() << "QuestionOpen()";
    int ResDlg = QMessageBox::question(this, tr("Вопрос"), tr("Нет открытого хранилища, открыть?"),
                                       QMessageBox::Yes | QMessageBox::No);
    if (ResDlg == QMessageBox::Yes)
    {        
        openJail();
    }
}
void MainWindow::setEnabledControlsAndMenu(bool enabledVal)
{
    ui->actionSave->setEnabled(enabledVal);
    ui->actionSave_as->setEnabled(enabledVal);
    ui->actionNewRoot->setEnabled(enabledVal);
    ui->actionNewChild->setEnabled(enabledVal);
    ui->actionDeleteItem->setEnabled(enabledVal);
    ui->actionCopyToClipbrd->setEnabled(enabledVal);
    ui->actionSaveChild->setEnabled(enabledVal);
    ui->treeWidget->setEnabled(enabledVal);
    ui->lineEdit_Desc->setEnabled(enabledVal);
    ui->pushButton->setEnabled(enabledVal);
    ui->pushButton_Save->setEnabled(enabledVal);
}

void MainWindow::enabledControlsAndMenu()
{
    setEnabledControlsAndMenu(true);
    setEnabledRightControls(true);
}

void MainWindow::disabledControlsAndMenu()
{
    setEnabledControlsAndMenu(false);
    setEnabledRightControls(false);
}

void MainWindow::setEnabledRightControls(bool enabledVal)
{
    ui->lineEdit_Passwd->setEnabled(enabledVal);
    ui->lineEdit_md->setEnabled(enabledVal);
    ui->lineEdit_Sha->setEnabled(enabledVal);
}

void MainWindow::disabledRightControls()
{
    isRootKeyOpen = true;
    setEnabledRightControls(!isRootKeyOpen);
}

void MainWindow::enabledRightControls()
{
    isRootKeyOpen = false;
    setEnabledRightControls(!isRootKeyOpen);
}

void MainWindow::updateHashes()
{
    QByteArray HashArray;
    HashArray.append(ui->lineEdit_Passwd->text());
    QByteArray hash = QCryptographicHash::hash(HashArray, QCryptographicHash::Sha1);
    ui->lineEdit_Sha->setText(hash.toHex());
    hash = QCryptographicHash::hash(HashArray, QCryptographicHash::Md5);
    ui->lineEdit_md->setText(hash.toHex());
}

void MainWindow::getHash(QCryptographicHash::Algorithm cryptographicHash)
{
    QInputDialog InputDlg;
    InputDlg.exec();
    if (InputDlg.resultBox == rbOk) {
        QByteArray HashArray;
        HashArray.append(InputDlg.text);
        QByteArray hash = QCryptographicHash::hash(HashArray, cryptographicHash);
        copyToClipboard(hash.toHex());
    }
}

void MainWindow::clearSelection()
{
    setEnabledRightControls(true);
    ui->lineEdit_Desc->clear();
    ui->lineEdit_Passwd->clear();
    ui->lineEdit_md->clear();
    ui->lineEdit_Sha->clear();
}

void MainWindow::updateItemFromRightPanel()
{
    if (isRootKeyOpen) {
        ui->treeWidget->UpdateRoot(ui->lineEdit_Desc->text());
        message(tr("Обновлено..."));
    } else {
        ui->treeWidget->UpdateChild(ui->lineEdit_Desc->text(), ui->lineEdit_Passwd->text());
        updateHashes();
        message(tr("Обновлено..."));
    }
}

void MainWindow::copyToClipboard(QString text)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(text);
    message(tr("Скопированно в буфер обмена..."));
}

QString MainWindow::getPassword()
{
    QPasswordDialog PasswordDialog;
    PasswordDialog.exec();
    if (PasswordDialog.resultBox == rbOk) {
        return PasswordDialog.password;
    } else {
        return tr("");
    }
}

/***************************************************************************************************
 * Функции главного меню
 **************************************************************************************************/

void MainWindow::createJail()
{
    qDebug() << "CreateJail()";
    if (isOpenJail) {
        saveJail();
        ui->treeWidget->CloseAll();
        disabledControlsAndMenu();
        isOpenJail = false;
    }
    QCreateJailBox CreateJailDlg;
    CreateJailDlg.exec();
    if (CreateJailDlg.resultBox == rbOk)
    {
        if (!CreateJailDlg.isCorrectPassword)
        {
            QMessageBox::warning(this, tr("Ошибка"), tr("Не корректный пароль..."), QMessageBox::Ok);
            exit(0);
        }
        isOpenJail = true;
        ui->treeWidget->ClearAll();
        qDebug() << CreateJailDlg.currentPassword;
        ui->treeWidget->SetPassword(CreateJailDlg.currentPassword);
        ui->treeWidget->SaveToFile(CreateJailDlg.pathToJail);
        if (CreateJailDlg.isOpenJailAuto) {
            config.setJailPath(CreateJailDlg.pathToJail);
        }
        enabledControlsAndMenu();
        disabledRightControls();
        ui->lineEdit_Desc->setEnabled(false);
        message(tr("Хранилище создано успешно"));
    }
}

void MainWindow::openJailFromFile(QString filePath)
{
    if (isOpenJail) {
        saveJail();
        ui->treeWidget->CloseAll();
        disabledControlsAndMenu();
        isOpenJail = false;
    }
    qDebug() << "OpenJailFromFile()";
    QString DbgPas = getPassword();
    if (DbgPas.isEmpty()) {
        return;
    }
    ui->treeWidget->SetPassword(DbgPas);
    qDebug() << DbgPas;
    if (ui->treeWidget->LoadFromFile(filePath)) {
        isOpenJail = true;
        enabledControlsAndMenu();
        disabledRightControls();
        ui->lineEdit_Desc->setEnabled(false);
        message(tr("Хранилище успешно открыто"));
    } else {
        QMessageBox::warning(this, tr("Ошибка"),
                             tr("Введён не верный пароль или файл не является хранилищем..."),
                             QMessageBox::Ok);
        ui->treeWidget->CloseAll();
        isOpenJail = false;
    }
}

void MainWindow::openJail()
{
    if (isOpenJail) {
        saveJail();
        ui->treeWidget->CloseAll();
        disabledControlsAndMenu();
    }
    qDebug() << "OpenJail()";
    QStringList fileNames;
    QFileDialog dialog;
    QString filePath;
    dialog.setNameFilter(tr("Файлы хранилища (*.jpk)"));
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();
        if (!fileNames[0].isEmpty()) {
            filePath = fileNames[0];
        } else {
            return ;
        }
    }
    openJailFromFile(filePath);
}

void MainWindow::saveJail()
{
    qDebug() << "SaveJail()";
    ui->treeWidget->SaveToFile();
    message(tr("Сохранено..."));
}

void MainWindow::saveAsJail()
{
    qDebug() << "SaveAsJail()";
    QFileDialog dialog;
    dialog.setNameFilter(tr("Файлы хранилища (*.jpk)"));
    QString fileName = dialog.getSaveFileName();
    if (!fileName.isEmpty())
    {
        ui->treeWidget->SaveToFile(fileName);
        isOpenJail = true;
        message(tr("Сохранено..."));
    }
}

void MainWindow::newRoot()
{
    qDebug() << "NewRoot()";
    QCreateRootItemBox RootInputDlg;
    RootInputDlg.exec();
    if (RootInputDlg.resultBox == rbOk) {
        ui->treeWidget->NewRoot(RootInputDlg.currentName);
        ui->treeWidget->SaveToFile();
        message(tr("Добавлен новый раздел..."));
    }
}

void MainWindow::newChild()
{
    qDebug() << "NewChild()";
    if (ui->treeWidget->selectedItems().count() > 0) {
        qDebug() << "ChildInputDlg.resultBox == rbOk";
        QCreateChildItemBox ChildInputDlg;
        ChildInputDlg.exec();
        if (ChildInputDlg.resultBox == rbOk) {
            ui->treeWidget->NewChild(ChildInputDlg.currentName, ChildInputDlg.currentPassword);
            message(tr("Добавлена запись..."));
        }
    } else {
        QMessageBox::warning(this,
                             tr("Ошибка"),
                             tr("Не допустимый индекс родительского элемента..."),
                             QMessageBox::Ok);
        return ;
    }
}

void MainWindow::deleteItem()
{
    if (ui->treeWidget->Delete())
    {
        message(tr("Удалено..."));
    }
}

/***************************************************************************************************
 * Тригеры и слоты
 **************************************************************************************************/

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    clearSelection();

    if (column != 0) {
        qDebug() << "Error column in MainWindow::on_treeWidget_itemDoubleClicked";
        return ;
    }
    if (QVariant(item->text(COLUMN_CHILD)).toInt() == INVALID_VALUE) {
        disabledRightControls();
    } else {
        enabledRightControls();
    }
    ui->lineEdit_Desc->setEnabled(true);
    ui->lineEdit_Desc->setText(item->text(COLUMN_TEXT));
    ui->lineEdit_Passwd->setText(item->text(COLUMN_PASSWORD));
    if (!isRootKeyOpen) {
        updateHashes();
    }
    ui->treeWidget->SaveSelect(item);
}

void MainWindow::on_pushButton_Save_clicked()
{
    updateItemFromRightPanel();
}

void MainWindow::on_lineEdit_Passwd_editingFinished()
{
    updateHashes();
}

void MainWindow::on_actionOpen_triggered()
{
    openJail();
}


void MainWindow::on_actionSave_triggered()
{
    if (isOpenJail) {
        saveJail();
    } else {
        questionOpen();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    if (isOpenJail) {
        saveAsJail();
    } else {
        questionOpen();
    }
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_actionNewRoot_triggered()
{
    if (isOpenJail) {
        newRoot();
    } else {
        questionOpen();
    }
}

void MainWindow::on_actionNewChild_triggered()
{
    if (isOpenJail) {
        newChild();
    } else {
        questionOpen();
    }
}

void MainWindow::on_actionSaveChild_triggered()
{
    updateItemFromRightPanel();
}

void MainWindow::on_actionDeleteItem_triggered()
{
    deleteItem();
}

void MainWindow::on_actionCopyToClipbrd_triggered()
{
    copyToClipboard(ui->lineEdit_Passwd->text());
}

void MainWindow::on_pushButton_clicked()
{
    copyToClipboard(ui->lineEdit_Passwd->text());
}

void MainWindow::on_actionAboutQt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionGenHardPass_triggered()
{
    copyToClipboard(sysGeneratePassword());
}

void MainWindow::on_actionGenEasyPass_triggered()
{
    copyToClipboard(sysGeneratePhrase());
}

void MainWindow::on_actionGetMD5_triggered()
{
    getHash(QCryptographicHash::Md5);
}

void MainWindow::on_actionGetSha1_triggered()
{
    getHash(QCryptographicHash::Sha1);
}

void MainWindow::on_actionGetMD4_triggered()
{
    getHash(QCryptographicHash::Md4);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("О программе..."),
                       tr("SecretKeeper - 11.2014\n"
                       "github.com/RuCode\n"));
}

void MainWindow::on_actionSendEmail_triggered()
{
    QDesktopServices::openUrl(tr("mailto:i.rcode@yandex.ru?subject=Bug in SecretKeeper"));
}

void MainWindow::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu=new QMenu(this);

    bool isSelected = (ui->treeWidget->selectedItems().count() > 0);
    if (isSelected) {
        ui->treeWidget->itemDoubleClicked(ui->treeWidget->selectedItems().first(), 0);
    }
    menu->addAction(QString("Создать раздел"), this,
                    SLOT(on_actionNewRoot_triggered()))->setEnabled(isOpenJail);
    menu->addSeparator();
    menu->addAction(QString("Создать запись"), this,
                    SLOT(on_actionNewChild_triggered()))->setEnabled(isSelected && isOpenJail);
    menu->addAction(QString("Сохранить"),this,
                    SLOT(on_actionSaveChild_triggered()))->setEnabled(isSelected && isOpenJail);
    menu->addAction(QString("Удалить"),this,
                    SLOT(on_actionDeleteItem_triggered()))->setEnabled(isSelected && isOpenJail);
    menu->addSeparator();
    menu->addAction(QString("Копировать в буфер обмена"), this,
                    SLOT(on_actionCopyToClipbrd_triggered()))->setEnabled(isSelected && isOpenJail);

    menu->popup(ui->treeWidget->viewport()->mapToGlobal(pos));
}

void MainWindow::on_actionNewjail_triggered()
{
    createJail();
}
