#ifndef WRONG_HXX
#define WRONG_HXX

    struct XWrong
    {
        const int a;        /* uninitialized const member */
        const int& ref;     /* uninitialized reference member */
    };

#endif  /* WRONG_HXX */