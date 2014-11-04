#include "_application.h"

QString sysGeneratePassword()
{
    int MAX_PASS_LEN = 14;
    QByteArray table;
    table.append("1234567890!@#$%^&*()_+-qwertyuiop[]\asdfghjkl;'zxcvbnm,./QWE"
                 "RTYUIOP{}|ASDFGHJKL:ZXCVBNM<>?");
    QString password;
    int rand_pos = 0;

    for (int i = 1; i < MAX_PASS_LEN; ++i)
    {
        rand_pos = rand() % table.count();
        password.append(table.at(rand_pos));
    }
    return password;
}

QString sysGeneratePhrase()
{
    int MAX_PASS_LEN = 8;
    QByteArray table;
    table.append("1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
    QString password;
    int rand_pos = 0;

    for (int i = 1; i < MAX_PASS_LEN; ++i)
    {
        rand_pos = rand() % table.count();
        password.append(table.at(rand_pos));
    }
    return password;
}
