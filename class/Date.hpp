#ifndef DATE_HPP
#define DATE_HPP

    #include <string>
    #include <iostream>

    #define LAZY_EVALUATION     1

    #if defined (LAZY_EVALUATION)
        struct cache
        {
            bool valid;
            std::string rep;
        };
    #endif

    class Date
    {
    public:
        enum Month
        {
            JAN = 1,
            FEB,
            MAR,
            APR,
            MAY,
            JUN,
            JUL,
            AUG,
            SEP,
            OCT,
            NOV,
            DEC
        };
        class Bad_date
        {
        };
    private:
        int m_day;
        int m_month;
        int m_year;

        static Date default_date;
    #if defined (LAZY_EVALUATION)
        cache* c;
    #else
        mutable bool cache_valid;
        mutable std::string cache;
    #endif
    private:
        void compute_cache_value() const;
    public:
        Date(int d = 0, Month m = Month(0), int y = 0);
        Date(int d, Month m);
        Date(int d);
        Date();
        Date(const char* date);
        static void set_default(int d, Month m, int y);
        
        int day() const;
        Month month() const;
        int year() const;

        Date& add_year(int n);
        Date& add_month(int n);
        Date& add_day(int n);

        std::string string_rep() const;
        void char_rep(char s[]) const;
    };

    inline bool operator==(Date a, Date b);
    inline bool operator!=(Date a, Date b);
    inline bool operator< (Date a, Date b);
    inline bool operator> (Date a, Date b);

    Date& operator++(Date& d);
    Date& operator--(Date& d);
    Date& operator+=(Date& d, int n);
    Date& operator-=(Date& d, int n);
    Date  operator+ (Date  d, int n);
    Date  operator- (Date  d, int n);

    std::ostream& operator<<(std::ostream& out, Date d);
    std::istream& operator>>(std::istream& in,  Date d);


    int diff(Date a, Date b);
    bool leapyear(int year);

#endif  /* DATE_HPP */