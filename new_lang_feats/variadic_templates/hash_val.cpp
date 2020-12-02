#include <iostream>

template<typename T, typename... Types> void hash_val(std::size_t& seed,
                                                      const T& val,
                                                      const Types&... args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template<typename... Types> std::size_t hash_val(const Types&... args)
{
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

template<typename T> void hash_combine(std::size_t& seed, const T& val)
{
    seed ^= std::hash<T>()(val) + 0x9E3779B9 + (seed << 6) + (seed >> 2);
}

template<typename T> void hash_val(std::size_t& seed, const T& val)
{
    hash_combine(seed, val);
}
