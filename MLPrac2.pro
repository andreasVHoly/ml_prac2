TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    perceptron.cpp \
    testset.cpp \
    percepnetwork.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    perceptron.h \
    testset.h \
    set.h \
    percepnetwork.h

DISTFILES += \
    test.txt

