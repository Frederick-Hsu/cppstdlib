#ifndef HASH_VAL_H
#define HASH_VAL_H

    #include <iostream>

    template<typename T, typename... Types> inline void hash_val(std::size_t& seed,
                                                                 const T& val,
                                                                 const Types&... args);

    template<typename... Types> inline std::size_t hash_val(const Types&... args);

    template<typename T> inline void hash_val(std::size_t& seed, const T& val);

    template<typename T> inline void hash_combine(std::size_t& seed, const T& val);



    #include "hash_val.cpp"

#endif  /* HASH_VAL_H */
