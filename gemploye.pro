# Qt Modules
QT       += core gui sql printsupport network  charts widgets serialport




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
    connection.cpp \
    employee.cpp \
    gemploye.cpp \
    main.cpp

# Header Files
HEADERS += \
    arduino.h \
    authentification.h \
    connection.h \
    employee.h \
    gemploye.h

# UI Files
FORMS += \
    gemploye.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
