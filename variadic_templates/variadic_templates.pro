TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Tuple/tuple.cpp \
        main.cpp \
        my_algo.cpp \
        test.cpp

HEADERS += \
    Tuple/PRINT_TUPLE.hpp \
    Tuple/tuple.hpp \
    my_algo.hpp \
    printf.hpp \
    test.hpp \
    variadic_templates.hpp

DISTFILES += \
    Tuple/print_arbitrary_list.py
