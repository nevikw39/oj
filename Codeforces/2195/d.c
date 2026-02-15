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
    int n;
    scanf("%d", &n);
    int64_t f[n];
    for (int i = 0; i < n; i++)
        scanf("%" SCNd64, f + i);
    const int64_t s = (*f + f[n - 1]) / (n - 1);
    printf("%" PRId64 " ", s - *f + 1[f] >> 1);
    for (int i = 1; i < n - 1; i++)
        printf("%" PRId64 " ", f[i - 1] - (i[f] << 1) + f[i + 1] >> 1);
    printf("%" PRId64 "\n", f[n - 2] - f[n - 1] + s >> 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
