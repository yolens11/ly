QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dockview/dockwidget.cpp \
    dockview/dockwidget2.cpp \
    dockview/dockwidget3.cpp \
    dragview/dragbutton.cpp \
    dragview/dragview.cpp \
    dragview/mymodel.cpp \
    flowview/flowlayout.cpp \
    flowview/flowwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    splitterview/splitterwidget.cpp \
    treeview/treeitem.cpp \
    treeview/treemodel.cpp \
    treeview/treewidget.cpp

HEADERS += \
    dockview/dockwidget.h \
    dockview/dockwidget2.h \
    dockview/dockwidget3.h \
    dragview/dragbutton.h \
    dragview/dragview.h \
    dragview/mymodel.h \
    flowview/flowlayout.h \
    flowview/flowwidget.h \
    mainwindow.h \
    splitterview/splitterwidget.h \
    treeview/treeitem.h \
    treeview/treemodel.h \
    treeview/treewidget.h

FORMS += \
    dockview/dockwidget.ui \
    dockview/dockwidget2.ui \
    dockview/dockwidget3.ui \
    dragview/dragview.ui \
    flowview/flowwidget.ui \
    mainwindow.ui \
    splitterview/splitterwidget.ui \
    treeview/treewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
