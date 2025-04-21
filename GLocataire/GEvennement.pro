QT       += core gui sql printsupport charts network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GEvennement
TEMPLATE = app

CONFIG += c++17

SOURCES += \
    arduino.cpp \
    connection.cpp \
    glocataires.cpp \
    locataires.cpp \
    main.cpp

HEADERS += \
    arduino.h \
    connection.h \
    glocataires.h \
    locataires.h

FORMS += \
    glocataires.ui

# Vérification de QtSerialPort (retirer la ligne LIBS si la version Qt5 gère cela automatiquement)
#LIBS += -lQt5SerialPort
