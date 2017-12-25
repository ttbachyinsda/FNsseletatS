TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
INCLUDEPATH += /home/ttbachyinsda/RAMCloud/src
INCLUDEPATH += /home/ttbachyinsda/RAMCloud/install/include
LIBS += -L/home/ttbachyinsda/RAMCloud/install/lib/ramcloud/ -lramcloud
QMAKE_CXXFLAGS += -D_GLIBCXX_USE_CXX11_ABI=0 -g -DNDEBUG -Wl,-rpath=/home/ttbachyinsda/RAMCloud/install/bin
SOURCES += main.cpp \
    NFS/nf.cpp \
    NFS/nat.cpp \
    RC/rc.cpp

HEADERS += \
    NFS/nf.h \
    NFS/nat.h \
    NFS/define.h \
    RC/rc.h

DISTFILES += \
    readme.md
