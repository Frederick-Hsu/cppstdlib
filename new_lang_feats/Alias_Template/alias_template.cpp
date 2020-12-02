
#include <iostream>
#include <iterator>

template<typename T> void output_static_date(const T& obj)
{
    std::cout << obj << std::endl;
}

template<class Container> void test_movable(Container contnr)
{
    typedef typename std::iterator_traits<typename Container::iterator>::value_type Valtype;

    std::size_t SIZE = contnr.size();
    for (unsigned long index = 0; index < SIZE; ++index)
    {
        contnr.insert(contnr.end(), Valtype());
    }
    output_static_date(*(contnr.begin()));
    Container c1(contnr);
    Container c2(std::move(contnr));
    c1.swap(c2);
}
