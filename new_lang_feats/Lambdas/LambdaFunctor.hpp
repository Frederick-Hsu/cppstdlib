#ifndef LAMBDA_FUNCTOR_HPP
#define LAMBDA_FUNCTOR_HPP

    class LambdaFunctor;

    class LambdaFunctor
    {
    public:
        LambdaFunctor(int lower, int upper);
        bool operator()(int n) const;
    private:
        int m_lower;
        int m_upper;
    };

    void apply_lambda_as_compare_predicate(void);

#endif  /* LAMBDA_FUNCTOR_HPP */
