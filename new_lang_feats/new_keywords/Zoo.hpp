#ifndef ZOO_HPP
#define ZOO_HPP

    #include <chrono>

    class Zoo
    {
    public:
        Zoo(int i1, int i2);                    /* default consrtuctor */
        virtual ~Zoo();                         /* destructor */

        Zoo(const Zoo&) = delete;               /* copy constructor */
        Zoo(Zoo&&) = default;                   /* move copy constructor */
        Zoo& operator=(const Zoo&) = default;   /* assign constructor */
        Zoo& operator=(const Zoo&&)=  delete;   /* move assign constructor*/
    private:
        int d1;
        int d2;
    };

    class Foo
    {
    public:
        Foo(int i) : mi(i) {}
        Foo() = default;

        Foo(const Foo& x) : mi(x.mi) {}
        // Foo(const Foo&) = default;      /* 表明恢复编译器提供的那个拷贝构造函数，而弃用用户编写的copy ctor */
        // Foo(const Foo&) = delete;

        Foo& operator=(const Foo& x) { mi = x.mi; return *this; }
        // Foo& operator=(const Foo&) = default;
        // Foo& operator=(const Foo&) = delete;

        // void func1() = default;
        void func2() = delete;

        virtual ~Foo() {}
        // virtual ~Foo() = delete;
        // virtual ~Foo() = default;
    private:
        int mi;
    };

    void test_ctor_default_delete(void);

#endif  /* ZOO_HPP */
