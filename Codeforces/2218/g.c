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
    int n, m;
    scanf("%d%d", &n, &m);
    int b[n], ps[m], prod = 1;
    memset(ps, 0, sizeof(int) * m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", b + i);
        ++ps[i[b]];
    }
    for (int i = 1; i < m; i++)
        ps[i] += ps[i - 1];
    for (int i = 0; i < n; i++)
    {
        if (!i[b])
            continue;
        int mn = INT_MAX;
        if (i)
            mn = b[i - 1];
        if (n - i > 1 && mn > b[i + 1])
            mn = b[i + 1];
        if (mn >= i[b])
        {
            puts("0");
            return;
        }
        prod = 1LL * prod * (ps[i[b] - 1] - (i[b] >= 2 && i[b] - mn != 1 ? ps[i[b] - 2] : 0)) % 676767677;
    }
    printf("%d\n", prod);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
