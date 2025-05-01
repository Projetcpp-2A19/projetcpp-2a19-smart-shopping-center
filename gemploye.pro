# Qt Modules
QT       += core gui sql printsupport network  charts widgets serialport quickwidgets location positioning




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# C++17 Configuration
CONFIG += c++17

# Project Target and Template
TARGET = Projet
TEMPLATE = app

# Defines
DEFINES += QT_DEPRECATED_WARNINGS


# Sources Files
SOURCES += \
    arduino.cpp \
    authentification.cpp \
    calendardialog.cpp \
    connection.cpp \
    employee.cpp \
    evennement.cpp \
    gemploye.cpp \
    gevennement.cpp \
    glocataires.cpp \
    locataires.cpp \
    main.cpp

# Header Files
HEADERS += \
    arduino.h \
    authentification.h \
    calendardialog.h \
    connection.h \
    employee.h \
    evennement.h \
    gemploye.h \
    gevennement.h \
    glocataires.h \
    locataires.h

# UI Files
FORMS += \
    gemploye.ui \
    gevennement.ui \
    glocataires.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc

DISTFILES +=
