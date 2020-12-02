#ifndef INITIALIZER_LISTS_H
#define INITIALIZER_LISTS_H

    #include <initializer_list>

    #include "Complex.hh"

    class P
    {
    public:
        P(int a, int b);
        P(std::initializer_list<int> initlist);
#if (CONVERSION == IMPLICIT)
        P(int a, int b, int c);
#elif (CONVERSION == EXPLICIT)
        explicit P(int a, int b, int c);
#endif
    };

    void funcp(const P&);

/*================================================================================================*/

namespace MySTL
{
    /* Definitions */
    template<class ElemType> class Initializer_List
    {
    public:
        typedef       ElemType      value_type;
        typedef const ElemType&     reference;
        typedef const ElemType&     const_reference;
        typedef       std::size_t   size_type;
        typedef const ElemType*     iterator;
        typedef const ElemType*     const_iterator;
    private:
        iterator    _M_array;
        size_type   _M_len;
    private:
        constexpr Initializer_List(const_iterator _a, size_type _b);
    public:
        constexpr Initializer_List() noexcept;
    public:
        constexpr size_type size() const noexcept;
        constexpr const_iterator begin() const noexcept;
        constexpr const_iterator end()   const noexcept;
    };

    template<class ElemType> constexpr const ElemType* begin(Initializer_List<ElemType> _list) noexcept;
    template<class ElemType> constexpr const ElemType*   end(Initializer_List<ElemType> _list) noexcept;

/*================================================================================================*/

    /* Implementations */
    template<class ElemType>
    constexpr Initializer_List<ElemType>::Initializer_List(const_iterator _a, size_type _len)
        : _M_array(_a), _M_len(_len)
    {
    }

    template<class ElemType>
    constexpr Initializer_List<ElemType>::Initializer_List() noexcept
        : _M_array(0), _M_len(0)
    {
    }

    template<class ElemType>
    constexpr typename Initializer_List<ElemType>::size_type Initializer_List<ElemType>::size() const noexcept
    {
        return _M_len;
    }

    template<class ElemType>
    constexpr typename Initializer_List<ElemType>::const_iterator Initializer_List<ElemType>::begin() const noexcept
    {
        return _M_array;
    }

    template<class ElemType>
    constexpr typename Initializer_List<ElemType>::const_iterator Initializer_List<ElemType>::end() const noexcept
    {
        return _M_array + _M_len;
    }

    template<class ElemType>
    constexpr const ElemType* begin(Initializer_List<ElemType> _list) noexcept
    {
        return _list.begin();
    }

    template<class ElemType>
    constexpr const ElemType* end(Initializer_List<ElemType> _list) noexcept
    {
        return _list.end();
    }
}

    void apply_initializer_list(void);

#endif  /* INITIALIZER_LISTS_H */
