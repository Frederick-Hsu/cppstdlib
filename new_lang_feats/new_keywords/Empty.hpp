#ifndef EMPTY_HPP
#define EMPTY_HPP

    // #define COMPILER_GENERATE_DEFAULT

    class Empty;

    class Empty
    {
    /* For an empty class, compiler will generate the "default constructor", "copy constructor",
     * "assign constructor" and "destructor" automatically.
     */
#if defined (COMPILER_GENERATE_DEFAULT)
    public:
        Empty();
        Empty(const Empty& rhs);
        Empty& operator=(const Empty& rhs);
        ~Empty();
#endif
    };

    void test_empty_class_object(void);

#endif  /* EMPTY_HPP */
