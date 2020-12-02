#ifndef DECLTYPE_H
#define DECLTYPE_H

    #include <map>
    #include <string>

    void GetTypeOfObject(void);

    template<typename T1, typename T2> auto add(T1 x, T2 y) -> decltype(x+y);

    template<typename T> void Test_DeclType(T container);

    class Person
    {
    private:
        std::string m_firstname;
        std::string m_lastname;
    public:
        Person(std::string firstname, std::string lastname) : m_firstname(firstname), m_lastname(lastname) {}
        Person(const Person& rhs) : m_firstname(rhs.m_firstname), m_lastname(rhs.m_lastname) {}
        Person& operator=(const Person& rhs)
        {
            m_firstname = rhs.m_firstname;
            m_lastname = rhs.m_lastname;
            return *this;
        }
        std::string firstname() const { return m_firstname; }
        std::string lastname()  const { return m_lastname;  }
        std::string firstname()       { return m_firstname; }
        std::string lastname()        { return m_lastname;  }
    };

    void apply_decltype_to_pass_lambda_type(void);

/*================================================================================================*/

    template<typename T> void Test_DeclType(T container)
    {
        std::map<std::string, float>::value_type elem;
        std::map<std::string, float> collection;
        decltype(collection)::value_type elem2;

        typedef typename decltype(container)::iterator iType;
        using IterType = typename decltype(container)::iterator;

        decltype(container) anotherObj(container);
    }

#endif  /* DECLTYPE_H */
