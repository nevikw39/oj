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

int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int cmp(const int *const restrict l, const int *const restrict r) { return *l - *r; }

int *lbound(const int *const restrict b, const int m, const int a)
{
    int *y = b - 1;
    for (int jump = m; jump; jump >>= 1)
        while (y + jump < b + m && *(y + jump) < a)
            y += jump;
    return y + 1;
}

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < m; i++)
        scanf("%d", b + i);
    qsort(b, m, sizeof(int), cmp);
    *a = bwmin(*a, *b - *a);
    for (int i = 1; i < n; i++)
    {
        int *ptr = lbound(b, m, a[i - 1] + a[i]);
        if (a[i - 1] > a[i] && ptr == b + m)
        {
            puts("no");
            return;
        }
        if (a[i - 1] > a[i])
            a[i] = *ptr - a[i];
        else if (ptr < b + m)
            a[i] = bwmin(a[i], *ptr - a[i]);
    }
    puts("yes");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
