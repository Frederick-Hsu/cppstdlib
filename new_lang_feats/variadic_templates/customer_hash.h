#ifndef CUSTOMER_HASH_H
#define CUSTOMER_HASH_H

    #include <iostream>
    #include <string>

    class CustomerHash;
    class Customer;

    class Customer
    {
        friend class CustomerHash;
    private:
        std::string fname;
        std::string lname;
        unsigned no;
    public:
        Customer(const char* firstname, const char* lastname, unsigned number);
    };

    class CustomerHash
    {
    public:
        std::size_t operator()(const Customer& c) const;
    };

#endif  /* CUSTOMER_HASH_H */
