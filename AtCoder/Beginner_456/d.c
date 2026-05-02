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
    char s[300001];
    scanf("%300000s", s);
    int64_t dp[3] = {0, 0, 0};
    for (char *c = s; *c; c++)
    {
        const int i = *c - 'a';
        dp[i] += (dp[(i + 1) % 3] + dp[(i + 2) % 3] + 1) % 998244353;
        dp[i] %= 998244353;
    }
    printf("%" PRId64 "\n", (*dp + 1[dp] + 2[dp]) % 998244353);
    return 0;
}
