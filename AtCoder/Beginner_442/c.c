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
    int n, m;
    scanf("%d%d", &n, &m);
    int deg[n];
    memset(deg, 0, sizeof(int) * n);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        ++deg[a - 1];
        ++deg[b - 1];
    }
    for (int *ptr = deg; ptr < deg + n; ptr++)
    {
        const int x = n - *ptr - 1;
        printf("%lld ", (x * (x - 1LL) >> 1) * (x - 2LL) / 3);
    }
    putchar('\n');
    return 0;
}
