#include "object_array.hpp"
#include "Table.hh"

#include <iostream>
#include <vector>

IBuffer::IBuffer()
{
    std::cin >> buf;
}

IBuffer::~IBuffer()
{
    #if defined (DEBUG)
    std::cout << "buf = " << buf << std::endl;
    std::cout << "IBuffer::~IBuffer() destructor called.\n" << std::endl;
    #endif
}

void init_object_array()
{
    IBuffer words[10];

    std::vector<Table>* p1 = new std::vector<Table>(10);
    Table* p2 = new Table;

    delete p1;
    delete p2;
}