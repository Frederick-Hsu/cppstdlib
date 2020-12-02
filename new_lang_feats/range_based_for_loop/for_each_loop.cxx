
#include <iostream>
#include <initializer_list>

template<typename Container> void PrintElements(const Container& coll)
{
#if 0
    for (const auto& elem : coll)
    {
        std::cout << elem << std::endl;
    }
#else
    for (auto pos = std::begin(coll); pos != std::end(coll); ++pos)
    {
        std::cout << *pos << std::endl;
    }
#endif
}


