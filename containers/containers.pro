TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CustomerHash.cpp \
        apply_tuple/apply_tuple.cpp \
        hash_function.cpp \
        hashtable.cpp \
        main.cpp

HEADERS += \
    CustomerHash.hpp \
    allocator.hpp \
    apply_tuple/apply_tuple.hpp \
    array.hpp \
    hash.hpp \
    hash_function.hpp \
    hash_impl.hpp \
    hashtable.hpp \
    list.hpp \
    universal_hash_function.hpp \
    vector.hpp
