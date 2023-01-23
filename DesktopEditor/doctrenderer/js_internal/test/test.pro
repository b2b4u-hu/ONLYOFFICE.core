QT       -= core
QT       -= gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

#INCLUDEPATH = $$PWD/../..

TEMPLATE = app

CONFIG += core_static_link_libstd

CORE_ROOT_DIR = $$PWD/../../../../../core
PWD_ROOT_DIR = $$PWD

include($$CORE_ROOT_DIR/Common/base.pri)
include($$CORE_ROOT_DIR/DesktopEditor/doctrenderer/js_internal/js_base.pri)

############### destination path ###############
DESTDIR = $$PWD/build
################################################

# Use installation builder path, or set the own path.
core_windows {
    DOCUMENT_BUILDER_INSTALL_PATH="C:/Program Files/ONLYOFFICE/DocumentBuilder"
} else {
    DOCUMENT_BUILDER_INSTALL_PATH=/opt/onlyoffice/documentbuilder
}

LIBS += -L'$$DOCUMENT_BUILDER_INSTALL_PATH' -ldoctrenderer

core_linux {
    include($$CORE_ROOT_DIR/Common/3dParty/icu/icu.pri)
    LIBS += -L'$$DOCUMENT_BUILDER_INSTALL_PATH' -lUnicodeConverter -lkernel -lkernel_network -lgraphics
    LIBS += -ldl
}

SOURCES += main.cpp
