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

int cmp(const void *const l, const void *const r) { return *(int *)l - *(int *)r; }

int main()
{
    int n, k, t;
    scanf("%d%d%d", &n, &k, &t);
    int a[n], cur = 0, sum = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    qsort(a, n, sizeof *a, cmp);
    for (int *ptr = a; ptr < a + n; ptr++)
    {
        if (*ptr >= t)
            break;
        if (cur < *ptr)
            sum += (*ptr - cur + k - 1) / k;
        cur = *ptr + k;
    }
    if (cur < t)
        sum += (t - cur + k - 1) / k;
    printf("%d\n", sum);
    return 0;
}
