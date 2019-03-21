#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T06:44:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pictureprocess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    processfuntion.cpp

HEADERS  += mainwindow.h \
    pictureprcess.h

FORMS    += mainwindow.ui
INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so
