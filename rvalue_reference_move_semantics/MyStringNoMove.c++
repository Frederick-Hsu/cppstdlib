#include "MyStringNoMove.h++"

#include <cstdlib>
#include <cstring>

size_t MyStringNoMove::DCtor = 0;
size_t MyStringNoMove::Ctor  = 0;
size_t MyStringNoMove::CCtor = 0;
size_t MyStringNoMove::CAsgn = 0;
size_t MyStringNoMove::MCtor = 0;
size_t MyStringNoMove::MAsgn = 0;
size_t MyStringNoMove::Dtor  = 0;

void MyStringNoMove::init_data(const char* str)
{
    m_data = new char[m_len+1];
    memcpy(m_data, str, m_len);
    m_data[m_len] = '\0';
}

MyStringNoMove::MyStringNoMove() : m_data(NULL), m_len(0)
{
    ++DCtor;
}

MyStringNoMove::MyStringNoMove(const char* str) : m_len(strlen(str))
{
    ++Ctor;
    init_data(str);
}

MyStringNoMove::MyStringNoMove(const MyStringNoMove& str) : m_len(str.m_len)
{
    ++CCtor;
    init_data(str.m_data);
}

MyStringNoMove& MyStringNoMove::operator=(const MyStringNoMove& str)
{
    ++CAsgn;
    if (this != &str)
    {
        if (m_data)
        {
            delete [] m_data;
        }
        m_len = str.m_len;
        init_data(str.m_data);
    }
    return *this;
}

MyStringNoMove::~MyStringNoMove()
{
    ++Dtor;
    if (m_data)
    {
        delete [] m_data;
        m_data = NULL;
    }
    m_len = 0;
}

bool MyStringNoMove::operator<(const MyStringNoMove &rhs) const
{
    return (strcmp(m_data, rhs.m_data) < 0);
}

bool MyStringNoMove::operator==(const MyStringNoMove &rhs) const
{
    return (strcmp(m_data, rhs.m_data) == 0);
}

char* MyStringNoMove::get() const
{
    return m_data;
}
