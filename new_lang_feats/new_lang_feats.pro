TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Alias_Template/XCLs.cpp \
        Alias_Template/alias_template.cpp \
        Alias_Template/test_template.cpp \
        Lambdas/Functor.cpp \
        Lambdas/LambdaFunctor.cpp \
        Lambdas/Lambdas.cpp \
        initializer/Array.cpp \
        initializer/Complex.cc \
        initializer/initializer_lists.cpp \
        initializer/uniform_init.cpp \
        main.cpp \
        new_keywords/Copy.cpp \
        new_keywords/DeclType.cpp \
        new_keywords/Empty.cpp \
        new_keywords/Override.cpp \
        new_keywords/Zoo.cpp \
        new_keywords/no_exception.cpp \
        range_based_for_loop/for_each_loop.cxx \
        test.cpp \
        variadic_templates/Tuple.cpp \
        variadic_templates/auxiliary.cpp \
        variadic_templates/customer_hash.cpp \
        variadic_templates/hash_val.cpp

HEADERS += \
    Alias_Template/XCLs.hpp \
    Alias_Template/alias_template.hpp \
    Alias_Template/test_template.hpp \
    Alias_Type/alias_type.hpp \
    Lambdas/Functor.hpp \
    Lambdas/LambdaFunctor.hpp \
    Lambdas/Lambdas.hpp \
    initializer/Array.hpp \
    initializer/Complex.hh \
    initializer/initializer_lists.h \
    initializer/uniform_init.h \
    new_keywords/Copy.hpp \
    new_keywords/DeclType.h \
    new_keywords/Empty.hpp \
    new_keywords/Noncopyable.hpp \
    new_keywords/Override.hpp \
    new_keywords/Zoo.hpp \
    new_keywords/no_exception.hpp \
    range_based_for_loop/for_each_loop.hh \
    test.h \
    variadic_templates/Tuple.h \
    variadic_templates/auxiliary.h \
    variadic_templates/customer_hash.h \
    variadic_templates/hash_val.h \
    variadic_templates/variadic_templates.h
