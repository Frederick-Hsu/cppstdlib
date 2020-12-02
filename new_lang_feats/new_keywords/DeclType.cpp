#include "DeclType.h"

#include <iostream>
#include <set>
#include <typeinfo>

#define LINUX_CPP_TYPEOF    1
#define STD_CPP03_TYPEID    2
#define STD_CPP11_DECLTYPE  3

#define GET_TYPE_OF_OBJECT      STD_CPP11_DECLTYPE

void GetTypeOfObject(void)
{
    using name = std::string;
    using salary = float;
    std::map<name, salary> collection { {"Frederique Hsu", 28000},
                                        {"Gary Lee", 30000},
                                        {"Henry Xing", 58000.00}};

#if (GET_TYPE_OF_OBJECT == LINUX_CPP_TYPEOF)
    typeof(collection);
#elif (GET_TYPE_OF_OBJECT == STD_CPP03_TYPEID)
    std::cout << typeid(collection).name() << std::endl;
#elif (GET_TYPE_OF_OBJECT == STD_CPP11_DECLTYPE)
    decltype(collection)::value_type elem;
#endif
}

auto cmp = [](const Person& p1, const Person& p2)
{
    return (p1.lastname() < p2.lastname())   ||
           ((p1.lastname() == p2.lastname()) && (p1.firstname() < p2.firstname()));
};

void apply_decltype_to_pass_lambda_type(void)
{
    std::set<Person, decltype(cmp)> collection(cmp);
}
