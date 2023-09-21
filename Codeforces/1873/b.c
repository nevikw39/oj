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

void solve()
{
    int n, prod = 1, zero = 0, r = 0;
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    for (int *ptr = a; ptr < a + n; ptr++)
    {
        scanf("%d", ptr);
        if (*ptr)
            prod *= *ptr;
        else
            ++zero;
    }
    if (zero >= 1)
    {
        printf("%d\n", zero == 1 ? prod : 0);
        return;
    }
    for (int *ptr = a; ptr < a + n; ptr++)
        r = bwmax(r, prod / *ptr * (*ptr + 1));
    printf("%d\n", r);
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
