TARGET = qgfxvnc
include(../../qpluginbase.pri)

DEFINES	+= QT_QWS_VNC

QTDIR_build:DESTDIR = $$QT_BUILD_TREE/plugins/gfxdrivers

HEADERS = \
	qscreenvnc_qws.h \
	qscreenvnc_p.h \
    d3des.h

SOURCES = main.cpp \
	qscreenvnc_qws.cpp \
    d3des.c

target.path += $$[QT_INSTALL_PLUGINS]/gfxdrivers
INSTALLS += target

OTHER_FILES += \
    README.txt
