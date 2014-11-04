#include "qvectortreewidget.h"

QVectorTreeWidget::QVectorTreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    CloseAll();
}

QVectorTreeWidget::~QVectorTreeWidget()
{
    CloseAll();
}

bool QVectorTreeWidget::rangeCheck(int rootIndex, int childIndex)
// Проверка границ qVector, false - ошибка, true - успех
{
    if ((rootIndex < 0) || (rootIndex > RootCountItems())) {
        qDebug() << "Range check error rootIndex";
        return false;
    }
    if (childIndex == INVALID_VALUE) {
        qDebug() << "Range check succes... But childIndex is invalid, maybe root item";
        return true;
    }
    if ((childIndex < 0) || (childIndex > ChildCountItems(rootIndex))) {
        qDebug() << "Range check error childIndex";
        return false;
    }
    qDebug() << "Range check succes...";
    return true;
}

int QVectorTreeWidget::RootCountItems()
// Количество разделов
{
    return dataPasswords.count() - INCREMENT_VALUE;
}

int QVectorTreeWidget::ChildCountItems(int rootIndex)
// Количество элементов раздела
{
    return dataPasswords[rootIndex].items.count() - INCREMENT_VALUE;
}

int QVectorTreeWidget::NewRoot(const QString text)
// Создание раздела
{
    qDebug() << "NewRoot::Default rootCount = " << RootCountItems();

    Root newRootItem;
    newRootItem.id = RootCountItems() + INCREMENT_VALUE;
    newRootItem.name = text;
    newRootItem.items.clear();
    newRootItem.item = new QTreeWidgetItem(this);
    newRootItem.item->setText(COLUMN_TEXT, text);
    newRootItem.item->setData(COLUMN_TEXT, Qt::UserRole, QVariant(newRootItem.id));
    #ifdef COUNT_COLUMNS_4
    newRootItem.item->setText(COLUMN_ROOT, QString::number(newRootItem.id));
    newRootItem.item->setText(COLUMN_CHILD, QString::number(INVALID_VALUE));
    newRootItem.item->setText(COLUMN_PASSWORD, tr(""));
    #endif
    dataPasswords.append(newRootItem);

    qDebug() << "NewRoot::Current rootCount = " << RootCountItems();
    return RootCountItems();
}

int QVectorTreeWidget::NewChild(const QString text, QString data)
{
    if (!rangeCheck(lastSel.root)) {
        return INVALID_VALUE;
    }
    return NewChild(lastSel.root, text, data);
}

int QVectorTreeWidget::NewChild(int rootId, const QString text, QString data)
// Создание элемента
{
    qDebug() << "NewChild::Current rootId = " << rootId;
    qDebug() << "NewChild::Current childId = " << ChildCountItems(rootId);
    if (!rangeCheck(rootId)) {
        return INVALID_VALUE;
    }
    Node newNodeItem;
    newNodeItem.id = ChildCountItems(rootId) + INCREMENT_VALUE;
    newNodeItem.description = text;
    newNodeItem.password = data;
    newNodeItem.item = new QTreeWidgetItem(dataPasswords[rootId].item);
    newNodeItem.item->setText(COLUMN_TEXT, text);
    newNodeItem.item->setData(COLUMN_TEXT, Qt::UserRole, QVariant(newNodeItem.id));
    #ifdef COUNT_COLUMNS_4
    newNodeItem.item->setText(COLUMN_ROOT, QString::number(rootId));
    newNodeItem.item->setText(COLUMN_CHILD, QString::number(newNodeItem.id));
    newNodeItem.item->setText(COLUMN_PASSWORD, data);
    #endif
    dataPasswords[rootId].items.append(newNodeItem);

    qDebug() << "NewChild::Current rootId = " << rootId;
    qDebug() << "NewChild::Current childId = " << newNodeItem.id;
    return ChildCountItems(rootId);
}

void QVectorTreeWidget::updateLinks()
// После удаления элементов портиться ссылочная целостность вектора, в данной функции обновляем её..
{
    for (int i = 0; i <= RootCountItems(); ++i) {
        dataPasswords[i].id = i;
        dataPasswords[i].item->setData(COLUMN_TEXT, Qt::UserRole, QVariant(i));
        dataPasswords[i].item->setText(COLUMN_ROOT, QString::number(i));
        dataPasswords[i].item->setText(COLUMN_CHILD, QString::number(INVALID_VALUE));
        for (int j = 0; j <= ChildCountItems(i); ++j) {
            dataPasswords[i].items[j].id = j;
            dataPasswords[i].items[j].item->setData(COLUMN_TEXT, Qt::UserRole, QVariant(j));
            dataPasswords[i].items[j].item->setText(COLUMN_ROOT, QString::number(i));
            dataPasswords[i].items[j].item->setText(COLUMN_CHILD, QString::number(j));
        }
    }
}

void QVectorTreeWidget::UpdateRoot(int rootId, const QString text)
// Задание нового имени разделу
{
    if (!rangeCheck(rootId)) {
        return ;
    }
    dataPasswords[rootId].name = text;
    dataPasswords[rootId].item->setText(COLUMN_TEXT, text);
}

void QVectorTreeWidget::UpdateChild(int rootId, int childId, const QString text, QString data)
// Изменение значений элемента
{
    if (!rangeCheck(rootId, childId)) {
        return ;
    }
    dataPasswords[rootId].items[childId].description = text;
    dataPasswords[rootId].items[childId].password = data;
    dataPasswords[rootId].items[childId].item->setText(COLUMN_TEXT, text);
    dataPasswords[rootId].items[childId].item->setText(COLUMN_PASSWORD, data);
}

void QVectorTreeWidget::UpdateRoot(const QString text)
{    
    if (!rangeCheck(lastSel.root)) {
        return ;
    }
    UpdateRoot(lastSel.root, text);
}

void QVectorTreeWidget::UpdateChild(const QString text, QString data)
{
    if (!rangeCheck(lastSel.root, lastSel.child)) {
        return ;
    }
    UpdateChild(lastSel.root, lastSel.child, text, data);
}

bool QVectorTreeWidget::Delete()
// Удаление последнего выбранного элемента
{
    if (!rangeCheck(lastSel.root, lastSel.child)) {
        return false;
    }
    if ((lastSel.child == INVALID_VALUE) && (lastSel.root == INVALID_VALUE))
    {
        return false;
    }
    if (lastSel.child == INVALID_VALUE) {
        Delete(lastSel.root);
    } else {
        Delete(lastSel.root, lastSel.child);
    }
    lastSel.child = INVALID_VALUE;
    lastSel.root = INVALID_VALUE;
    return true;
}

void QVectorTreeWidget::Delete(int rootId)
// Удаление раздела целиком
{
    if (!rangeCheck(rootId)) {
        return ;
    }
    for (int i = 0; i <= ChildCountItems(rootId); ++i)
    {
        Delete(rootId, i);
    }
    this->takeTopLevelItem(rootId);
    dataPasswords.takeAt(rootId);
    updateLinks();
}

void QVectorTreeWidget::Delete(int rootId, int childId)
// Удаление элемента
{
    if (!rangeCheck(rootId, childId)) {
        return ;
    }
    dataPasswords[rootId].item->takeChild(childId);
    dataPasswords[rootId].items.takeAt(childId);
    updateLinks();
}

void QVectorTreeWidget::SaveSelect(QTreeWidgetItem *item)
// Сохранение индексов выбранного элемента
{
    lastSel.root = QVariant(item->text(COLUMN_ROOT)).toInt();
    lastSel.child = QVariant(item->text(COLUMN_CHILD)).toInt();
}

void QVectorTreeWidget::ClearAll()
// Очистка всего
{
    this->clear();
    dataPasswords.clear();
    lastSel.child = INVALID_VALUE;
    lastSel.root = INVALID_VALUE;
}

void QVectorTreeWidget::SetPassword(const QString pass)
// Установка пароля
{
    password.clear();
    password = pass.trimmed();
}

void QVectorTreeWidget::SaveToFile()
{
    if (!lastFilePath.isEmpty()) {
        SaveToFile(lastFilePath);
    }
}

void QVectorTreeWidget::SaveToFile(const QString FileName)
// Сохранение в файл всех записей
{
    qDebug() << "SaveToFile with " << password;
    QByteArray passArray;
    passArray+= password;
    QFile encryptedFile(FileName);
    CryptFileDevice cryptFileDevice(&encryptedFile, passArray, "any salt");
    if (!cryptFileDevice.open(QIODevice::WriteOnly))
    {
        qDebug() << ("Not open ") << FileName;
        return ;
    }
    QDataStream out(&cryptFileDevice);
    out << dataPasswords.count();
    for (int RootCounter = 0; RootCounter < dataPasswords.count(); ++RootCounter)
    {
        out << dataPasswords[RootCounter].id;
        out << dataPasswords[RootCounter].name;
        out << ChildCountItems(RootCounter);
        for (int ChildCounter = 0; ChildCounter <= ChildCountItems(RootCounter); ++ChildCounter)
        {
            out << dataPasswords[RootCounter].items[ChildCounter].id;
            out << dataPasswords[RootCounter].items[ChildCounter].description;
            out << dataPasswords[RootCounter].items[ChildCounter].password;
        }
    }
    cryptFileDevice.close();
}

bool QVectorTreeWidget::LoadFromFile(const QString fileName)
// Чтение из файла всех записей
{
    ClearAll();

    qDebug() << "LoadFromFile with " << password;
    QByteArray passArray;
    passArray+= password;
    QFile encryptedFile(fileName);
    CryptFileDevice cryptFileDevice(&encryptedFile, passArray, "any salt");
    if (!cryptFileDevice.open(QIODevice::ReadOnly))
    {
        qDebug() << ("Not open ") << fileName;
        return false;
    }
    QDataStream in(&cryptFileDevice);

    Root hRoot;
    Node hNode;
    int FileRootCount;
    int FileChildCount;
    in >> FileRootCount;
    for (int RootCounter = 0; RootCounter < FileRootCount; ++RootCounter)
    {
        in >> hRoot.id;
        in >> hRoot.name;
        in >> FileChildCount;
        NewRoot(hRoot.name);
        for (int ChildCounter = 0; ChildCounter <= FileChildCount; ++ChildCounter)
        {
            in >> hNode.id;
            in >> hNode.description;
            in >> hNode.password;
            NewChild(hRoot.id, hNode.description, hNode.password);
        }
    }
    cryptFileDevice.close();
    lastFilePath = fileName;
    return true;
}

void QVectorTreeWidget::CloseAll()
{
    dataPasswords.clear();
    lastSel.child = INVALID_VALUE;
    lastSel.root = INVALID_VALUE;
    password.clear();
    lastFilePath.clear();
}
