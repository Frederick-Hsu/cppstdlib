#include "MyString.hpp"

#include <cstdlib>
#include <cstring>
#include <cassert>

size_t MyString::DCtor = 0;
size_t MyString::Ctor  = 0;
size_t MyString::CCtor = 0;
size_t MyString::CAsgn = 0;
size_t MyString::MCtor = 0;
size_t MyString::MAsgn = 0;
size_t MyString::Dtor  = 0;

void MyString::init_data(const char* str)
{
    m_data = new char[m_len + 1];
    memcpy(m_data, str, m_len);
    m_data[m_len] = '\0';
}

MyString::MyString() : m_data(NULL), m_len(0)
{
    ++DCtor;
}

MyString::MyString(const char* str) : m_len(strlen(str))
{
    ++Ctor;
    init_data(str);
}

MyString::MyString(char str[], int len) : m_len(len)
{
    m_data = new char[m_len + 1];
    assert(m_data != NULL);

    memset(m_data, 0, m_len + 1);
    for (size_t index = 0; index < m_len; ++index)
    {
        m_data[index] = str[index];
    }
}

MyString::MyString(const std::initializer_list<char>& str) : m_len(str.size())
{
    m_data = new char[m_len + 1];
    int index = 0;
    for (auto& elem : str)
    {
        m_data[index++] = elem;
    }
    m_data[m_len] = '\0';
}

MyString::MyString(const MyString& str) : m_len(str.m_len)
{
    ++CCtor;
    init_data(str.m_data);
}

MyString::MyString(MyString&& str) noexcept : m_data(str.m_data), m_len(str.m_len)
{
    ++MCtor;
    str.m_len = 0;
    str.m_data = NULL;
}

MyString& MyString::operator=(const MyString& str)
{
    ++CAsgn;
    if (this != &str)
    {
        if (m_data)
        {
            delete[] m_data;
        }
        m_len = str.m_len;
        init_data(str.m_data);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& str) noexcept
{
    ++MAsgn;
    if (this != &str)
    {
        if (m_data)
        {
            delete[] m_data;
        }
        m_len = str.m_len;
        m_data = str.m_data;

        str.m_data = NULL;
        str.m_len = 0;
    }
    return *this;
}

MyString::~MyString()
{
    ++Dtor;
    if (m_data)
    {
        delete[] m_data;
    }
}

bool MyString::operator<(const MyString &rhs) const
{
    return (std::string(m_data) < std::string(rhs.m_data));
}

bool MyString::operator==(const MyString &rhs) const
{
    return (strcmp(m_data, rhs.m_data) == 0);
}

char* MyString::get() const
{
    return m_data;
}
