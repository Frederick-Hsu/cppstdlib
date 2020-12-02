#include "Functor.hpp"

#include <iostream>

Functor::Functor(int id) : m_id(id)
{
}

void Functor::operator()()
{
    std::cout << "My Functor id: " << m_id << std::endl;
    ++m_id;
}

void Functor::setId(int userid)
{
    m_id = userid;
}

void test_functor(void)
{
    Functor functor;
    functor();

    functor.setId(10);
    functor();
}
