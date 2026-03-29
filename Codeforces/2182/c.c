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

static inline int f(int n, const int *const restrict x, const int *const restrict y)
{
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
        bool flag = true;
        for (int i = 0; i < n && flag; i++)
            if (x[i] >= y[(i + j) % n])
                flag = false;
        if (flag)
            ++cnt;
    }
    return cnt;
}

void solve()
{
    int n;
    scanf("%d", &n);
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);
    for (int i = 0; i < n; i++)
        scanf("%d", c + i);
    printf("%" PRId64 "\n", 1LL * n * f(n, a, b) * f(n, b, c));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
