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

static inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

void solve()
{
    int n;
    char s0[200001], s1[200001];
    scanf("%d%200000s%200000s", &n, s0, s1);
    int d = 0, p = *s0 != *s1;
    for (int i = 1; i < n; i++)
    {
        const int dp = bwmin(d + (s0[i] != s0[i - 1]) + (s1[i] != s1[i - 1]), p + (s0[i] != s1[i]));
        d = p;
        p = dp;
    }
    printf("%d\n", p);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
