#ifndef CURIOUS_H
#define CURIOUS_H


    class Curious;

    int myrandom(int x);

    class Curious
    {
    private:
        static const int c1 = 7;
        // static int c2 = 11;     /* ISO C++ forbids in-class initialization of non-const static member */
        const int c3 = 13;
        static const int c4;    //  = myrandom(17);     /* call to non-'constexpr' function myrandom() */
        static const float c5;  //  = 7.0;    /* 'constexpr' needed for in-class initialization of static data member of non-integral type */
        const int* ptr;
    public:
        Curious();
    };

#endif  /* CURIOUS_H */