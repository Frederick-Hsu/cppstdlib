#ifndef UNIFORM_INIT_H
#define UNIFORM_INIT_H

    #include <initializer_list>
    #include "initializer_lists.h"

    void uniform_initialize(void);

    void print(std::initializer_list<int> vals);
    void print(MySTL::Initializer_List<int> vals);

#endif  /* UNIFORM_INIT_H */
