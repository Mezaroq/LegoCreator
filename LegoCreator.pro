#-------------------------------------------------
#
# Project created by QtCreator 2019-10-15T20:10:33
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LegoCreator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#QMAKE_CXXFLAGS += -Wreturn-type

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    Model/CreatorMenu.cpp \
    Model/CreatorObject.cpp \
    Model/CreatorRail.cpp \
    View/CreatorScene.cpp \
    View/CreatorView.cpp \
    ViewModel/CreatorProvider.cpp \
    ViewModel/CreatorViewModel.cpp \
        main.cpp \
    View/MainWindow.cpp

HEADERS += \
    Model/CreatorMenu.h \
    Model/CreatorObject.h \
    Model/CreatorRail.h \
    View/CreatorScene.h \
    View/CreatorView.h \
    View/MainWindow.h \
    ViewModel/CreatorProvider.h \
    ViewModel/CreatorViewModel.h

FORMS += \
        View/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
