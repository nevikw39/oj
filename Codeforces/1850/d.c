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

int cmp(const int *const l, const int *const r) { return *l - *r; }

void solve()
{
    int n, k, *a, r = 1;
    scanf("%d%d", &n, &k);
    a = calloc(n, sizeof(int));
    for (int *ptr = a; ptr < a + n; ptr++)
        scanf("%d", ptr);
    qsort(a, n, sizeof(int), cmp);
    for (int *ptr = a + 1, cnt = 1; ptr < a + n; ptr++)
        if (*ptr - (-1)[ptr] <= k)
            r = bwmax(r, ++cnt);
        else
            cnt = 1;
    printf("%d\n", n - r);
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
