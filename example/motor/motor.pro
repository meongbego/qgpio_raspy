#-------------------------------------------------
#
# Project created by QtCreator 2014-08-07T03:59:33
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = motor
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    motortest.cpp \
    ../../libgpiojs.cpp

HEADERS += \
    motortest.h \
    ../../libgpiojs.h \
    motortest.h
