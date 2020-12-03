#ifndef ARRAY_HPP
#define ARRAY_HPP

    #include <cstddef>
    #include <stdexcept>

namespace MyContainers
{
/*================================================================================================*/

    /* Prototypes: */
    template<typename ElemType, size_t Nm> struct array;
    template<typename ElemType, size_t Nm> struct array_traits;

/*================================================================================================*/

    /* Definitions: */
    template<typename ElemType, size_t Nm> struct array_traits
    {
        typedef ElemType Type[Nm];

        static constexpr ElemType& S_ref(const Type& Elem, size_t n) noexcept;
    };

    template<typename ElemType, size_t Nm> struct array
    {
        typedef ElemType        value_type;
        typedef ElemType*       pointer;
        typedef value_type*     iterator;
        typedef value_type&     reference;
        typedef size_t          size_type;

#if (__cplusplus >= 201103L)    /* C++11 */
        typedef array_traits<ElemType, Nm>  AT_Type;
        typename AT_Type::Type m_elems;

        iterator begin() noexcept;
        iterator end() noexcept;
        constexpr size_type size() const noexcept;
        reference operator[](size_type index) noexcept;
        reference at(size_type index);
        pointer data() noexcept;
#else   /* C++0x */
        value_type m_instance[Nm ? Nm : 1];
        iterator begin();
        iterator end();
#endif
    };

/*================================================================================================*/

    /* Implementations: */
    template<typename ElemType, size_t Nm>
    constexpr ElemType& array_traits<ElemType, Nm>::S_ref(const Type& Elements, size_t n) noexcept
    {
        return const_cast<ElemType&>(Elements[n]);
    }

#if (__cplusplus >= 201103L)    /* C++11 */
    template<typename ElemType, size_t Nm>
    typename array<ElemType, Nm>::iterator array<ElemType, Nm>::begin() noexcept
    {
        return iterator(data());
    }

    template<typename ElemType, size_t Nm>
    typename array<ElemType, Nm>::iterator array<ElemType, Nm>::end() noexcept
    {
        return iterator(data() + Nm);
    }

    template<typename ElemType, size_t Nm>
    constexpr typename array<ElemType, Nm>::size_type array<ElemType, Nm>::size() const noexcept
    {
        return Nm;
    }

    template<typename ElemType, size_t Nm>
    typename array<ElemType, Nm>::reference array<ElemType, Nm>::operator[](size_type index) noexcept
    {
        return AT_Type::S_ref(m_elems, index);
    }

    template<typename ElemType, size_t Nm>
    typename array<ElemType, Nm>::reference array<ElemType, Nm>::at(size_type index)
    {
        if (index >= Nm)
            throw std::runtime_error("out of range.\n");
        return AT_Type::S_ref(m_elems, index);
    }

    template<typename ElemType, size_t Nm>
    typename array<ElemType, Nm>::pointer array<ElemType, Nm>::data() noexcept
    {
        return std::addressof(AT_Type::S_ref(m_elems, 0));
    }
#else   /* C++0x */
    template<typename ElemType, size_t Nm>
    typename array<ElemType, Nm>::iterator array<ElemType, Nm>::begin()
    {
        return iterator(&m_instance[0]);
    }

    template<typename ElemType, size_t Nm>
    typename array<ElemType, Nm>::iterator array<ElemType, Nm>::end()
    {
        return iterator(&m_instance[Nm]);
    }
#endif
}

#endif  /* ARRAY_HPP */
