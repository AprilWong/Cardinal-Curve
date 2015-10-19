#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T01:31:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardinalCurve
TEMPLATE = app


SOURCES += main.cpp\
        canvas.cpp \
    input.cpp \
    cspline.cpp \
    car.cpp

HEADERS  += canvas.h \
    input.h \
    cspline.h \
    car.h

FORMS    += canvas.ui
