#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

namespace MySTL
{
    /* Prototypes */
    template<class ElemType, std::size_t Nm> struct Array;

/*================================================================================================*/

    /* Definitions */

    template<class ElemType, std::size_t Nm> struct Array
    {
        typedef ElemType        value_type;
        typedef ElemType*       pointer;
        typedef value_type*     iterator;

        value_type _M_instance[Nm ? Nm : 1];
        iterator begin();
        iterator end();
    };

/*================================================================================================*/

    /* Implementations */
    template<class ElemType, std::size_t Nm>
    typename Array<ElemType, Nm>::iterator Array<ElemType, Nm>::begin()
    {
        return iterator(&_M_instance[0]);
    }

    template<class ElemType, std::size_t Nm>
    typename Array<ElemType, Nm>::iterator Array<ElemType, Nm>::end()
    {
        return iterator(&_M_instance[Nm]);
    }
}

    void test_Array(void);

#endif  /* ARRAY_HPP */
