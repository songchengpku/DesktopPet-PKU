QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mainwindowclose.cpp \
    timetable.cpp \
    timetable_add.cpp \
    timetable_delete.cpp \
    timetableclear.cpp \
    timetableclose.cpp \
    timetableremind.cpp \
    timetablesave.cpp

HEADERS += \
    mainwindow.h \
    mainwindowclose.h \
    timetable.h \
    timetable_add.h \
    timetable_delete.h \
    timetableclear.h \
    timetableclose.h \
    timetableremind.h \
    timetablesave.h

FORMS += \
    mainwindow.ui \
    mainwindowclose.ui \
    timetable.ui \
    timetable_add.ui \
    timetable_delete.ui \
    timetableclear.ui \
    timetableclose.ui \
    timetableremind.ui \
    timetablesave.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
