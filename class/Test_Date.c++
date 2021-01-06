#include "Test_Date.h++"

#include "Date.hpp"

void represent_date_with_string(void)
{
    Date nationalDay(1, 10, 1949);
    const Date laborDay(1, 5, 2020);
    std::string strNationalDay = nationalDay.string_rep();
    std::string strLaborDay = laborDay.string_rep();
}