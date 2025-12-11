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

int64_t query(char c, int l, int r)
{
    printf("%c %d %d\n", c, l, r);
    fflush(stdout);
    int64_t sum;
    scanf("%" PRId64 "d", &sum);
    return sum;
}

void solve()
{
    int n;
    scanf("%d", &n);
    int l = 0;
    for (int jump = 1 << 31 - __builtin_clz(n); jump; jump >>= 1)
        if (l + jump < n && query('2', 1, l + jump) == query('1', 1, l + jump))
            l += jump;
    ++l;
    const int d = query('2', 1, n) - (n * (n + 1LL) >> 1);
    printf("! %d %d\n", l, l + d - 1);
    fflush(stdout);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
