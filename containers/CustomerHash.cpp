#include "CustomerHash.hpp"
#include "universal_hash_function.hpp"

#include <iostream>

Customer::Customer()
{
}

Customer::Customer(const char* fname, const char* lname, int age, float salary)
    : m_fname(fname), m_lname(lname), m_age(age), m_salary(salary)
{
}

size_t CustomerHash::operator()(const Customer &obj) const noexcept
{
    return MyContainers::hash_val(obj.m_fname, obj.m_lname, obj.m_age, obj.m_salary);
}

void how_to_calculate_your_hash_code(void)
{
    Customer client("Frederique", "Hsu", 37, 28500.50);
    size_t hashcode = CustomerHash()(client);

    std::cout << "The customer hash code = " << hashcode << std::endl;
}
