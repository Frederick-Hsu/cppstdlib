#ifndef CUSTOMER_HASH_HPP
#define CUSTOMER_HASH_HPP

    #include <cstddef>
    #include <string>

    class CustomerHash;
    class Customer;

    class CustomerHash
    {
    public:
        size_t operator()(const Customer& obj) const noexcept;
    };

    class Customer
    {
        friend class CustomerHash;
    private:
        std::string m_fname;
        std::string m_lname;
        int m_age;
        float m_salary;
    public:
        Customer();
        Customer(const char* fname, const char* lname, int age, float salary);
    };

    void how_to_calculate_your_hash_code(void);

#endif  /* CUSTOMER_HASH_HPP */
