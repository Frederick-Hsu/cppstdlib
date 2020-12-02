#ifndef XCLS_HPP
#define XCLS_HPP

    template<typename T, template<class> class Container> class XCLs;

    template<typename T, template<class> class Container>
    class XCLs
    {
    private:
        Container<T> contr;
    public:
        XCLs();
    };

    template<typename T, template<class> class Container>
    XCLs<T, Container>::XCLs() : contr(Container<T>())
    {
    }

    void test_template_template_argument(void);

#endif  /* XCLS_HPP */
