#-------------------------------------------------
#
# Project created by QtCreator 2017-09-30T13:39:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A1Server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../A1/client.cpp \
    ../A1/server.cpp \
    ../A1/socketwrappers.cpp

HEADERS  += mainwindow.h \
    ../A1/client.h \
    ../A1/server.h \
    ../A1/socketwrappers.h

FORMS    += mainwindow.ui
