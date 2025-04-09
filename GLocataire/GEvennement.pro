QT       += core gui sql printsupport charts network \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Add QXlsx source path (sources) using relative paths
SOURCES += \
    connection.cpp \
    glocataires.cpp \
    locataires.cpp \
    main.cpp

# Add the header files using relative paths
HEADERS += \
    connection.h \
    glocataires.h \
    locataires.h

FORMS += \
    glocataires.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
