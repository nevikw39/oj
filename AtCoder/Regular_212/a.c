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

#define MOD (998244353)

int main()
{
    int k, sum = 0;
    scanf("%d", &k);
    for (int x = 2; x < k; x++)
        for (int y = x; (y << 1) <= k - x; y++)
        {
            const int z = k - x - y;
            int fg = (k - z) * (z - 1LL) % MOD * (y - 1LL) % MOD * (x - 1LL) % MOD;
            if (x != y && y != z)
                fg = fg * 6LL % MOD;
            else if (x != y || y != z)
                fg = fg * 3LL % MOD;
            sum = (sum + fg) % MOD;
        }
    printf("%d\n", sum);
    return 0;
}
