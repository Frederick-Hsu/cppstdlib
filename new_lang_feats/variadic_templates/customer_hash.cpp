#include "customer_hash.h"
#include "hash_val.h"

Customer::Customer(const char* firstname, const char* lastname, unsigned number)
    : fname(firstname), lname(lastname), no(number)
{
}

std::size_t CustomerHash::operator()(const Customer &c) const
{
    return hash_val(c.fname, c.lname, c.no);
}
