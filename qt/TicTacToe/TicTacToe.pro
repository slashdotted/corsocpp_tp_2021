#-------------------------------------------------
#
# Project created by QtCreator 2015-06-15T08:36:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    msgdialog.cpp

HEADERS  += mainwindow.h \
    msgdialog.h

FORMS    += mainwindow.ui \
    msgdialog.ui

RESOURCES += \
    risorse.qrc
