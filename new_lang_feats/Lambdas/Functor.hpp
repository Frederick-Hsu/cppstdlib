#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP

    class Functor;

    class Functor
    {
    private:
        int m_id;
    public:
        Functor(int id = 0);
        void operator()();
        void setId(int userid);
    };

    void test_functor(void);

#endif  /* FUNCTOR_HPP */
