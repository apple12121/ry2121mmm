QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Demo01_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    images/101.bmp \
    images/102.bmp \
    images/103.bmp \
    images/104.bmp \
    images/105.bmp \
    images/106.bmp \
    images/107.bmp \
    images/108.bmp \
    images/118.bmp \
    images/119.bmp \
    images/120.bmp \
    images/121.bmp \
    images/122.bmp \
    images/123.bmp \
    images/124.bmp \
    images/125.bmp \
    images/126.bmp \
    images/127.bmp \
    images/128.bmp \
    images/129.bmp \
    images/130.bmp \
    images/131.bmp \
    images/165.JPG \
    images/194.JPG \
    images/20.ico \
    images/300.bmp \
    images/301.bmp \
    images/302.bmp \
    images/303.bmp \
    images/304.bmp \
    images/305.bmp \
    images/306.bmp \
    images/307.bmp \
    images/308.bmp \
    images/309.bmp \
    images/310.bmp \
    images/311.bmp \
    images/312.bmp \
    images/313.bmp \
    images/314.bmp \
    images/315.bmp \
    images/316.bmp \
    images/317.bmp \
    images/318.bmp \
    images/319.bmp \
    images/320.bmp \
    images/321.bmp \
    images/322.bmp \
    images/323.bmp \
    images/324.bmp \
    images/325.bmp \
    images/326.bmp \
    images/327.bmp \
    images/328.bmp \
    images/329.bmp \
    images/330.bmp \
    images/331.bmp \
    images/332.bmp \
    images/333.bmp \
    images/400.bmp \
    images/401.bmp \
    images/402.bmp \
    images/403.bmp \
    images/404.bmp \
    images/405.bmp \
    images/406.bmp \
    images/407.bmp \
    images/408.bmp \
    images/409.bmp \
    images/410.bmp \
    images/411.bmp \
    images/412.bmp \
    images/413.bmp \
    images/414.bmp \
    images/415.bmp \
    images/416.bmp \
    images/417.bmp \
    images/418.bmp \
    images/419.bmp \
    images/420.bmp \
    images/421.bmp \
    images/422.bmp \
    images/423.bmp \
    images/424.bmp \
    images/425.bmp \
    images/426.bmp \
    images/427.bmp \
    images/428.bmp \
    images/429.bmp \
    images/430.bmp \
    images/431.bmp \
    images/432.bmp \
    images/433.bmp \
    images/BLD.BMP \
    images/DBLUNDR.BMP \
    images/ITL.BMP \
    images/UNDRLN.BMP \
    images/WORDUNDR.BMP \
    images/check2.ico \
    images/copy.bmp \
    images/copy2.bmp \
    images/cut.bmp \
    images/cut2.bmp \
    images/delete1.bmp \
    images/delete2.bmp \
    images/delfold1.bmp \
    images/delfold2.bmp \
    images/exit.bmp \
    images/exit2.bmp \
    images/export1.bmp \
    images/export2.bmp \
    images/f231ab38cc2efeea851dba37a8b6648.bmp \
    images/fold.bmp \
    images/fold2.bmp \
    images/folder1.bmp \
    images/folder2.bmp \
    images/import1.bmp \
    images/import2.bmp \
    images/new1.bmp \
    images/new2.bmp \
    images/next1.bmp \
    images/next2.bmp \
    images/open1.bmp \
    images/open2.bmp \
    images/open3.bmp \
    images/open4.bmp \
    images/paste.bmp \
    images/paste2.bmp \
    images/picture.zip \
    images/pre1.bmp \
    images/pre2.bmp \
    images/preview1.bmp \
    images/preview2.bmp \
    images/print1.bmp \
    images/print2.bmp \
    images/redo.bmp \
    images/redo2.bmp \
    images/save1.bmp \
    images/save2.bmp \
    images/saveall1.bmp \
    images/saveall2.bmp \
    images/ubdo.bmp \
    images/undo.bmp \
    images/undo2.bmp \
    images/upfold1.bmp \
    images/upfold2.bmp
