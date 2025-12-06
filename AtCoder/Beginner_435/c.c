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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }
inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int main()
{
    int n, mx = 0;
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++)
    {
        if (i > mx)
            break;
        scanf("%d", &a);
        mx = bwmax(mx, i + a - 1);
    }
    printf("%d\n", bwmin(mx + 1, n));
    return 0;
}
