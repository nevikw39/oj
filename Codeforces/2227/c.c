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

int cmp(const void *const restrict lhs, const void *const restrict rhs)
{
    const int l = *(const int *const)lhs, r = *(const int *const)rhs;
    const bool l2 = !(l % 2), l3 = !(l % 3), r2 = !(r % 2), r3 = !(r % 3);
    const int l_key = (l2 && l3) ? 3 : (l3 ? 2 : !l2), r_key = (r2 && r3) ? 3 : (r3 ? 2 : !r2 ? 1 : 0);
    return l_key - r_key;
}

void solve()
{
    int n;
    scanf("%d\n", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    qsort(a, n, sizeof(int), cmp);
    for (int *ptr = a; ptr < a + n; ptr++)
        printf("%d ", *ptr);
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
