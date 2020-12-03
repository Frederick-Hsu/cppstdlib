#ifndef PERFECT_FORWARDING_HPP
#define PERFECT_FORWARDING_HPP

    #include <forward_list>

    // #include <bits/move.h>

namespace MySTL
{
/*================================================================================================*/

    /* Definitions: */
    template<typename T, typename U> void functionA(T&& a, U&& b);

    template<typename ElemType> struct remove_reference
    {
        typedef ElemType type;
    };

    template<typename ElemType> struct remove_reference<ElemType&>
    {
        typedef ElemType type;
    };

    template<typename ElemType> struct remove_reference<ElemType&&>
    {
        typedef ElemType type;
    };

    template<typename ElemType> constexpr ElemType&& forward(typename remove_reference<ElemType>::type&  Elem) noexcept;
    template<typename ElemType> constexpr ElemType&& forward(typename remove_reference<ElemType>::type&& Elem) noexcept;
    template<typename ElemType> constexpr typename remove_reference<ElemType>::type&& move(ElemType&& Elem) noexcept;

/*================================================================================================*/

    /* Implementations: */
    template<typename ElemType> constexpr ElemType&& forward(typename remove_reference<ElemType>::type&  Elem) noexcept
    {
        return static_cast<ElemType&&>(Elem);
    }

    template<typename ElemType> constexpr ElemType&& forward(typename remove_reference<ElemType>::type&& Elem) noexcept
    {
        static_assert(!std::is_lvalue_reference<ElemType>::value,
                      "template argument substituting ElemType is an lvalue reference type.\n");
        return static_cast<ElemType&&>(Elem);
    }

    template<typename ElemType> constexpr typename remove_reference<ElemType>::type&& move(ElemType&& Elem) noexcept
    {
        return static_cast<typename remove_reference<ElemType>::type&&>(Elem);
    }

    template<typename T, typename U> void functionA(T&& a, U&& b)
    {
        functionB(forward<T>(a), forward<U>(b));
    }
}

#endif  /* PERFECT_FORWARDING_HPP */
