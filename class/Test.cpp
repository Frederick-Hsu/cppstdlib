#include "Test.h"
#include "Table.hh"

#include <iostream>

void perform_test_cases(void)
{
    free_heap_storage();
    std::cout << "\n" << std::endl;
}


void free_heap_storage(void)
{
    Table* p = new Table;
    Table* q = new Table;

    delete p;
    delete q;
}