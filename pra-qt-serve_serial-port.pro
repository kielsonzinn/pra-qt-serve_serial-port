QT -= gui
QT += serialport

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = build

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u

SOURCES += \
    main.cpp
