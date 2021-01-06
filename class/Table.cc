#include "Table.hh"

#include <cstring>
#include <cstdlib>
#include <exception>

Name::Name(const char* name)
{
    if (name == nullptr)
    {
        str = nullptr;
    }
    else
    {
        size_t len = strlen(name);

        str = (char*)malloc(sizeof(char) * (len+1));
        if (str ==nullptr)
        {
            throw std::bad_alloc();
        }
        memcpy(str, name, len);
        str[len] = '\0';
    }
}

Name::Name(const Name& other)
{
    size_t len = strlen(other.str);
    if (len > 0)
    {
        str = (char*)malloc(sizeof(char) * (len + 1));
        if (str == nullptr)
        {
            throw std::bad_alloc();
        }
        memcpy(str, other.str, len);
        str[len] = '\0';
    }
    else
    {
        str = nullptr;
    }
}

Name& Name::operator=(const Name& other)
{
    if (this != &other)
    {
        if (str != nullptr)
        {
            free(str);
        }
        size_t len = strlen(other.str);
        if (len > 0)
        {
            str = (char*)malloc(sizeof(char) * (len+1));
            if (str == nullptr)
            {
                throw std::bad_alloc();
            }
            memcpy(str, other.str, len);
            str[len] = '\0';
        }
        else
        {
            str = nullptr;
        }
    }
    return *this;
}

Name::~Name()
{
    if (str != nullptr)
    {
        free(str);
    }
}

Table::Table(size_t s)
{
    p = new Name[sz=s];
}

Table::~Table()
{
    if (p != nullptr)
    {
        delete [] p;
        p = nullptr;
        sz = 0;
    }
}

Table::Table(const Table& other)
{
    p = new Name[sz=other.sz];
    for (size_t index = 0; index < sz; ++index)
    {
        p[index] = other.p[index];
    }
}

Table& Table::operator=(const Table& other)
{
    if (this != &other)     /* cannot copy itself */
    {
        delete [] p;
        p = new Name[sz = other.sz];
        for (size_t index = 0; index < sz; ++index)
        {
            p[index] = other.p[index];
        }
    }
    return *this;
}

Table::Table(Table&& other)
{
    if (other.p == nullptr)
    {
        p = nullptr;
        sz = 0;
    }

    sz = other.sz;
    p = other.p;
    for (size_t index = 0; index < sz; ++index)
    {
        p[index] = other.p[index];
    }

    other.p = nullptr;
    other.sz = 0;
}

Table& Table::operator=(Table&& other)
{
    if (this == &other)
    {
        return *this;
    }

    if (p != nullptr)
    {
        delete [] p;
    }
    sz = other.sz;
    p = other.p;
    for (size_t index = 0; index < sz; ++index)
    {
        p[index] = other.p[index];
    }

    other.p = nullptr;
    other.sz = 0;
    return *this;
}