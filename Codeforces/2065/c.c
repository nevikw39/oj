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

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    assert(m == 1);
    int a[n], b;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    scanf("%d", &b);
    *a = bwmin(*a, b - *a);
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i] && a[i - 1] > b - a[i])
        {
            puts("no");
            return;
        }
        if (a[i - 1] > a[i])
            a[i] = b - a[i];
        else if (a[i - 1] <= b - a[i])
            a[i] = bwmin(a[i], b - a[i]);
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
