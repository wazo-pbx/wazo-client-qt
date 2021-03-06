include(common-no-tests.pri)

TEMPLATE     = lib
win32:CONFIG += dll
unix:CONFIG  += plugin

INCLUDEPATH += $${BASELIB_DIR}/src
INCLUDEPATH += $${ROOT_DIR}/src

DESTDIR      = $${BIN_DIR}/plugins
macx:DESTDIR = $${BIN_DIR}/wazoclient.app/Contents/PlugIns

LIBS += -L$${BIN_DIR}
unix:LIBS += -lwazoclientxlets
win32 {
    release:LIBS += -lwazoclientxlets
    debug:LIBS += -lwazoclientxletsd
}
