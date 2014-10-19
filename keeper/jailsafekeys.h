#ifndef QJAILSAFEKEYS_H
#define QJAILSAFEKEYS_H

#include <stdio.h>
#include <stdlib.h>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QMessageBox>
#include <openssl/blowfish.h>
#include <QDebug>
#include "_warning.h"

//******************************************************************************
    #pragma message WARN("Херовый класс, надо бы его переписать")
//******************************************************************************

#define BUFSIZE 1024
#define KEY_SIZE 16

class QJailSafeKeys : public QObject
{
    Q_OBJECT

private:
    int  ReadFile(QString FileName, char *Buffer, int SizeToRead); // return readed bytes

    void Encrypt(const unsigned char *FromBuf, long FromBufLen,
                 unsigned char *ToBuf, char *Key);
    void Decrypt(const unsigned char *FromBuf, long FromBufLen,
                 unsigned char *ToBuf, char *Key);

public:
    explicit QJailSafeKeys(QObject *parent = 0);

    void LoadFromFile(QString FileName, QString Key);
    void SaveToFile(QString FileName, QString Key);

    void Test();

signals:
    void ReadRootItem(int RootIndex, QString Description);
    void ReadChildItem(int RootIndex, int ChildIndex, QString Password, QString Description);

public slots:
    void WriteRootItem(int RootIndex, QString Description);
    void WriteChildItem(int RootIndex, int ChildIndex, QString Password, QString Description);

};


#endif // QJAILSAFEKEYS_H


