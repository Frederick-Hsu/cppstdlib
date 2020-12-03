#ifndef HASH_HPP
#define HASH_HPP

    #include <cstddef>
    #include <string>

    #include "hash_impl.hpp"

namespace MyContainers
{
/*================================================================================================*/

    /* Prototypes: */
    template<typename Result, typename Arg> struct hash_base;
    template<typename T>                    struct hash;        /* primary class template hash */

/*================================================================================================*/

    /* Defintions: */
    template<typename Result, typename Arg> struct hash_base
    {
        typedef Result      result_type;
        typedef Arg         argument_type;
    };

    /* partial specializations for pointer types */
    template<typename T> struct hash<T*> : public hash_base<size_t, T*>
    {
        size_t operator()(T* arg) const noexcept;
    };

    template<> struct hash<float> : public hash_base<size_t, float>
    {
        size_t operator()(float val) const noexcept
        {
            return ((val != 0.0f) ? hash_impl::hash(val) : 0);
        }
    };

    template<> struct hash<double> : public hash_base<size_t, double>
    {
        size_t operator()(double val) const noexcept
        {
            return ((val != 0.0) ? hash_impl::hash(val) : 0);
        }
    };

    template<> struct hash<long double> : public hash_base<size_t, long double>
    {
        size_t operator()(long double val) const noexcept;
    };

    template<> struct hash<std::string> : public hash_base<size_t, std::string>
    {
        size_t operator()(const std::string& str) const noexcept
        {
            return hash_impl::hash(str.data(), str.length());
        }
    };

    #define hash_specialize(ElemType)                                               \
        template<> struct hash<ElemType> : public hash_base<size_t, ElemType>       \
        {                                                                           \
            size_t operator()(ElemType val) const noexcept                          \
            {                                                                       \
                return static_cast<size_t>(val);                                    \
            }                                                                       \
        };

/*================================================================================================*/

    /* Implementations : */
    template<typename T>
    size_t hash<T*>::operator()(T* arg) const noexcept
    {
        return reinterpret_cast<size_t>(arg);
    }

        hash_specialize(bool)
        hash_specialize(char)
        hash_specialize(signed char)
        hash_specialize(unsigned char)
        hash_specialize(wchar_t)
        hash_specialize(char16_t)
        hash_specialize(char32_t)
        hash_specialize(short)
        hash_specialize(int)
        hash_specialize(long)
        hash_specialize(long long)
        hash_specialize(unsigned short)
        hash_specialize(unsigned int)
        hash_specialize(unsigned long)
        hash_specialize(unsigned long long)

    #undef hash_specialize
}

#endif  /* HASH_HPP */
