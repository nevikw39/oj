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
    int n, k;
    scanf("%d%d", &n, &k);
    int d[n], *ptr = d;
    int64_t sum = 0;
    for (int i = 0, a, b; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        i[d] = b - a;
        sum += a;
    }
    qsort(d, n, sizeof(int), cmp);
    while (k--)
        sum += *ptr++;
    printf("%" PRId64 "\n", sum);
    return 0;
}
