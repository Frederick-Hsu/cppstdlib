#include "Test.h"
#include "Table.hh"
#include "object_array.hpp"
#include "local_static_memory/local_static_memory.hpp"
#include "nonlocal_memory/temp_objects.hpp"

#include <iostream>
#include <functional>

void perform_test_cases(void)
{
    // free_heap_storage();
    std::cout << "\n" << std::endl;

    // init_object_array();
    // investigate_local_static_memory(false);
    // investigate_local_static_memory(true);
    // investigate_local_static_memory(true);

    std::string bbc("bbc"), adefg("afg"), MNPQ("MNPQ");
    access_temp_objects_lifetime(bbc, adefg, MNPQ);
}


void free_heap_storage(void)
{
    Table* p = new Table;
    Table* q = new Table;

    delete p;
    delete q;
}