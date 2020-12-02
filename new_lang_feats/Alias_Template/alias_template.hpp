#ifndef ALIAS_TEMPLATE_HPP
#define ALIAS_TEMPLATE_HPP

    #include <vector>

    template<typename T> using Vec = std::vector<T>;

    template<typename T> void output_static_date(const T& obj);
    template<class Container> void test_movable(Container contnr);

    template<typename T> struct Container
    {
        using value_type = T;       /* identical to "typedef T value_type;" */
        Container();
    private:
        value_type element;
    };

    #include "alias_template.cpp"

#endif  /* ALIAS_TEMPLATE_HPP */
