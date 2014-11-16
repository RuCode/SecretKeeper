#include "qconfig.h"

QConfig::QConfig(QObject *parent) :
    QObject(parent)
{
    QString fileName = QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation);
    fileName += '/';//QDir::separator();
    fileName += CONF_NAME;
    settings.setUserIniPath(fileName);
    settings.setPath(QSettings::IniFormat, QSettings::UserScope, fileName);
    #ifdef DBG_OUT
        qDebug() << fileName;
    #endif
}

void QConfig::setJailPath(QString filePath)
{
    QSettings settings("Secret", "Keeper");
    #ifdef DBG_OUT
        qDebug() << "setJailPath(" << filePath << ')';
    #endif
    settings.beginGroup(tr("jail"));
    settings.setValue("path", filePath);
    settings.sync();
    #ifdef DBG_OUT
        qDebug() << "JailPath " << settings.value("path", QVariant(tr(""))).toString();
    #endif
    settings.endGroup();
}

QString QConfig::JailPath()
{
    QSettings settings("Secret", "Keeper");
    settings.beginGroup(tr("jail"));
    #ifdef DBG_OUT
        qDebug() << "JailPath " << settings.value("path", QVariant(tr(""))).toString();
    #endif
    QString path;
    path = settings.value("path", QVariant(tr(""))).toString();
    settings.endGroup();
    return path;
}
