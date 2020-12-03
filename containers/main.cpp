#include <iostream>
#include <functional>

#include "hash_function.hpp"

#include "apply_tuple/apply_tuple.hpp"

using namespace std;

int main()
{
    cout << "Current C++ standard no. = " << __cplusplus << endl;
    cout << "Current program is " << sizeof(void*) * 8 << "-bit." << endl;


    void* pi = (void*)(new int(100));
    cout << MyContainers::hash<int>()(123) << endl
         << MyContainers::hash<long>()(123L) << endl
         << hash<string>()(string("Alice Yu")) << endl
         << hash<const char*>()("Alice Yu") << endl
         << hash<char>()('A') << endl
         << hash<float>()(3.141592653) << endl
         << hash<double>()(3.141592653) << endl
         << hash<void*>()(pi) << endl;

    /*
    cout << MyContainers::hash<const char*>()("kiwi") << endl
         << MyContainers::hash<const char*>()("plum") << endl
         << MyContainers::hash<const char*>()("apple") << endl;
     */

    std::cout << "\nApplying tuple..." << std::endl;
    apply_tuple();
    return 0;
}
