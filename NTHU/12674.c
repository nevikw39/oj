/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

void inline static swap(int *l, int *r)
{
    *l ^= *r ^= *l ^= *r;
}

int inline static min(int l, int r)
{
    return r ^ ((l ^ r) & -(l < r));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a > b)
            swap(&a, &b);
        if (b > c)
            swap(&b, &c);
        if (a > b)
            swap(&a, &b);
        if (a + b < c)
            printf("%d\n", a + b);
        else
            printf("%d\n", c + min(a, a + b - c >> 1));
    }
    return 0;
}