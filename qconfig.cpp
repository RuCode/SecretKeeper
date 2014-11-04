#include "qconfig.h"

QConfig::QConfig(QObject *parent) :
    QObject(parent)
{
    QString fileName = QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation);
    fileName += QDir::separator();
    fileName += CONF_NAME;
    settings.setPath(QSettings::IniFormat, QSettings::UserScope, fileName);
}

void QConfig::setJailPath(QString filePath)
{
    settings.setValue("jail/path", filePath);
    settings.sync();
}

QString QConfig::JailPath()
{
    return settings.value("jail/path", QVariant(tr(""))).toString();
}
