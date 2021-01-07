#include "Zlib.hpp"

#include <cassert>

bool Zlib::initialized = false;

void Zlib::initialize()
{
    initialized = true;
}

void* Zlib::create()
{
    num = 0;
    name = "Zlib";
    if (initialized == false)
    {
        initialize();
    }
    return static_cast<void*>(this);
}

void Zlib::destroy(void* pobj)
{
    Zlib* ptr = static_cast<Zlib*>(pobj);
    assert(ptr != nullptr);
    {
        delete ptr;
    }
}