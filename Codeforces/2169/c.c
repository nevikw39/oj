/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

void solve()
{
    int n;
    scanf("%d", &n);
    int64_t sum = 0, mn = 0, mx = 0;
    for (int i = 0, a; i < n; i++)
    {
        scanf("%d", &a);
        sum += a;
        const int64_t x = (i + 1LL) * (i + 2) - sum;
        if (mn > x)
            mn = x;
        if (mx < x - mn)
            mx = x - mn;
    }
    printf("%" PRId64 "\n", sum + mx);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
