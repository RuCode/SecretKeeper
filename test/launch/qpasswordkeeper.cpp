#include "qpasswordkeeper.h"

#define DEBUG3

QPasswordKeeper::QPasswordKeeper(QObject *parent) :
    QObject(parent)
{
    DataPasswords.clear();
    Password = "";
    FilePath = "";
}


int QPasswordKeeper::RootCountItems()
{
    return DataPasswords.count() - 1;
}

int QPasswordKeeper::ChildCountItems(int RootIndex)
{
    return DataPasswords.at(RootIndex).Items.count() - 1;
}

// New Root Item
int QPasswordKeeper::NewRoot(QString AName)
{
    Root NewRootItem;
    NewRootItem.ID = RootCountItems()+1;
    NewRootItem.Name = AName;
    NewRootItem.Items.clear();
    DataPasswords.append(NewRootItem);
    return NewRootItem.ID;
}

// Remove Root Item
void QPasswordKeeper::FreeRoot(int Index)
{
    DataPasswords.remove(Index);
}

// Get root description
QString QPasswordKeeper::GetRoot(int Index)
{
    if ((Index < 0) || (Index > RootCountItems())) {
        #ifdef DEBUG
            qDebug() << tr("Func GetRoot is Aborted");
        #endif
        return tr("Error");
    }
    return DataPasswords.at(Index).Name;
}

// Set Root Description
void QPasswordKeeper::SetRoot(int Index, QString AName)
{    
    if ((Index < 0) || (Index > RootCountItems())) {
        #ifdef DEBUG
            qDebug() << tr("Func SetRoot is Aborted");
        #endif
        return;
    }

    DataPasswords[Index].Name = AName;
}

// New child Items
int QPasswordKeeper::NewChild(int RootIndex, QString APassword, QString ADescription)
{
    Node NewNodeItem;
    NewNodeItem.Description = ADescription;
    NewNodeItem.Password = APassword;
    NewNodeItem.ID = ChildCountItems(RootIndex) + 1;
    DataPasswords[RootIndex].Items.append(NewNodeItem);
    return NewNodeItem.ID;
}

// Free child Items
void QPasswordKeeper::FreeChild(int RootIndex, int Index)
{
    DataPasswords[RootIndex].Items.remove(Index);
}

// Get child password
QString QPasswordKeeper::GetChildPassword(int RootIndex, int Index)
{
    if ((RootIndex < 0) || (RootIndex > RootCountItems())) {
        #ifdef DEBUG
            qDebug() << tr("Func GetChildPassword is Aborted with invalid RootIndex: ") << RootIndex;
            qDebug() << tr("RootCount: ") << RootCountItems();
        #endif
        return tr("Error");
    }
    if ((Index < 0) | (Index > ChildCountItems(RootIndex))) {
        #ifdef DEBUG
            qDebug() << tr("Func GetChildPassword is Aborted with invalid ChildIndex");
        #endif
        return tr("Error");
    }
    return DataPasswords[RootIndex].Items[Index].Password;
}

// Get child description
QString QPasswordKeeper::GetChildDescription(int RootIndex, int Index)
{
    if ((RootIndex < 0) || (RootIndex > RootCountItems())) {
        #ifdef DEBUG
            qDebug() << tr("Func GetChildDescription is Aborted with invalid RootIndex");
        #endif
        return tr("Error");
    }
    if ((Index < 0) || (Index > ChildCountItems(RootIndex))) {
        #ifdef DEBUG
            qDebug() << tr("Func GetChildDescription is Aborted with invalid ChildIndex");
        #endif
        return tr("Error");
    }
    return DataPasswords[RootIndex].Items[Index].Description;
}

// Set password to child item
void QPasswordKeeper::SetChildPassword(int RootIndex, int Index, QString APassword)
{    
    if ((RootIndex < 0) || (RootIndex > RootCountItems())) {
        #ifdef DEBUG
            qDebug() << tr("Func SetChildPassword is Aborted with invalid RootIndex");
        #endif
        return ;
    }
    if ((Index < 0) || (Index > ChildCountItems(RootIndex))) {
        #ifdef DEBUG
            qDebug() << tr("Func SetChildPassword is Aborted with invalid ChildIndex");
        #endif
        return ;
    }
    DataPasswords[RootIndex].Items[Index].Password = APassword;
}

// Set descrption to child item
void QPasswordKeeper::SetChildDescription(int RootIndex, int Index, QString ADescription)
{    
    if ((RootIndex < 0) || (RootIndex > RootCountItems())) {
        #ifdef DEBUG
            qDebug() << tr("Func SetChildDescription is Aborted with invalid RootIndex");
        #endif
        return ;
    }
    if ((Index < 0) || (Index > ChildCountItems(RootIndex))) {
        #ifdef DEBUG
            qDebug() << tr("Func SetChildDescription is Aborted with invalid ChildIndex");
        #endif
        return ;
    }
    DataPasswords[RootIndex].Items[Index].Description = ADescription;
}

void QPasswordKeeper::UpdateTreeVidget(QTreeWidget *TreeWidget)
{
    TreeWidget->clear();

    for (int i = 0; i <= RootCountItems(); ++i) {

        QTreeWidgetItem *root = new QTreeWidgetItem(TreeWidget);
        root->setText(0, GetRoot(i));
        root->setData(0, Qt::UserRole, QVariant(i));

        int ChildCount = ChildCountItems(i);

        #ifdef DEBUG
            qDebug() << QString("ChildCountItems = ") + QString::number(ChildCount);
        #endif

        for (int j = 0; j <= ChildCount; ++j) {

            QTreeWidgetItem *item = new QTreeWidgetItem(root);

            #ifdef DEBUG
                qDebug() << QString("j = ") + QString::number(j, 10);
                qDebug() << QString("ChildCountItems = ") + QString::number(ChildCountItems(i));
                qDebug() << QString("Child descript: ")+GetChildDescription(i, j);
            #endif

            item->setData(0, Qt::UserRole, QVariant(j));
            item->setText(0, GetChildDescription(i, j));
        }

    }
    TreeWidget->expandAll();
}

void QPasswordKeeper::Clear()
{
    DataPasswords.clear();
}

void QPasswordKeeper::ClearRoot(int RootIndex)
{
    if ((RootIndex < 0) || (RootIndex > RootCountItems())) {
        #ifdef DEBUG
            qDebug() << tr("Func ClearRoot is Aborted with invalid RootIndex");
        #endif
        return ;
    }
    DataPasswords[RootIndex].Items.clear();
}

void QPasswordKeeper::itemActivated(QTreeWidgetItem *item, int column)
{
    #ifdef DEBUG2
        qDebug() << tr("Activated");
        qDebug() << tr("Child count: ") << item->childCount();
    #endif

    int RootId = QVariant(item->data(0, Qt::UserRole)).toInt();
    if (GetRoot(RootId) == item->text(0)) {
        exit(0);
    }
    if ((item->childCount() == 0) && (column == 0)) {
        RootId = QVariant(item->parent()->data(0, Qt::UserRole)).toInt();
        int ItemId = QVariant(item->data(0, Qt::UserRole)).toInt();
        #ifdef DEBUG2
            QMessageBox::information(0, tr("Pass"), GetChildPassword(RootId, ItemId), QMessageBox::Ok);
            qDebug() << GetChildPassword(RootId, ItemId);
        #endif
        // Отправляем сигнал
        emit SelectPassword(GetChildDescription(RootId, ItemId), GetChildPassword(RootId, ItemId));
    }
}

void QPasswordKeeper::SaveToFile(QString FileName)
{
    QFile file(FileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << ("Not open ") << FileName;
        return ;
    }
    QDataStream out(&file);
    out << DataPasswords.count();
    for (int i = 0; i < DataPasswords.count(); ++i)
    {
        out << DataPasswords[i].ID;
        out << DataPasswords[i].Name;
        out << DataPasswords[i].Items.count();
        for (int j = 0; j < DataPasswords[i].Items.count(); ++j)
        {
            out << DataPasswords[i].Items[j].ID;
            out << DataPasswords[i].Items[j].Description;
            out << DataPasswords[i].Items[j].Password;
//******************************************************************************//
//                                                                              //
// Тут надо бы, шифровать пароль, ну или целиком файл                           //
//                                                                              //
//******************************************************************************//
        }
    }
    file.close();
    FilePath = FileName;
}

void QPasswordKeeper::SaveToFile()
{
    if (FilePath.isEmpty()) {
        SaveToFile(FilePath);
    }
}

void QPasswordKeeper::LoadFromFile(QString FileName)
{
    Clear();
    QFile file(FileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << ("Not open ") << FileName;
        return ;
    }
    QDataStream in(&file);
    Root hRoot;
    Node hNode;
    int FileRootCount;
    int FileChildCount;
    in >> FileRootCount;
    for (int i = 0; i < FileRootCount; ++i)
    {
        in >> hRoot.ID;
        in >> hRoot.Name;
        in >> FileChildCount;
        NewRoot(hRoot.Name);
        for (int j = 0; j < FileChildCount; ++j)
        {

//******************************************************************************//
//                                                                              //
// Тут надо бы, по идеи расшифровать пароль, ну или целиком файл                //
//                                                                              //
//******************************************************************************//
            in >> hNode.ID;
            in >> hNode.Description;
            in >> hNode.Password;
            NewChild(hRoot.ID, hNode.Password, hNode.Description);
        }
//        QMessageBox::information(0, QString::fromUtf8("Тест класса"), hRoot.Name, QMessageBox::Ok | QMessageBox::Cancel);
    }
    file.close();
    FilePath = FileName;
}

// Test
void QPasswordKeeper::Test()
{
    int MessageResult = QMessageBox::information(0, QString::fromUtf8("Тест класса"),
                QString::fromUtf8("Данный метод выполнит стандартные функции класса в целях отладки."),
                             QMessageBox::Ok | QMessageBox::Cancel);
    if (MessageResult == QMessageBox::Cancel) {
        return;
    }

    #ifdef DEBUG
        qDebug() << QString("\n\n\n+++++++++++++++++++++++++++++++++++++++++++++++++");
        qDebug() << QString("Root count: ")+QString::number(RootCountItems());
        qDebug() << QString("\n");
    #endif

    int RootID = NewRoot(QString("Test Root Item"));

    #ifdef DEBUG
        qDebug() << QString("Root count: ")+QString::number(RootCountItems());
        qDebug() << QString("Child count: ")+QString::number(ChildCountItems(RootID));
        qDebug() << QString("\n");
    #endif
    #ifdef DEBUG
        int ChildID =
    #endif
            NewChild(RootID, QString("qwerty"), QString("Test Password"));
    #ifdef DEBUG
        qDebug() << QString("Child count: ")+QString::number(ChildCountItems(RootID));
        qDebug() << QString("Root descript: ")+GetRoot(RootID);
        qDebug() << QString("Child descript: ")+GetChildDescription(RootID, ChildID);
        qDebug() << QString("\n");
    #endif
    #ifdef DEBUG
        ChildID =
    #endif
            NewChild(RootID, QString("12345"), QString("Test Password 2"));
    #ifdef DEBUG
        qDebug() << QString("Child count: ")+QString::number(ChildCountItems(RootID));
        qDebug() << QString("Root descript: ")+GetRoot(RootID);
        qDebug() << QString("Child descript: ")+GetChildDescription(RootID, ChildID);
        qDebug() << QString("\n");
        qDebug() << QString("\n\n\n+++++++++++++++++++++++++++++++++++++++++++++++++");
    #endif

    RootID = NewRoot(QString("Test Root Item 2"));
    #ifdef DEBUG
        qDebug() << QString("Root count: ")+QString::number(RootCountItems());
        qDebug() << QString("Child count: ")+QString::number(ChildCountItems(RootID));
    #endif

    #ifdef DEBUG
        ChildID =
    #endif
            NewChild(RootID, QString("abcdefgh"), QString("Test Password 3"));
    #ifdef DEBUG
        qDebug() << QString("Child count: ")+QString::number(ChildCountItems(RootID));
        qDebug() << QString("Root descript: ")+GetRoot(RootID);
        qDebug() << QString("Child descript: ")+GetChildDescription(RootID, ChildID);
        qDebug() << QString("\n\n\n+++++++++++++++++++++++++++++++++++++++++++++++++");
    #endif
        SaveToFile(QString("/home/anton/passwd.dat"));
        LoadFromFile(QString("/home/anton/passwd.dat"));
}
