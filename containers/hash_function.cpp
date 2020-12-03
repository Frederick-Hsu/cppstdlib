#include "hash_function.hpp"

namespace MyContainers
{
    size_t stl_hash_string(const char* str)
    {
        unsigned long h = 0;
        for (; *str; ++str)
        {
            h = 5 * h + *str;
        }
        return size_t(h);
    }

    size_t stl_hash_string(char* str)
    {
        unsigned long h = 0;
        for (; *str; ++str)
        {
            h = 5 * h + *str;
        }
        return size_t(h);
    }
}
