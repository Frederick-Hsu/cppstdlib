/* File name    : sharedptr.cpp
 * Description  : Study the shared_ptr, and figure out how to use it.
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>


int main(void)
{
    /* two shared pointers representing 2 persons by their names */
    std::shared_ptr<std::string> pNico(new std::string("nico"));
    // std::shared_ptr<std::string> pJutta(new std::string("jutta"));
    std::shared_ptr<std::string> pJutta{new std::string("jutta")};
    std::shared_ptr<std::string> pFrederique = std::make_shared<std::string>("Frederique");

    std::shared_ptr<std::string> pAlice;
    pAlice.reset(new std::string("Alice"),
                 [](std::string* p)
                 {
                        std::cout << "delete " << *p << std::endl;
                        delete p;
                 });

    /* Capitalize person names */
    (*pNico)[0] = 'N';
    pJutta->replace(0, 1, "J");

    /* Put them multiple times in a container */
    std::vector<std::shared_ptr<std::string>> whoMakeCoffee;
    whoMakeCoffee.push_back(pJutta);
    whoMakeCoffee.push_back(pJutta);
    whoMakeCoffee.push_back(pAlice);
    whoMakeCoffee.push_back(pNico);
    whoMakeCoffee.push_back(pFrederique);
    whoMakeCoffee.push_back(pJutta);
    whoMakeCoffee.push_back(pNico);
    whoMakeCoffee.push_back(pFrederique);

    /* Print out all elements */
    for (auto ptr : whoMakeCoffee)
    {
        std::cout << *ptr << ",\t";
    }
    std::cout << "\n" << std::endl;

    /* overwrite a name again */
    *pNico = "Nicolas";

    /* print out all elements once again */
    for (auto ptr : whoMakeCoffee)
    {
        std::cout << *ptr << ",\t";
    }
    std::cout << "\n" << std::endl;

    /* Print out the use_count */
    std::cout << "use_count = " << whoMakeCoffee[0].use_count() << std::endl;

    pAlice = nullptr;
    whoMakeCoffee.resize(2);

    /* Dealing with arrays */
    std::shared_ptr<int> pArray(new int[10],
                                [] (int* p)
                                {
                                    delete[] p;
                                });
    std::shared_ptr<int> pIntArray(new int[5], std::default_delete<int[]>());
    std::unique_ptr<int[]> pUniqueArray(new int[10]);
    std::shared_ptr<int[]> pSharedArray(new int[10]);

    /* for unique_ptr<>, you have to specify a second argument to specify your own deleter. */
    std::unique_ptr<int, void (*)(int*)> myptr(new int[25], [](int* p){ delete[] p; });

    return 0;
}
