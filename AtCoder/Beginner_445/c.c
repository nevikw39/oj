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
    int n;
    scanf("%d", &n);
    int dp[n][64];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", i[dp]);
        --*i[dp];
    }
    for (int j = 1; j < 64; j++)
        for (int i = 0; i < n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    for (int i = 0; i < n; i++)
        printf("%d ", dp[i][63] + 1);
    putchar('\n');
    return 0;
}
