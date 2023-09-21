/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
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

int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int *a;

int64_t f(int n, int h)
{
    int64_t y = 0;
    for (int *ptr = a; ptr < a + n; ptr++)
        y += bwmax(h - *ptr, 0);
    return y;
}

void solve()
{
    int n, x, h = 0;
    scanf("%d%d", &n, &x);
    a = malloc(sizeof(int) * n);
    for (int *ptr = a; ptr < a + n; ptr++)
        scanf("%d", ptr);
    for (int64_t jump = INT_MAX >> 1; jump; jump >>= 1)
        while (h + jump <= INT_MAX && f(n, h + jump) <= x)
            h += jump;
    printf("%d\n", h);
    free(a);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
