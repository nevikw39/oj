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

inline int64_t bwmax(int64_t l, int64_t r) { return l ^ ((l ^ r) & -(l < r)); }

int n, w, a[20], b[20];

int64_t f(int i, int64_t d, int64_t v)
{
    if (i == n)
        return d;
    int64_t y = f(i + 1, d, v);
    if (v + i[b] <= w)
        y = bwmax(y, f(i + 1, d + i[a], v + i[b]));
    return y;
}

int main()
{
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++)
        scanf("%d%d", a + i, b + i);
    printf("%" PRId64 "\n", f(0, 0, 0));
    return 0;
}
