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

inline int sgn(int x) { return (x > 0) - (x < 0); }

int main()
{
    int n, k, cnt = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0, a, ap; i < n; i++, ap = a)
    {
        scanf("%d", &a);
        if (!sgn(a - k))
            ++cnt;
        if (i && sgn(a - k) * sgn(ap - k) < 0)
            ++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}
