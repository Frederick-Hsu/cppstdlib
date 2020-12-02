#include "Complex.hh"

#include <iostream>

Complex::Complex(int re, int im) : real(re), imag(im)
{
}

Complex Complex::operator+(const Complex &x)
{
    return Complex((real + x.real), (imag + x.imag));
}

void test_Complex(void)
{
    Complex c1(12, 5);
#if (CONVERSION == IMPLICIT)
    /* with explicit, the implicit conversion from 5 to Complex(5, 0) will occur */
    Complex c2 = c1 + 5;
#elif (CONVERSION == EXPLICIT)
    /* explicit will prevent the conversion from 5 to Complex(5, 0) */
    Complex c2 = c1 + Complex(5);
#endif
}

void test_mystl_complex(void)
{
    MySTL::complex<int> unitComplex(1, 1);
    MySTL::complex<double> zeroComplex;

    std::cout << "unit complex = " << unitComplex.real() << " + " << unitComplex.imag() << "i" << std::endl;
    std::cout << "zero complex = " << zeroComplex.real() << " + " << zeroComplex.imag() << "i" << std::endl;

    MySTL::complex<long> bigComplex(unitComplex);
}
