#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

    #include <functional>

namespace MyContainers
{
    template<typename ElemType,
             typename Hash = std::hash<ElemType>,
             typename EqPred = std::equal_to<ElemType>,
             typename Allocator = std::allocator<ElemType>>
#if (__cplusplus >= 201103L)    /* C++11 */
    class unordered_set;
#else   /* C++0x */
    class hash_set;
#endif

    template<typename ElemType,
             typename Hash = std::hash<ElemType>,
             typename EqPred = std::equal_to<ElemType>,
             typename Allocator = std::allocator<ElemType>>
#if (__cplusplus >= 201103L)    /* C++11 */
    class unordered_multiset;
#else   /* C++0x */
    class hash_multiset;
#endif

    template<typename Key,
             typename Value,
             typename Hash = std::hash<Value>,
             typename EqPred = std::equal_to<Value>,
             typename Allocator = std::allocator<std::pair<const Key, Value>>>
#if (__cplusplus >= 201103L)    /* C++11 */
    class unordered_map;
#else   /* C++0x */
    class hash_map;
#endif

    template<typename Key,
             typename Value,
             typename Hash = std::hash<Value>,
             typename EqPred = std::equal_to<Value>,
             typename Allocator = std::allocator<std::pair<const Key, Value>>>
#if (__cplusplus >= 201103L)    /* C++11 */
    class unordered_multimap;
#else   /* C++0x */
    class hash_map;
#endif
}

#endif  /* HASH_TABLE_HPP */
