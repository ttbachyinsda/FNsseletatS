TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += /home/ttbachyinsda/RAMCloud/src
INCLUDEPATH += /home/ttbachyinsda/RAMCloud/install/include
LIBS += -L/home/ttbachyinsda/RAMCloud/install/lib/ramcloud/ -lramcloud
QMAKE_CXXFLAGS += -D_GLIBCXX_USE_CXX11_ABI=0 -g -DNDEBUG -Wl,-rpath=/home/ttbachyinsda/RAMCloud/install/bin
SOURCES += main.cpp
