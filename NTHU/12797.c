/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int inline static min(int l, int r)
{
    return r ^ ((l ^ r) & -(l < r));
}

int inline static max(int l, int r)
{
    return l ^ ((l ^ r) & -(l < r));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c, d, mn, mx;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (b - a > c - b)
        {
            mx = b - a;
            mn = c - b;
        }
        else
        {
            mn = b - a;
            mx = c - b;
        }
        int64_t r = 0;
        for (int i = 0; i <= mn; i++)
            r += max(0, (i + 1) * (min(d + 1, a + b + i) - c));
        for (int i = mn + 1; i <= mx; i++)
            r += max(0, (mn + 1) * (min(d + 1, a + b + i) - c));
        for (int i = mx + 1; i <= mx + mn; i++)
            r += max(0, (mx + mn + 1 - i) * (min(d + 1, a + b + i) - c));
        printf("%" PRId64 "\n", r);
    }
    return 0;
}