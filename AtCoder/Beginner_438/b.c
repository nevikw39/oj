/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
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
    char s[101], t[101];
    scanf("%d%d%s%s", &n, &m, s, t);
    int mn = INT_MAX;
    for (int i = 0; i <= n - m; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
            sum += (s[i + j] - t[j] + 10) % 10;
        if (mn > sum)
            mn = sum;
    }
    printf("%d\n", mn);
    return 0;
}
