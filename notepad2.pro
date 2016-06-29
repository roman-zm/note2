#-------------------------------------------------
#
# Project created by QtCreator 2016-06-22T13:49:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = notepad2
TEMPLATE = app

#QMAKE_LFLAGS_RELEASE += -static -static-libgcc


SOURCES += main.cpp\
        notepad.cpp \
    aboutwidget.cpp \
    findwidget.cpp

HEADERS  += notepad.h \
    aboutwidget.h \
    findwidget.h

FORMS    += notepad.ui \
    aboutwidget.ui \
    findwidget.ui
