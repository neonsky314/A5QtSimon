QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gameloop.cpp \
    globals.cpp \
    main.cpp \
    interface.cpp \
    mytimer.cpp \
    redraw.cpp

HEADERS += \
    gameloop.h \
    globals.h \
    interface.h \
    mytimer.h \
    redraw.h

FORMS += \
    interface.ui

TRANSLATIONS += \
    A5QtSimon_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    high_score
