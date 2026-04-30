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
    scanf("%d\n", &n);
    int a[n], suf[n], freq[n];
    memset(freq, 0, sizeof(int) * n);
    int64_t sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        sum += i[a];
    }
    for (int i = n - 1, mn = n + 1; ~i; i--)
    {
        if (mn > i[a])
            mn = i[a];
        i[suf] = mn;
        sum -= mn;
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        ++freq[i[suf] - 1];
        if (mx < freq[i[a] - 1])
            mx = freq[i[a] - 1];
    }
    if (mx > 1)
        sum += mx - 1;
    printf("%" PRId64 "\n", sum);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
