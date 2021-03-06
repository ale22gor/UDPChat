#-------------------------------------------------
#
# Project created by QtCreator 2019-09-21T14:59:04
#
#-------------------------------------------------

QT       -= gui
QT       +=core network


TEMPLATE = lib

DEFINES += MODEL_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        clientlistmodel.cpp \
        messagesmodel.cpp \
        model.cpp

HEADERS += \
        clientlistmodel.h \
        messagesmodel.h \
        model.h \
        model_global.h 


unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UDPBack/release/ -lUDPBack
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UDPBack/debug/ -lUDPBack
else:unix: LIBS += -L$$OUT_PWD/../UDPBack/ -lUDPBack

INCLUDEPATH += $$PWD/../UDPBack
DEPENDPATH += $$PWD/../UDPBack
