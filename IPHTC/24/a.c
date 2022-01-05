/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

static inline void swap(int *l, int *r) { *l ^= *r ^= *l ^= *r; }

static inline int min(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int r, g, b;
        scanf("%d%d%d", &r, &g, &b);
        if (r > g)
            swap(&r, &g);
        if (g > b)
            swap(&g, &b);
        if (r > g)
            swap(&r, &g);
        if (r + g < b)
            printf("%d\n", r + g);
        else
            printf("%d\n", b + min(r, r + g - b >> 1));
    }
    return 0;
}
