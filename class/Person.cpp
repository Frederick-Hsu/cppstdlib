#include "Person.hpp"

Person::Person(const std::string& name, const std::string& addr) : name(name)
{
    address = addr;
}

Person::Person(const Person& per) : name(per.name), address(per.address)
{
}