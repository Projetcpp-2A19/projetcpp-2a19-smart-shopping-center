# Qt Modules
QT       += core gui sql printsupport network

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
    authentification.cpp \
    connection.cpp \
    employee.cpp \
    main.cpp \
    gevennement.cpp

# Header Files
HEADERS += \
    authentification.h \
    connection.h \
    employee.h \
    gevennement.h

# UI Files
FORMS += \
    gevennement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
