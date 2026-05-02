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
    int cnt = 1;
    int64_t sum = 0;
    for (const char *c = s + 1; *c; c++)
        if (*c == *(c - 1))
        {
            sum += cnt * (cnt + 1LL) >> 1;
            sum %= 998244353;
            cnt = 1;
        }
        else
            ++cnt;
    printf("%" PRId64 "\n", (sum + (cnt * (cnt + 1LL) >> 1)) % 998244353);
    return 0;
}
