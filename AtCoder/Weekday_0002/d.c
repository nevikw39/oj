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
    int n, m;
    scanf("%d%d", &n, &m);
    int c[n], r[m];
    for (int i = 0; i < n; i++)
        scanf("%d", c + i);
    for (int i = 0; i < m; i++)
        scanf("%d", r + i);
    qsort(c, n, sizeof(int), cmp);
    qsort(r, m, sizeof(int), cmp);
    int cnt = 0, *ptr = c, *qtr = r;
    while (ptr < c + n && qtr < r + m)
    {
        if (*ptr <= *qtr)
        {
            ++cnt;
            ++ptr;
        }
        ++qtr;
    }
    printf("%d\n", cnt);
    return 0;
}
