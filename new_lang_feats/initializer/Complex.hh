#ifndef COMPLEX_HH
#define COMPLEX_HH

    #define IMPLICIT        1
    #define EXPLICIT        2
    #define CONVERSION      EXPLICIT

    struct Complex
    {
        int real;
        int imag;

#if (CONVERSION == IMPLICIT)
        Complex(int re, int im = 0);
#elif (CONVERSION == EXPLICIT)
        explicit Complex(int re, int im = 0);
#endif
        Complex operator+(const Complex& x);
    };

    void test_Complex(void);

/*================================================================================================*/

namespace MySTL
{
    template<typename ElemType> struct complex;

    template<typename ElemType> struct complex
    {
        typedef ElemType value_type;
        complex(const ElemType& real = ElemType(), const ElemType& imag = ElemType());
        template<typename Type> complex(const complex<Type>& rhs);

        ElemType real() const;
        ElemType imag() const;
        ElemType real();
        ElemType imag();
    private:
        ElemType _M_real;
        ElemType _M_imag;
    };

    template<typename ElemType>
    complex<ElemType>::complex(const ElemType& real, const ElemType& imag)
        : _M_real(real), _M_imag(imag)
    {
    }

    template<typename ElemType> template<typename Type>
    complex<ElemType>::complex(const complex<Type>& rhs)
        : _M_real(rhs.real()), _M_imag(rhs.imag())
    {
    }

    template<typename ElemType> ElemType complex<ElemType>::real() const
    {
        return _M_real;
    }

    template<typename ElemType> ElemType complex<ElemType>::imag() const
    {
        return _M_imag;
    }

    template<typename ElemType> ElemType complex<ElemType>::real()
    {
        return _M_real;
    }

    template<typename ElemType> ElemType complex<ElemType>::imag()
    {
        return _M_imag;
    }
}

    void test_mystl_complex(void);

#endif  /* COMPLEX_HH */
