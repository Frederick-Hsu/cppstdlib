#include "Zoo.hpp"

Zoo::Zoo(int i1, int i2) : d1(i1), d2(i2)
{
}

Zoo::~Zoo()
{
}

void test_ctor_default_delete(void)
{
    Foo f1(5);      /* Foo(int i)表示用户已经定义构造函数，编译器提供的默认构造函数将被屏蔽掉 */
    Foo f2;         /* 如果没有定义 Foo() = default; 则不能调用编译器提供的默认构造函数 */
    Foo f3(f1);     /* 如果定义了 Foo(const Foo&) = delete; 表明删除copy ctor, 则此句就会出错 */
    f3 = f2;        /* 若定义了 Foo& operator=(const Foo&) = delete; 表明弃用编译器提供的赋值构造函数，则词句就会出错 */
}
