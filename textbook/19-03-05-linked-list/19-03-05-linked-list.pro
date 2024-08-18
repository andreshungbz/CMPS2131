TEMPLATE = app
TARGET = 19_03_05_linked_list

CONFIG += c++20 cmdline console

INCLUDEPATH += include

SOURCES += src/main.cpp \

HEADERS += include/List.h \
           include/ListNode.h

# Unix/Linux build folders
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

# Windows build folders
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
