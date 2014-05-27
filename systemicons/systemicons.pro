TEMPLATE = app
TARGET = systemicons

SOURCES += \
    main.cpp \
    dialog.cpp \
    systemicons.cpp

HEADERS += \
    dialog.h \
    systemicons.h

FORMS += \
    dialog.ui

RESOURCES += \
    systemicons.qrc

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII

win32 {
    LIBS += -lShell32
    HEADERS += systemicons_win_p.h
    SOURCES += systemicons_win.cpp
}

mac {
    QT += macextras
    LIBS += -framework AppKit
    HEADERS += systemicons_mac_p.h
    OBJECTIVE_SOURCES += systemicons_mac.mm
}
