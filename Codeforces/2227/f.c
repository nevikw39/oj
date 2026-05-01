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

static inline int64_t bwmax(int64_t l, int64_t r) { return l ^ ((l ^ r) & -(l < r)); }

void solve()
{
    int n;
    scanf("%d\n", &n);
    int a[n];
    int64_t suf[n], sum = 0, mx = 0;
    memset(suf, 0, sizeof(int64_t) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        ++suf[i[a] - 1];
    }
    for (int i = n - 2; ~i; i--)
        suf[i] += suf[i + 1];
    for (int i = 0; i < n; i++)
    {
        sum += (i[suf] * ((n << 1) - i[suf] + 1) >> 1) - i[a] * (i + 1LL);
        mx = bwmax(mx, i - n + suf[i[a] - 1]);
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
