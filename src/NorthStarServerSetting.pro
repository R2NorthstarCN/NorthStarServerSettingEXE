QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutns.cpp \
    argsconfig.cpp \
    argsdediconfig.cpp \
    argsdedieditor.cpp \
    argseditor.cpp \
    cfgeditor.cpp \
    main.cpp \
    mainwindow.cpp \
    serverconfig.cpp

HEADERS += \
    aboutns.h \
    argsconfig.h \
    argsdediconfig.h \
    argsdedieditor.h \
    argseditor.h \
    cfgeditor.h \
    define.h \
    mainwindow.h \
    serverconfig.h

FORMS += \
    aboutns.ui \
    argsdedieditor.ui \
    argseditor.ui \
    cfgeditor.ui \
    mainwindow.ui



msvc {
        QMAKE_CFLAGS += /utf-8
        QMAKE_CXXFLAGS += /utf-8
}



RC_FILE += ver.rc
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    ver.rc

RC_ICONS = "NS.ico"
