include(common-baselib.pri)

TEMPLATE    = lib
# hide_symbols avoids exporting all symbols from dll with gcc
CONFIG      += dll hide_symbols

TARGET      = xivoclient

# Library version
VERSION      = $${XIVOVER}
DEFINES     += BASELIB_LIBRARY

INCLUDEPATH += $${ROOT_DIR}/src

HEADERS     += $${ROOT_DIR}/src/*.h
HEADERS     += $${ROOT_DIR}/src/storage/*.h
HEADERS     += $${ROOT_DIR}/src/dao/*.h

SOURCES     += $${ROOT_DIR}/src/*.cpp
SOURCES     += $${ROOT_DIR}/src/storage/*.cpp
SOURCES     += $${ROOT_DIR}/src/dao/*.cpp

DESTDIR     = $${BIN_DIR}

QT += network
QT += widgets

TRANSLATIONS += $${ROOT_DIR}/baselib_en.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_es_CL.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_es_ES.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_pt_BR.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_hu.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_ja.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_de.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_it.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_fr.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_nl.ts
TRANSLATIONS += $${ROOT_DIR}/baselib_pl.ts

QMAKE_EXTRA_COMPILERS += updateqm
updateqm.input = TRANSLATIONS
updateqm.output = $$ROOT_DIR/obj/${QMAKE_FILE_BASE}.qm
updateqm.commands = $$QMAKE_LRELEASE -silent ${QMAKE_FILE_IN} -qm ${QMAKE_FILE_OUT}
# no_link = not included for linking
# target_predep = will be compiled before the executable
updateqm.CONFIG += no_link target_predeps

RESOURCES += $${ROOT_DIR}/baselib.qrc $${ROOT_DIR}/translations.qrc

MOC_DIR = $$ROOT_DIR/obj
OBJECTS_DIR = $$ROOT_DIR/obj
RCC_DIR = $$ROOT_DIR/obj

# This adds test-coverage infos
# debug {
#     LIBS += -lgcov
#     QMAKE_CXXFLAGS += -g -fprofile-arcs -ftest-coverage -O0 --coverage
#     QMAKE_LDFLAGS += -g -fprofile-arcs -ftest-coverage  -O0 --coverage
# }
