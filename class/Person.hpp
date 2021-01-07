#ifndef PERSON_HPP
#define PERSON_HPP

    #include <string>

    class Person;

    class Person
    {
    private:
        std::string name;
        std::string address;
    public:
        Person(const Person&);
        Person(const std::string& name, const std::string& addr);
    };

#endif  /* PERSON_HPP */