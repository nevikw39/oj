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

inline int _log2(int64_t x) { return 63 - __builtin_clzl(x); }

int n, k, *a;

bool f(int64_t x)
{
    if (!x)
        return true;
    int64_t sum = 0;
    int cnt = 0;
    for (int *ptr = a; ptr < a + n && cnt < k; ptr++)
        if ((sum += *ptr) >= x)
        {
            sum = 0;
            ++cnt;
        }
    return cnt >= k;
}

int main()
{
    scanf("%d%d", &n, &k);
    a = malloc(sizeof(int) * n);
    int64_t sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        sum += i[a];
    }
    int64_t x = 0;
    for (int64_t jump = 1LL << _log2(sum); jump; jump >>= 1)
        if ((x | jump) <= sum && f(x | jump))
            x |= jump;
    printf("%" PRId64 "\n", x);
    free(a);
    return 0;
}
