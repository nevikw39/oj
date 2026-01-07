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

inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }
inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

void solve()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    const int a = k - 1, b = n - k;
    int res = 1;
    for (int r = 0; r <= b; r++)
    {
        const int l = bwmin(bwmin(a, r), m + 1 - (r << 1));
        if (l >= 0)
            res = bwmax(res, 1 + r + l);
    }
    for (int l = 0; l <= a; l++)
    {
        const int r = bwmin(bwmin(b, l), m + 1 - (l << 1));
        if (r >= 0)
            res = bwmax(res, 1 + l + r);
    }
    printf("%d\n", res);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
