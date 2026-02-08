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

inline int64_t bwmax(int64_t l, int64_t r) { return l ^ ((l ^ r) & -(l < r)); }

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int64_t mx[n - 1], d[n];
    memset(mx, 0, sizeof(int64_t) * (n - 1));
    memset(d, 0, sizeof(int64_t) * n);
    while (q--)
    {
        int i, x;
        scanf("%d%d", &i, &x);
        --i;
        d[i] += x;
        if (n - i > 1)
            mx[i] = bwmax(mx[i], d[i] - d[i + 1]);
    }
    int64_t a = 1, sum = a;
    for (int64_t *ptr = mx; ptr < mx + n - 1; ptr++)
        sum += a += *ptr + 1;
    printf("%" PRId64 "\n", sum);
    return 0;
}
