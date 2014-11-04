#-------------------------------------------------
#
# Project created by QtCreator 2014-11-02T18:29:16
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

#openssl
win32 {
    INCLUDEPATH += c:/OpenSSL-Win32/include
    LIBS += -Lc:/OpenSSL-Win32/bin -llibeay32
}
linux|macx {
    LIBS += -lcrypto
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SecretKeeper
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    qvectortreewidget.cpp \
    cryptfiledevice.cpp \
    qcreatejailbox.cpp \
    _application.cpp \
    qcreatechilditembox.cpp \
    qcreaterootitembox.cpp \
    qpassworddialog.cpp \
    qconfig.cpp \
    qinputdialog.cpp

HEADERS  += mainwindow.h \
    qvectortreewidget.h \
    _warning.h \
    cryptfiledevice.h \
    qcreatejailbox.h \
    _application.h \
    qcreatechilditembox.h \
    qcreaterootitembox.h \
    qpassworddialog.h \
    qconfig.h \
    qinputdialog.h

FORMS    += mainwindow.ui \
    qcreatejailbox.ui \
    qcreatechilditembox.ui \
    qcreaterootitembox.ui \
    qpassworddialog.ui \
    qinputdialog.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    LICENSE \
    README.md
