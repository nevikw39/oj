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
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

#ifndef __SIZEOF_FLOAT128__
#define __float128 long double
#endif

__int128_t power(__int128_t x, __int128_t n)
{
    __int128_t y = 1;
    for (; n; n >>= 1, x *= x)
        if (n & 1)
            y *= x;
    return y;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int64_t n, r = -1;
        scanf("%" SCNd64, &n);
        for (int i = 0; i < 64; i++)
        {
            __int128_t a = 0, p = power(2, i);
            for (int64_t jump = n >> 1; jump; jump >>= 1)
                while (a + jump < n && (a + jump) * p - (a + jump) + (a + jump) * (a + jump - 1) / 2 < n)
                    a += jump;
            ++a;
            if (!(a & 1))
                continue;
            if (a * p - a + a * (a - 1) / 2 == n)
            {
                r = a * p;
                break;
            }
        }
        printf("%" PRId64 "\n", r);
    }
    return 0;
}