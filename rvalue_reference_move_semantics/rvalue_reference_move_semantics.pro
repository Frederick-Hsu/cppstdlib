TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        MyString.cpp \
        MyStringNoMove.c++ \
        Rvalue_Reference.cpp \
        hash.cpp \
        main.cpp \
        perfect_forwarding.cpp \
        unperfect_forwarding.cpp

HEADERS += \
    MyString.hpp \
    MyStringNoMove.h++ \
    Rvalue_Reference.hpp \
    hash.hpp \
    perfect_forwarding.hpp \
    unperfect_forwarding.hpp
