#ifndef QCONFIG_H
#define QCONFIG_H

#define CONF_NAME "config.jail"

#include <QDir>
#include <QDebug>
#include <QObject>
#include <QSettings>
#include <QMessageBox>
#include <QStandardPaths>

class QConfig : public QObject
{
    Q_OBJECT
public:
    explicit QConfig(QObject *parent = 0);
    void setJailPath(QString filePath);
    QString JailPath();

private:
    QSettings settings;

signals:

public slots:

};

#endif // QCONFIG_H
