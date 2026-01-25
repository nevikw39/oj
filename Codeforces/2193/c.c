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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

void solve()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);
    a[n - 1] = bwmax(a[n - 1], b[n - 1]);
    for (int i = n - 2; i >= 0; i--)
        a[i] = bwmax(a[i], bwmax(a[i + 1], b[i]));
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d ", l == 1 ? a[r - 1] : a[r - 1] - a[l - 2]);
    }
    putchar('\n');
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
