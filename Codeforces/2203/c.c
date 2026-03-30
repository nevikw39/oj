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

bool f(int64_t n, int64_t s, int64_t m)
{
    for (int k = 60; ~k; k--)
        if (m & (1LL << k))
            s -= (n < s >> k ? n : s >> k) << k;
    return !s;
}

void solve()
{
    int64_t s, m;
    scanf("%" SCNd64 "%" SCNd64, &s, &m);
    const int64_t lowbit = m & -m;
    if (s && !m || s % lowbit)
    {
        puts("-1");
        return;
    }
    int64_t n = (s + m - 1) / m - 1;
    for (int k = 60; ~k; k--)
        if (n + (1LL << k) < s / lowbit && !f(n + (1LL << k), s, m))
            n += 1LL << k;
    printf("%" PRId64 "\n", n + 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
