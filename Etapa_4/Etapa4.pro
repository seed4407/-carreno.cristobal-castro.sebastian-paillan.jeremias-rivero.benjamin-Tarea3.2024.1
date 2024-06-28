QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    code/Comida.cpp \
    code/Estado.cpp \
    code/Inventario.cpp \
    code/Item.cpp \
    code/Juguete.cpp \
    code/Mascota.cpp \
    code/Medicina.cpp

HEADERS += \
    mainwindow.h \
    code/Comida.h \
    code/Item.h \
    code/Juguete.h \
    code/Mascota.h \
    code/Medicina.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img/images.qrc \
    img/chatbot_gato.png \
    code/config.csv
