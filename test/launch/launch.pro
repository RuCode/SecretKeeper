#-------------------------------------------------
#
# Project created by QtCreator 2014-09-15T12:01:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = launch
TEMPLATE = app

LIBS += -lssl -lcrypto

SOURCES += main.cpp\
        mainwindow.cpp \
    qpasswordkeeper.cpp \
    qjailsafekeys.cpp \
    dialoginputroot.cpp \
    dialogcreatejail.cpp

HEADERS  += mainwindow.h \
    qpasswordkeeper.h \
    qjailsafekeys.h \
    dialoginputroot.h \
    dialogcreatejail.h \
    _warning.h

FORMS    += mainwindow.ui \
    dialoginputroot.ui \
    dialogcreatejail.ui
