#ifndef MYSTRING_HPP
#define MYSTRING_HPP

    /* Includes: */
    #include <cstdio>
    #include <iostream>
    #include <iterator>
    #include <ctime>
    #include <typeinfo>

    #include "perfect_forwarding.hpp"

/*================================================================================================*/

    /* Prototypes: */
    class MyString;

    template<typename M> void test_moveable(M container, long value);
    template<typename T> void output_static_data(const T& obj);

/*================================================================================================*/

    /* Definitions: */
    class MyString
    {
    public:
        static size_t DCtor;        /* 累计 default         constructor 呼叫次数 */
        static size_t Ctor;         /* 累计                 constructor 呼叫次数 */
        static size_t CCtor;        /* 累计 copy            constructor 呼叫次数 */
        static size_t CAsgn;        /* 累计 copy assignment constructor 呼叫次数 */
        static size_t MCtor;        /* 累计 move            constructor 呼叫次数 */
        static size_t MAsgn;        /* 累计 move assignment constructor 呼叫次数 */
        static size_t Dtor;         /* 累计                 destructor  呼叫次数 */
    private:
        char* m_data;
        size_t m_len;
    private:
        void init_data(const char* str);
    public:
        MyString();                                     /* default         constructor  */
        explicit MyString(const char* str);             /* explicit        constructor  */
        explicit MyString(char str[], int len);
        explicit MyString(const std::initializer_list<char>& str);
        MyString(const MyString& str);                  /* copy            constructor  */
        MyString(MyString&& str) noexcept;              /* move            constructor  */
        MyString& operator=(const MyString& str);       /* copy assignment constructor  */
        MyString& operator=(MyString&& str) noexcept;   /* move assignment constructor  */
        virtual ~MyString();                            /* default         destructor   */
    public:
        bool operator< (const MyString& rhs) const;
        bool operator==(const MyString& rhs) const;
        char* get() const;
    };

/*================================================================================================*/

    /* Implementations: */
    template<typename T> void output_static_data(const T& obj)
    {
        std::cout << "\n" << typeid(obj).name() << " --- " << std::endl
                  << "DCtor = " << T::DCtor << "\n"
                  << " Ctor = " << T::Ctor  << "\n"
                  << "CCtor = " << T::CCtor << "\n"
                  << "MCtor = " << T::MCtor << "\n"
                  << "CAsgn = " << T::CAsgn << "\n"
                  << "MAsgn = " << T::MAsgn << "\n"
                  << " Dtor = " << T::Dtor
                  << std::endl;

    }

    template<typename M> void test_moveable(M container, long value)
    {
        char buf[10];

#if defined (TEMPLATE_ALIAS)
        using Vtype = typename std::iterator_traits<typename M::iterator>::value_type;
#else
        typedef typename std::iterator_traits<typename M::iterator>::value_type Vtype;
#endif

        std::clock_t timeStart = std::clock();
        for (long i = 0; i < value; ++i)
        {
            std::snprintf(buf, 10, "%d", rand());
            auto iter = container.end();
            container.insert(iter, Vtype(buf));
        }
        std::cout << "construction, milli-seconds: " << (std::clock() - timeStart) << std::endl;
        std::cout << "sizeof() = " << container.size() << std::endl;

        output_static_data(*(container.begin()));

        timeStart = std::clock();
        M container1(container);
        // std::cout << "sizeof(container1) = " << container1.size() << std::endl;
        std::cout << "container copy: " << (std::clock() - timeStart) << " milli-seconds." << std::endl;

        timeStart = std::clock();
        M container2(MySTL::move(container1));
        // std::cout << "sizeof(container2) = " << container2.size() << std::endl;
        std::cout << "container move copy: " << (std::clock() - timeStart) << " milli-seconds." << std::endl;

        timeStart = std::clock();
        container1.swap(container2);
        std::cout << "container swap: " << (std::clock() - timeStart) << "milli-seconds." << std::endl;
    }

#endif  /* MYSTRING_HPP */
