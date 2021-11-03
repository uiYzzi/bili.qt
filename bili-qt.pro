#-------------------------------------------------
#
# Project created by QtCreator 2021-10-29T16:58:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bili-qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
        mainwindow-dtk.cpp \
    src/pages/recommendpage.cpp \
    src/widgets/common/videoitem.cpp \
    src/backend/utils/httprequest.cpp \
    src/backend/bili-api/appapi.cpp \
    src/widgets/common/smoothscrollbar.cpp \
    src/widgets/common/smoothscrollarea.cpp \
    src/widgets/common/smoothlistwidget.cpp \
    src/pages/popularpage.cpp \
    src/pages/searchpage.cpp \
    src/widgets/avantartooltip.cpp \
    src/dialogs/logindialog.cpp

HEADERS += \
        mainwindow-dtk.h \
    src/pages/recommendpage.h \
    src/widgets/common/videoitem.h \
    src/backend/utils/httprequest.h \
    src/backend/bili-api/appapi.h \
    src/widgets/common/smoothscrollbar.h \
    src/widgets/common/smoothscrollarea.h \
    src/widgets/common/smoothlistwidget.h \
    src/pages/popularpage.h \
    src/pages/searchpage.h \
    src/widgets/avantartooltip.h \
    src/dialogs/logindialog.h

FORMS += \
        mainwindow-dtk.ui \
    src/pages/recommendpage.ui \
    src/widgets/common/videoitem.ui \
    src/pages/popularpage.ui \
    src/pages/searchpage.ui \
    src/widgets/avantartooltip.ui \
    src/dialogs/logindialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets/assets.qrc
