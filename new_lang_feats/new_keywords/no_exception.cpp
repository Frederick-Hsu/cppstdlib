#include "no_exception.hpp"

#include <cassert>
#include <cstring>
#include <cstdlib>

void foo() noexcept
{
}

namespace MySTL
{
    MyString::MyString(const char* str)
    {
        assert(str != nullptr);
        std::size_t len = strlen(str);
        m_len = len;

        m_data = (char*)malloc(sizeof(char) * (len + 1));
        assert(m_data != nullptr);
        memset(m_data, 0, sizeof(char) * (len+1));
        memcpy(m_data, str, sizeof(char)*len);
    }

    MyString::~MyString()
    {
        if (m_data != nullptr)
        {
            free(m_data);
            m_data = nullptr;
            m_len = 0;
        }
    }

    MyString::MyString(MyString&& str) noexcept
    {
        m_len = str.m_len;
        m_data = (char*)malloc(sizeof(char) * (m_len + 1));
        assert(m_data != nullptr);

        memset(m_data, 0, sizeof(char) * (m_len + 1));
        memcpy(m_data, str.m_data, sizeof(m_len));
    }

    MyString& MyString::operator=(const MyString&& str) noexcept
    {
        if (strlen(m_data) != 0)
        {
            free(m_data);
        }

        m_len = str.m_len;
        m_data = (char*)malloc(sizeof(char) * (m_len + 1));
        assert(m_data != nullptr);
        memset(m_data, 0, sizeof(char)*(m_len + 1));
        memcpy(m_data, str.m_data, sizeof(char)*m_len);

        return *this;

    }
}

