#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>

#include "Rvalue_Reference.hpp"
#include "MyString.hpp"
#include "unperfect_forwarding.hpp"
#include "MyStringNoMove.h++"

using namespace std;

template<typename T> using StrVec = std::vector<T>;

int main(int argc, char* argv[])
{
    cout << "Current C++ standard no. = " << __cplusplus << endl;
    cout << "Current program is " << sizeof(void*) * 8 << "-bit" << endl;
    cout << "\n" << endl;

    assign_to_rvalue();

    cout << "\n" << std::endl;

    test_unperfect_forward();

    cout << "================================== Moveable performance testing ==================================" << endl;
    cout << "\nvector container: " << std::endl;
    test_moveable(std::vector<MyString>(), 3000000L);
    cout << "\nlist container: " << std::endl;
    test_moveable(std::list<MyString>(), 3000000L);
    cout << "\ndeque container: " << std::endl;
    test_moveable(std::deque<MyString>(), 3000000L);
    cout << "\nmultiset container: " << std::endl;
    test_moveable(std::multiset<MyString>(), 3000000L);
    cout << "\n" << endl;

    cout << "================================== NonMoveable performance testing ==================================" << endl;
    cout << "\nvector container: " << std::endl;
    test_nonmoveable(std::vector<MyStringNoMove>(), 3000000L);
    cout << "\nlist container: " << std::endl;
    test_nonmoveable(std::list<MyStringNoMove>(), 3000000L);
    cout << "\ndeque container: " << std::endl;
    test_nonmoveable(std::deque<MyStringNoMove>(), 3000000L);
    cout << "\nmultiset container: " << std::endl;
    test_nonmoveable(std::multiset<MyStringNoMove>(), 3000000L);
    cout << "\n" << endl;

    return 0;
}
