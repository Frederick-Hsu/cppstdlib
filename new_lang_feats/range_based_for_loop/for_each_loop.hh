#ifndef FOR_EACH_LOOP_HH
#define FOR_EACH_LOOP_HH

    #include "../initializer/Complex.hh"
    template<typename Container> void PrintElements(const Container& coll);

    #include "for_each_loop.cxx"

    class MyStrProc
    {
    public:
#if (CONVERSION == IMPLICIT)
        MyStrProc(std::string& s) {}
#elif (CONVERSION == EXPLICIT)
        explicit MyStrProc(std::string& s) {}
#endif
    };

#endif  /* FOR_EACH_LOOP_HH */
