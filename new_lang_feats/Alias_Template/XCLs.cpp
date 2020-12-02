#include "XCLs.hpp"

#include <string>
#include <vector>
#include <list>
#include <queue>

/* alias template */
template<typename T> using Vector = std::vector<T, std::allocator<T>>;
template<typename T> using List = std::list<T, std::allocator<T>>;
template<typename T> using Queue = std::queue<T, std::allocator<T>>;
template<class CharT> using MyString = std::basic_string<CharT, std::char_traits<CharT>>;

void test_template_template_argument(void)
{
    /* "Vector" to designate the template template parameter "template<class> class Container"
     * (i.e. Container<T>)
     */
    XCLs<int, Vector> c1;
    XCLs<std::string, List> c2;

    typedef MyString<char> mystring;
    XCLs<mystring, Queue> c3;
}
