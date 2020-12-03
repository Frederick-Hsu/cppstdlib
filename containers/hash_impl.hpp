#ifndef HASH_IMPL_HPP
#define HASH_IMPL_HPP

    #include <cstddef>

    #include <bits/hash_bytes.h>

namespace MyContainers
{
    struct hash_impl
    {
        static size_t hash(const void* ptr,
                           size_t length,
                           size_t seed = static_cast<size_t>(0xC70F690UL))
        {
            return std::_Hash_bytes(ptr, length, seed);
        }

        template<typename T> static size_t hash(const T& val)
        {
            return hash(&val, sizeof(val));
        }

        template<typename T> static size_t hash_combine(const T& val, size_t _hash)
        {
            return hash(&val, sizeof(val), _hash);
        }
    };

    struct Fnv_hash_impl
    {
        static size_t hash(const void* ptr,
                           size_t length,
                           size_t seed = static_cast<size_t>(2166136261UL))
        {
            return std::_Fnv_hash_bytes(ptr, length, seed);
        }

        template<typename T> static size_t hash(const T& val)
        {
            return hash(&val, sizeof(val));
        }

        template<typename T> static size_t hash_combine(const T& val, size_t _hash)
        {
            return hash(&val, sizeof(val), _hash);
        }
    };
}

#endif  /* HASH_IMPL_HPP */
