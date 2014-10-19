#include "qjailsafekeys.h"

QJailSafeKeys::QJailSafeKeys(QObject *parent) :
    QObject(parent)
{
}

int QJailSafeKeys::ReadFile(QString FileName, char *Buffer, int SizeToRead)
{
    FILE *hFile;
    hFile = fopen(FileName.toAscii(), "r");
    if (hFile == NULL) {
        QMessageBox::warning(0, tr("Error"), tr("Ошибка открытия для чтения"), QMessageBox::Ok);
        return 0;
    }
    int ReadedBytes = 0;
    for (;;) {
        int flen = fread(Buffer, 1, SizeToRead, hFile);
        if (flen <= 0)
            break;
        ReadedBytes+= flen;
    }
    fclose(hFile);
    return ReadedBytes;
}

void QJailSafeKeys::LoadFromFile(QString FileName, QString Key)
{

}

void QJailSafeKeys::Encrypt(const unsigned char *FromBuf, long FromBufLen,
                            unsigned char *ToBuf, char *Key)
{
    memset(ToBuf, 0, FromBufLen);

    BF_KEY BfKey;
    BF_set_key(&BfKey, strlen(Key), reinterpret_cast<unsigned char*>(Key));
    int num = 0;
    unsigned char iv[8];
    BF_cfb64_encrypt(FromBuf, ToBuf, FromBufLen, &BfKey, iv, &num, BF_ENCRYPT);
}

void QJailSafeKeys::Decrypt(const unsigned char *FromBuf, long FromBufLen,
                            unsigned char *ToBuf, char *Key)
{
    memset(ToBuf, 0, FromBufLen);

    BF_KEY BfKey;
    BF_set_key(&BfKey, strlen(Key), reinterpret_cast<unsigned char*>(Key));
    int num = 0;
    unsigned char iv[8];
    BF_cfb64_encrypt(FromBuf, ToBuf, FromBufLen, &BfKey, iv, &num, BF_DECRYPT);
}

void QJailSafeKeys::SaveToFile(QString FileName, QString Key)
{

}

void QJailSafeKeys::WriteRootItem(int RootIndex, QString Description)
{
    QMessageBox::warning(0, QString("Info"), QString("Add Root #%1").arg(RootIndex),
                         QMessageBox::Ok);
}

void QJailSafeKeys::WriteChildItem(int RootIndex, int ChildIndex, QString Password, QString Description)
{

}

void QJailSafeKeys::Test()
{
    QString FileName('/home/anton/test.txt');
    QString Key("qwerty");
    // Test - read from file
    if (!QFile::exists(FileName)) {
        QMessageBox::warning(0, tr("Error"), tr("Файла не существует"), QMessageBox::Ok);
        return;
    }
    char inbuf[BUFSIZE];
    int ReadBytes = ReadFile(FileName, inbuf, BUFSIZE);
    inbuf[ReadBytes] = 0;
    qDebug() << ReadBytes;
    QMessageBox::warning(0, tr("Info"), tr(inbuf)+"\nKey:\n"+Key, QMessageBox::Ok);

    // Test - Encrypt and Decrypt

    unsigned char ukey[16] = "1234567890!@#$%";
    unsigned char DefBuf[BUFSIZE] = "12345678Hello World! ALALALLALALALAL Привет Kak dela?";
    unsigned char CryptBuf[BUFSIZE];
    unsigned char OutBuf[BUFSIZE];

    Encrypt(reinterpret_cast<unsigned char*>(DefBuf), sizeof(DefBuf), CryptBuf,
            reinterpret_cast<char*>(ukey));

    Decrypt(reinterpret_cast<unsigned char*>(CryptBuf), sizeof(CryptBuf), OutBuf,
            reinterpret_cast<char*>(ukey));

    QMessageBox::warning(0, tr("Info"), tr(reinterpret_cast<char*>(OutBuf+8)), QMessageBox::Ok);
}

