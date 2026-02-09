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

int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    int p[n], x = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
        if (l <= i[p] && i[p] <= r && (!~x || x[p] < i[p]))
            x = i;
    }
    printf("%d\n", ~x ? x + 1 : -1);
    return 0;
}
