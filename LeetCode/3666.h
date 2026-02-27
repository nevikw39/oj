/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }
inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }
inline int div_ceil(int x, int y) { return (x + y - 1) / y; }

int minOperations(char *s, int k)
{
    int n = 0, zeros = 0;
    while (*s)
    {
        if (*s++ == '0')
            ++zeros;
        ++n;
    }
    if (!zeros)
        return 0;
    if (n == k)
        return (n == zeros) - (n != zeros);
    int odd = bwmax(div_ceil(zeros, k), div_ceil(n - zeros, n - k)), even = bwmax(div_ceil(zeros, k), div_ceil(zeros, n - k));
    if (~odd & 1)
        ++odd;
    if (even & 1)
        ++even;
    int y = INT_MAX;
    if (~(k ^ zeros) & 1)
        y = bwmin(y, odd);
    if (~zeros & 1)
        y = bwmin(y, even);
    return y != INT_MAX ? y : -1;
}
