#ifndef ALIAS_TYPE_HPP
#define ALIAS_TYPE_HPP

    /* type alias, identical to */
    typedef void (*pfn)(int, int);

    /* the name "pfunc" now denotes a pointer to function */
    using pfunc = void (*)(int, int);

    void example(int, int)
    {
    }

    pfunc fn = example;

#endif  /* ALIAS_TYPE_HPP */
