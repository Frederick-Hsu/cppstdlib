#ifndef TABLE_HH
#define TABLE_HH

    #include <cstddef>

    class Name
    {
    private:
        char* str;
    public:
        Name(const char* name = nullptr);
        Name(const Name& other);
        Name& operator=(const Name& other);
        ~Name();
    private:
        Name(Name&&) = delete;
        Name& operator=(Name&&) = delete;
    };

    class Table
    {
    private:
        Name* p;
        size_t sz;
    public:
        Table(size_t s = 15);
        Table(const Table& other);
        Table& operator=(const Table& other);
        Table(Table&& other);
        Table& operator=(Table&& other);
        ~Table();
    public:
        Name* lookup(const char* s);
        bool insert(Name* pname);
    };


#endif  /* TABLE_HH */