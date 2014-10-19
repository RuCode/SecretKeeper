#ifndef QPASSWORDKEEPER_H
#define QPASSWORDKEEPER_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QTreeWidget>
#include <QFile>
#include <QTextStream>

#include "_warning.h"

class QPasswordKeeper : public QObject
{
    Q_OBJECT
private:

    struct Node
    {
        int ID;
        QString Password;
        QString Description;
    };

    struct Root
    {
        int ID;
        QString Name;
        QVector<Node> Items;
    };

    QVector<Root> DataPasswords;
    QString LastFilePath;
    int RootCountItems();
    int ChildCountItems(int RootIndex);

public:
    QString Password;
    explicit QPasswordKeeper(QObject *parent = 0);

    void    Clear();
    void    ClearRoot(int RootIndex);

    int     NewRoot(QString AName); // New Root Item
    void    FreeRoot(int Index);    // Remove Root Item

    QString GetRoot(int Index);  // Get root description
    void    SetRoot(int Index, QString AName); // Set Root Description

    int     NewChild(int RootIndex, QString APassword, QString ADescription);
    void    FreeChild(int RootIndex, int Index);

    QString GetChildPassword(int RootIndex, int Index);
    QString GetChildDescription(int RootIndex, int Index);
    void    SetChildPassword(int RootIndex, int Index, QString APassword);
    void    SetChildDescription(int RootIndex, int Index, QString ADescription);

    void    Test(); // Test code in methods

public:
    void    SaveToFile();
    void    SaveToFile(QString FileName);
    void    LoadFromFile(QString FileName);
    void    UpdateTreeVidget(QTreeWidget *TreeWidget); // Communication to controls

signals:
    void    SelectPassword(QString Description, QString Password);

public slots:
    void    itemActivated(QTreeWidgetItem *item, int column);

};

#endif // QPASSWORDKEEPER_H
