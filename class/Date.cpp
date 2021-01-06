#include "Date.hpp"

Date Date::default_date(1, Month(1), 2021);

void Date::set_default(int d, Month m, int y)
{
    Date::default_date = Date(d, m, y);
}

Date::Date(int d, Month m, int y)
{
    if (y == 0)
        m_year = default_date.m_year;
    if (m == 0)
        m_month = default_date.m_month;
    if (d == 0)
        m_day = default_date.m_day;

    int max;
    switch (m)
    {
    case FEB:
        max = 28 + leapyear(y);
        break;
    case APR:
    case JUN:
    case SEP:
    case NOV:
        max = 30;
        break;
    case JAN:
    case MAR:
    case MAY:
    case JUL:
    case AUG:
    case OCT:
    case DEC:
        max = 31;
        break;
    default:
        throw Bad_date();
    }
    if ((d < 1) || (d > max))
    {
        throw Bad_date();
    }
    m_year = y;
    m_month = m;
    m_day = d;
}

int Date::day() const
{
    return m_day;
}

Date::Month Date::month() const
{
    return Month(m_month);
}

int Date::year() const
{
    return m_year;
}

Date& Date::add_year(int n)
{
    if ((m_day == 29) && (m_month == 2) && !leapyear(m_year+n))
    {
        m_day = 1;
        m_month = 3;
    }
    m_year += n;
    return *this;
}

Date& Date::add_month(int n)
{
    if (n == 0)
        return *this;
    if (n > 0)
    {
        int delta_year = n / 12;
        int mon = m_month + n % 12;
        if (mon > 12)
        {
            delta_year++;
            mon -= 12;
        }
        m_year += delta_year;
        m_month = Month(mon);
        return *this;
    }
    else    // n <= 0
    {
        return *this;
    }
}

std::string Date::string_rep() const
{
#if defined (LAZY_EVALUATION)
    if (!c->valid)
    {
        compute_cache_value();
        c->valid = true;
    }
    return c->rep;
#else
    if (!cache_valid)
    {
        compute_cache_value();
        cache_valid = true;
    }
    return cache;
#endif
}

bool leapyear(int year)
{
    return ((year % 4) == 0);
}

void Date::compute_cache_value() const
{
}

bool operator==(Date a, Date b)
{
    return (a.day() == b.day()) && (a.month() == b.month()) && (a.year() == b.year());
}

bool operator!=(Date a, Date b)
{
    return !(a == b);
}