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
    int n, m, w[15], c[15];
    static bool dp[2][1 << 15] = {};
    static int64_t sum[1 << 15] = {};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", w + i);
    for (int i = 0; i < m; i++)
        scanf("%d", c + i);
    for (int s = 0; s < 1 << n; s++)
        for (int i = 0; i < n; i++)
            if (s & (1 << i))
                s[sum] += i[w];
    dp[0][0] = true;
    const int u = (1 << n) - 1;
    for (int i = 0; i < m; i++)
        for (int s = 0; s < 1 << n; s++)
            if (dp[i & 1][s])
            {
                const int sp = u ^ s;
                for (int ss = sp; ss; ss = (ss - 1) & sp)
                    if (ss[sum] <= i[c])
                        dp[~i & 1][s | ss] = true;
            }
    puts(dp[m & 1][u] ? "Yes" : "No");
    return 0;
}
