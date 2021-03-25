#-------------------------------------------------
#
# Project created by QtCreator 2020-04-22T15:52:53
#
#-------------------------------------------------

QT += core gui
QT += xml

QT += widgets

TARGET = InfoPoint
TEMPLATE = app
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Models/discobar.cpp \
    Models/pasticceria.cpp \
        main.cpp \
    Controllers/controller.cpp \
    Models/ristoranti.cpp \
    Models/discoteca.cpp \
    Models/locale.cpp \
    Models/model.cpp \
    Models/bar.cpp \
    Models/fileexception.cpp \
    Views/mainMenu.cpp \
    Views/layoutview.cpp \
    Views/layoutviewitem.cpp \
    Views/localelistwidget.cpp \
    Views/localeitems.cpp \
    Views/insertlayout.cpp \
    Views/combtipolocale.cpp \
    Views/searchlayout.cpp







HEADERS += \
    Controllers/controller.h \
    Models/container.h \
    Models/discobar.h \
    Models/pasticceria.h \
    Models/ristoranti.h \
    Models/discoteca.h \
    Models/locale.h \
    Models/model.h \
    Models/bar.h \
    Models/fileexception.h \
    Views/mainMenu.h \
    Views/layoutview.h \
    Views/layoutviewitem.h \
    Views/localelistwidget.h \
    Views/localeitems.h \
    Views/insertlayout.h \
    Views/combtipolocale.h \
    Views/searchlayout.h

DISTFILES += \
    dati.xml






