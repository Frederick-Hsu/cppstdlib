#ifndef HASH_FUNCTION_HPP
#define HASH_FUNCTION_HPP

    #include <cstddef>

namespace MyContainers
{
    inline size_t stl_hash_string(const char* str);
    inline size_t stl_hash_string(char* str);

    /* generic edition */
    template<typename Key> struct hash {};

    /* specific editions: */
    template<> struct hash<char>
    {
        size_t operator()(char x) const { return x; }
    };

    template<> struct hash<short>
    {
        size_t operator()(short x) const { return x; }
    };

    template<> struct hash<unsigned short>
    {
        size_t operator()(unsigned short x) const { return x; }
    };

    template<> struct hash<int>
    {
        size_t operator()(int x) const { return x; }
    };

    template<> struct hash<unsigned int>
    {
        size_t operator()(unsigned int x) const { return x; }
    };

    template<> struct hash<long>
    {
        size_t operator()(long x) const { return x; }
    };

    template<> struct hash<unsigned long>
    {
        size_t operator()(unsigned long x) const { return x; }
    };

    template<> struct hash<char*>
    {
        size_t operator()(char* s) const { return stl_hash_string(s); }
    };

    template<> struct hash<const char*>
    {
        size_t operator()(const char* s) const { return stl_hash_string(s); }
    };
}

#endif  /* HASH_FUNCTION_HPP */
