#ifndef MY_ALGO_HPP
#define MY_ALGO_HPP

    #include <initializer_list>
    #include <algorithm>

namespace MyAlgorithms
{
/*================================================================================================*/

    /* Prototypes: */
    struct _Iter_less_iter
    {
        template<typename _Iterator1, typename _Iterator2>
        bool operator()(_Iterator1 it1, _Iterator2 it2) const;
    };

    template<typename ElemType> inline ElemType max(std::initializer_list<ElemType> elems);

    template<typename ForwardIterator> inline ForwardIterator max_element(ForwardIterator first,
                                                                          ForwardIterator last);

    template<typename ForwardIterator, typename Compare>
    ForwardIterator _max_element(ForwardIterator first, ForwardIterator last, Compare comp);

    inline _Iter_less_iter _iter_less_iter();

/*================================================================================================*/

    /* Implementations: */
    template<typename ElemType> ElemType max(std::initializer_list<ElemType> elems)
    {
        return *max_element(elems.begin(), elems.end());
    }

    template<typename ForwardIterator> ForwardIterator max_element(ForwardIterator first,
                                                                   ForwardIterator last)
    {
        return _max_element(first, last, _iter_less_iter());
    }

    template<typename ForwardIterator, typename Compare>
    ForwardIterator _max_element(ForwardIterator first, ForwardIterator last, Compare comp)
    {
        if (first == last)
            return first;
        ForwardIterator result = first;
        while (++first != last)
        {
            if (comp(result, first))
            {
                result = first;
            }
        }
        return result;
    }

    template<typename _Iterator1, typename _Iterator2>
    bool _Iter_less_iter::operator()(_Iterator1 it1, _Iterator2 it2) const
    {
        return (*it1 < *it2);
    }

    _Iter_less_iter _iter_less_iter()
    {
        return _Iter_less_iter();
    }
}

    void test_my_algorithms(void);

#endif  /* MY_ALGO_HPP */
