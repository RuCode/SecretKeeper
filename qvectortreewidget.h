#ifndef QVECTORTREEWIDGET_H
#define QVECTORTREEWIDGET_H

#define INCREMENT_VALUE 1
#define INVALID_VALUE -1
#define COUNT_COLUMNS_4
#define COLUMN_TEXT 0
#define COLUMN_ROOT 1
#define COLUMN_CHILD 2
#define COLUMN_PASSWORD 3

#include <QFile>
#include <QTreeWidget>
#include <QDebug>

#include "_warning.h"
#include "cryptfiledevice.h"

class QVectorTreeWidget : public QTreeWidget
{
    Q_OBJECT

private:
    struct Node
    {
        int id;
        QString password;
        QString description;
        QTreeWidgetItem *item;
    };

    struct Root
    {
        int id;
        QString name;
        QVector<Node> items;
        QTreeWidgetItem *item;
    };

    struct LastSel
    {
        int root;
        int child;
    };

    QVector<Root> dataPasswords;    
    LastSel lastSel;

    QString lastFilePath;
    QString password;
    void updateLinks();
    bool rangeCheck(int rootIndex, int childIndex = INVALID_VALUE);

public:
    explicit QVectorTreeWidget(QWidget *parent = 0);
    ~QVectorTreeWidget();

    void ClearAll();

    int RootCountItems();
    int ChildCountItems(int rootIndex);

    int NewRoot(const QString text);
    int NewChild(int rootId, const QString text, QString data);
    int NewChild(const QString text, QString data);
    void UpdateRoot(int rootId, const QString text);
    void UpdateChild(int rootId, int childId, const QString text, QString data);
    void UpdateRoot(const QString text);
    void UpdateChild(const QString text, QString data);
    bool Delete();
    void Delete(int rootId);
    void Delete(int rootId, int childId);

    void SaveSelect(QTreeWidgetItem *item);
    void SetPassword(const QString pass);
    void SaveToFile(const QString fileName);
    void SaveToFile();
    bool LoadFromFile(const QString fileName);

    void CloseAll();

signals:

public slots:

};

#endif // QVECTORTREEWIDGET_H
