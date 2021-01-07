#include "local_static_memory.hpp"
#include "../Table.hh"

void investigate_local_static_memory(bool flag)
{
    static Table tbl;

    if (flag)
    {
        static Table tbl2;
    }
}