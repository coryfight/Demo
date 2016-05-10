#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T10:00:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -LC:\mysql\mysql-5.6.15-win32\lib -llibmysql
#LIBS += -lmysqlclient
TARGET = cdma
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    scripdlg.cpp \
    mymysql.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    scripdlg.h \
    mymysql.h
