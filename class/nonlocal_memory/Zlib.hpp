#ifndef ZLIB_HPP
#define ZLIB_HPP

    #include <string>

    class Zlib;

    class Zlib
    {
    private:
        static bool initialized;
        static void initialize();
    private:
        int num;
        std::string name;
    public:
        /* no constructor */
        void* create();
        void destroy(void* pobj);
    };

#endif  /* ZLIB_HPP */