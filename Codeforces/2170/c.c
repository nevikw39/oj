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

static inline void shuffle(int *arr, int n)
{
    for (int i = n - 1; i; i--)
    {
        const int j = rand() % (i + 1), tmp = j[arr];
        j[arr] = i[arr];
        i[arr] = tmp;
    }
}

int cmp_lt(const void *restrict lhs, const void *restrict rhs) { return *(const int *)lhs - *(const int *)rhs; }
int cmp_gt(const void *restrict lhs, const void *restrict rhs) { return -cmp_lt(lhs, rhs); }

void solve()
{
    int n;
    int64_t k;
    scanf("%d%" SCNd64, &n, &k);
    int q[n], r[n], cnt = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", q + i);
    for (int i = 0; i < n; i++)
        scanf("%d", r + i);
    shuffle(q, n);
    qsort(q, n, sizeof(int), cmp_gt);
    shuffle(r, n);
    qsort(r, n, sizeof(int), cmp_lt);
    for (int *ptr = q, *qtr = r; ptr < q + n && qtr < r + n; ptr++)
        if ((*ptr + 1LL) * (*qtr + 1) <= k + 1)
        {
            ++cnt;
            ++qtr;
        }
    printf("%d\n", cnt);
}

int main()
{
    srand(time(NULL));
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
