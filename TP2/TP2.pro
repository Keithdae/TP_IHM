#-------------------------------------------------
#
# Project created by QtCreator 2016-01-19T12:32:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawarea.cpp \
    shape.cpp

HEADERS  += mainwindow.h \
    drawarea.h \
    shape.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons/images/images.qrc
