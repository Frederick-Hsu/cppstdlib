#ifndef UNPERFECT_FORWARDING_HPP
#define UNPERFECT_FORWARDING_HPP

    /* process(int) 将与 process(int&), process(int&&) 构成歧义。
     *
     * int a = 1;
     * process(a);      // ambiguous, unknow whether to call 'process(int)' or 'process(int&)'
     *
     * process(5);      // since constant and temporary variable are regarded as Rvalue,
     *                  // ambiguous, unknow whether to call 'process(int)' or 'process(int&&)'
     *
    void process(int i);    // so, cannot overload the 3 functions simultaneously : process(int); process(int&); process(int&&);
     *
     */

    void process(int& i);
    void process(int&& i);

    void forward(int&& i);

    void test_unperfect_forward(void);

#endif  /* UNPERFECT_FORWARDING_HPP */
