QT       += core gui widgets multimedia  quick qml charts network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = DesktopPet-PKU  # 替换成你想要的名字
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backend/Sport_Item.cpp \
    backend/deepseekservice.cpp \
    backend/qmarkdowntextdocument.cpp \
    frontend/chatdialog.cpp \
    main.cpp \
    frontend/mainwindow.cpp \
    frontend/mainwindowclose.cpp \
    frontend/timetable.cpp \
    frontend/timetableclear.cpp \
    frontend/timetableclose.cpp \
    frontend/timetableremind.cpp \
    frontend/timetablesave.cpp\
    frontend/records.cpp \
    frontend/schedule.cpp \
    frontend/sports.cpp \
    frontend/stats.cpp\
    frontend/clotheschanging.cpp\

HEADERS += \
    backend/Sport_Item.h \
    backend/deepseekservice.h \
    backend/qmarkdowntextdocument.h \
    frontend/chatdialog.h \
    frontend/mainwindow.h \
    frontend/mainwindowclose.h \
    frontend/timetable.h \
    frontend/timetableclear.h \
    frontend/timetableclose.h \
    frontend/timetableremind.h \
    frontend/timetablesave.h\
    frontend/records.h \
    frontend/schedule.h \
    frontend/sports.h \
    frontend/stats.h\
    frontend/clotheschanging.h \


FORMS += \
    frontend/chatdialog.ui \
    frontend/mainwindow.ui \
    frontend/mainwindowclose.ui \
    frontend/timetable.ui \
    frontend/timetableclear.ui \
    frontend/timetableclose.ui \
    frontend/timetableremind.ui \
    frontend/timetablesave.ui\
    frontend/records.ui \
    frontend/schedule.ui \
    frontend/sports.ui \
    frontend/stats.ui\
    frontend/clotheschanging.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
