## .pro工程文件

由qmake创建生成，用于生成makefile。

```pro
QT       += core gui

# Qt4.0以上版本新增widgets。
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets		

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

# 生成的可执行文件名。
TARGET = 01_HelloQt		

# 模板类型：应用程序模板。
# app为默认值：建立一个应用程序的makefile。
# lib 	- 建立一个库的makefile。
# vcapp - 建立一个应用程序的VisualStudio项目文件。
# vclib - 建立一个库的VisualStudio项目文件。
# subdirs -特殊模板，创建能够进入特定目录并且为一个项目文件生成makefile同时调用make的makefile。
TEMPLATE = app			

# 源文件
SOURCES += \			
    main.cpp \
    mainwindow.cpp
    
# 头文件
HEADERS += \			
    mainwindow.h

# .ui设计文件
FORMS += forms/painter.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
```

