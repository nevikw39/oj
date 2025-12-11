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

void solve()
{
    int a, b, k = 0, x[101];
    scanf("%d%d", &a, &b);
    if (__builtin_clz(a) > __builtin_clz(b))
    {
        puts("-1");
        return;
    }
    b ^= a;
    for (int i = 1; b && k <= 100; i <<= 1, b >>= 1)
        if (b & 1)
            x[k++] = i;
    printf("%d\n", k);
    for (int *ptr = x; k--; ptr++)
        printf("%d ", *ptr);
    putchar('\n');
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
