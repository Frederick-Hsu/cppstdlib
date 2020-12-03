#ifndef UNIVERSAL_HASH_FUNCTION_HPP
#define UNIVERSAL_HASH_FUNCTION_HPP

    #include <cstddef>

    #include "hash.hpp"

namespace MyContainers
{
/*================================================================================================*/

    /* Prototypes: */
    template<typename T>                    inline void   hash_combine(size_t& seed, const T& val);
    template<typename T>                    inline void   hash_val(    size_t& seed, const T& val);
    template<typename T, typename... Types> inline void   hash_val(    size_t& seed, const T& val, const Types&... args);
    template<typename... Types>             inline size_t hash_val(                                const Types&... args);

/*================================================================================================*/

    /* Implementations: */
    template<typename T> void hash_combine(size_t& seed, const T& val)
    {
        seed ^= hash<T>()(val) +
                0x9E3779B9 +
                (seed << 6) +
                (seed >> 2);
    }

    template<typename T> void hash_val(size_t& seed, const T& val)
    {
        hash_combine(seed, val);
    }

    template<typename T, typename... Types> void hash_val(size_t& seed, const T& val, const Types&... args)
    {
        hash_val(seed, val);
        hash_val(seed, args...);
    }

    template<typename... Types> size_t hash_val(const Types&... args)
    {
        size_t seed = 0;
        hash_val(seed, args...);
        return seed;
    }

}

#endif  /* UNIVERSAL_HASH_FUNCTION_HPP */
