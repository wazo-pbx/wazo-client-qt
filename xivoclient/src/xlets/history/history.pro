include(../../../common-xlets.pri)

HEADERS     = *.h
SOURCES     = *.cpp
FORMS       = history_widget.ui

TARGET      = historyplugin

TRANSLATIONS += $$ROOT_DIR/i18n/history_en.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_es_CL.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_es_ES.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_pt_BR.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_hu.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_de.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_ja.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_it.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_fr.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_nl.ts
TRANSLATIONS += $$ROOT_DIR/i18n/history_pl.ts

RESOURCES = history.qrc
