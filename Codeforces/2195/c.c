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
    int n, dp[2][6];
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int j = 0; j < 6; j++)
        dp[0][j] = *a != j + 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < 6; j++)
        {
            dp[i & 1][j] = INT_MAX;
            const int c = i[a] != j + 1;
            for (int k = 0; k < 6; k++)
                if (j != k && j + k != 5 && dp[i & 1][j] > dp[~i & 1][k] + c)
                    dp[i & 1][j] = dp[~i & 1][k] + c;
        }
    int mn = INT_MAX;
    for (int j = 0; j < 6; j++)
        if (mn > dp[~n & 1][j])
            mn = dp[~n & 1][j];
    printf("%d\n", mn);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
