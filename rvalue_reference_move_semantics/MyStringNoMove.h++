#ifndef MYSTRING_NOMOVE_HPP
#define MYSTRING_NOMOVE_HPP

    #include <cstddef>

    #include "MyString.hpp"

    template<typename M> void test_nonmoveable(M container, long value);

    class MyStringNoMove;

    class MyStringNoMove
    {
    public:
        static size_t DCtor;
        static size_t Ctor;
        static size_t CCtor;
        static size_t CAsgn;
        static size_t MAsgn;
        static size_t MCtor;
        static size_t Dtor;
    private:
        char* m_data;
        size_t m_len;
    private:
        void init_data(const char* str);
    public:
        MyStringNoMove();
        explicit MyStringNoMove(const char* str);
        MyStringNoMove(const MyStringNoMove& str);
        MyStringNoMove& operator=(const MyStringNoMove& str);
        virtual ~MyStringNoMove();
    public:
        bool operator< (const MyStringNoMove& rhs) const;
        bool operator==(const MyStringNoMove& rhs) const;
        char* get() const;
    };

    template<typename M> void test_nonmoveable(M container, long value)
    {
        test_moveable(container, value);
    }


#endif /* MYSTRING_NOMOVE_HPP */
