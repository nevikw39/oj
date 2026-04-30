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

static inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

static inline int f(const int *const restrict a, int n, int x, bool even)
{
    bool freq[n];
    memset(freq, 0, sizeof(bool) * n);
    for (int l = x, r = x + even; ~l && r < n << 1 && a[l] == a[r]; l--, r++)
        freq[l[a]] = freq[r[a]] = true;
    int mex = 0;
    while (mex < n && freq[mex])
        ++mex;
    return mex;
}

void solve()
{
    int n;
    scanf("%d\n", &n);
    int a[n << 1], zero0 = -1, zero1 = -1;
    for (int i = 0; i < n << 1; i++)
    {
        scanf("%d", a + i);
        if (!i[a])
        {
            if (!~zero0)
                zero0 = i;
            else
                zero1 = i;
        }
    }
    int mex = bwmax(f(a, n, zero0, false), f(a, n, zero1, false));
    mex = bwmax(mex, f(a, n, (zero0 & zero1) + ((zero0 ^ zero1) >> 1), zero1 - zero0 & 1));
    printf("%d\n", mex);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
