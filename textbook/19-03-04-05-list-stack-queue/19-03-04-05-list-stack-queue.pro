TEMPLATE = app
TARGET = 19_03_04_05_list_stack_queue

CONFIG += c++20 cmdline console

INCLUDEPATH += include

SOURCES += src/queue-driver.cpp \

HEADERS += include/List.h \
           include/ListNode.h \
           include/Stack.h \
           include/Stackcomposition.h \
           include/Queue.h \

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
