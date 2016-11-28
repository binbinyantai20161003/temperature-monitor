#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T19:39:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = temperMonitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectdlg.cpp \
    channelconfig.cpp

HEADERS  += mainwindow.h \
    globaldef.h \
    connectdlg.h \
    channelconfig.h

FORMS    += mainwindow.ui \
    connectdlg.ui \
    channelconfig.ui

RC_ICONS +=AppIco.ico
