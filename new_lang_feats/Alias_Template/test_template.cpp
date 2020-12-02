#include "test_template.hpp"
#include "alias_template.hpp"

#include <list>
#include <string>
#include <deque>

static void apply_template_alias(void)
{
    Vec<int> odds {1, 3, 5, 7, 9, 11,13, 15};
}

void test_container_movable(void)
{
    // test_movable(std::list<std::string>());
    // test_movable(std::vector<std::string>());
    test_movable(std::deque<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100}));
}
