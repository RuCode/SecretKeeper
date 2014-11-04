#ifndef _APPLICATION_H
#define _APPLICATION_H

#pragma once

#include <QString>
#include <QByteArray>

#define INVALID_INDEX -1

enum eResultBox
{
   rbOk,
   rbCancel,
   rbError
};

QString sysGeneratePassword();
QString sysGeneratePhrase();

#endif // _APPLICATION_H
