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

double f(double x, __int128_t n)
{
    if (x == 0 || x == 1 || x == -1 && (n & 1) || n == 1)
        return x;
    if (x == -1 && (~n & 1))
        return -x;
    if (n < 0)
        return 1 / f(x, -n);
    double y = 1;
    for (; n; n >>= 1, x *= x)
        if (n & 1)
            y *= x;
    return y;
}

double myPow(double x, int n) { return f(x, n); }
