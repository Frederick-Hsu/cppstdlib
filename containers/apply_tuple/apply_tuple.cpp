#include "apply_tuple.hpp"

#include <iostream>
#include <tuple>
#include <string>
#include <complex>

void apply_tuple(void)
{
    using namespace std;

    cout << "sizeof(string) = " << sizeof(string) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(float)  = " << sizeof(float) << endl;
    cout << "sizeof(int)    = " << sizeof(int) << endl;
    cout << "sizeof(complex<double>) = " << sizeof(complex<double>) << endl;

    /* Create a four-element tuple */
    tuple<string, int, int, complex<double>> tpl;
    cout << "sizeof(tpl) = " << sizeof(tpl) << endl;

    /* Create and initialize a tuple explicitly */
    tuple<int, float, string> mytpl(41, 6.3, "Alice Yu");
    cout << "sizeof(mytpl) = " << sizeof(mytpl) << endl;

    /* iterate over elements */
    cout << "mytpl: " << get<0>(mytpl) << ", " << get<1>(mytpl) << ", " << get<2>(mytpl) << endl;

    /* create tuple with make_tuple() */
    auto yourtpl = make_tuple(22, 44, "Frederique Hsu");

    get<1>(mytpl) = get<1>(yourtpl);    /* assign second value from yourtpl to mytpl */
    /* comparison and assignment */
    if (mytpl < yourtpl)
    {
        cout << "mytpl < yourtpl" << endl;
    }
    else
    {
        cout << "mytpl >= yourtpl" << endl;
    }
    mytpl = yourtpl;
    // cout << mytpl << endl;

    tuple<int, float, string> histpl(77, 1.1, "more light");
    int ielem;
    float felem;
    string strelem;
    tie(ielem, felem, strelem) = histpl;    /* assign values from histple to tie() tuple */

    /* meta programming */
    typedef tuple<int, float, string> TupleType;
    cout << tuple_size<TupleType>::value << endl;
    tuple_element<1, TupleType>::type farg = 5.25;
    // typedef tuple_element<1, TupleType>::tuple_element elem;
}
