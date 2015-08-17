TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    perceptron.cpp \
    testset.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    perceptron.h \
    testset.h \
    set.h

