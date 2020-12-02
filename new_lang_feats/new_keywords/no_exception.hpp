#ifndef NO_EXCEPTION_HPP
#define NO_EXCEPTION_HPP

    #include <cstddef>

    void foo() noexcept;    /* Assure that this foo() function won't throw any exception */

namespace MySTL
{
    class MyString;

    class MyString
    {
    private:
        char* m_data;
        std::size_t m_len;
    public:
        MyString(const char* str);
        ~MyString();
        MyString(MyString&& str) noexcept;
        MyString& operator=(const MyString&& str) noexcept;
    };
}

#endif  /* NO_EXCEPTION_HPP */
