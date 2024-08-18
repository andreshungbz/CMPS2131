# Template Project File for qmake
# contains normalization configurations for build directories
# using qmake with QT Creator and cmake with JetBrains CLion IDEs

# project specification (app for executable)
TEMPLATE = app

# set the name of the output executable
TARGET = output

# C++ standard
CONFIG += c++20

# configure for cmdline and console (Windows)
CONFIG += cmdline console

# add include directory in project root for created header files
INCLUDEPATH += include

# sources (in src directory) and headers in (include directory)

SOURCES += src/main.cpp \

HEADERS += include/Example.h \

# configure build folders for Unix/Linux 
unix {
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/qmake-build-debug
    }

    CONFIG(release, debug|release) {
        DESTDIR = $$PWD/qmake-build-release
    }

    OBJECTS_DIR = $$DESTDIR/
    MOC_DIR = $$DESTDIR/
    RCC_DIR = $$DESTDIR/
    UI_DIR = $$DESTDIR/
}

# configure build folders for Windows
win32 {
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD\\qmake-build-debug
    }

    CONFIG(release, debug|release) {
        DESTDIR = $$PWD\\qmake-build-release
    }

    OBJECTS_DIR = $$DESTDIR\\
    MOC_DIR = $$DESTDIR\\
    RCC_DIR = $$DESTDIR\\
    UI_DIR = $$DESTDIR\\
}
