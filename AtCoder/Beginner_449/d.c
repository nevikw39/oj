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

static inline int even(int l, int r)
{
    if (l & 1)
        ++l;
    if (r & 1)
        --r;
    return l <= r ? (r - l >> 1) + 1 : 0;
}

int main()
{
    int l, r, d, u;
    scanf("%d%d%d%dn", &l, &r, &d, &u);
    // sweeping line
    int64_t sum = 0;
    const int x_even = even(l, r);
    for (int y = d; y <= u; y++)
    {
        const int y_abs = abs(y),
                  intersect_l = l > -y_abs ? l : -y_abs,
                  intersect_r = r < y_abs ? r : y_abs,
                  intersect_even = even(intersect_l, intersect_r);
        sum += x_even - intersect_even;
        if (~y_abs & 1 && intersect_l <= intersect_r)
            sum += intersect_r - intersect_l + 1;
    }
    printf("%" PRId64 "\n", sum);
    return 0;
}
