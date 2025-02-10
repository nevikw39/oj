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

#define N ((int)2e5 + 2)

int lpf[N], primes[17984], *tail = primes;

void sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (!lpf[i])
        {
            lpf[i] = i;
            *tail++ = i;
        }
        for (int *ptr = primes; ptr != tail && *ptr <= lpf[i] && i * *ptr < N; ptr++)
            lpf[i * *ptr] = *ptr;
    }
}

void solve()
{
    int n;
    scanf("%d", &n);
    int ctr[n + 1];
    memset(ctr, 0, sizeof(int) * (n + 1));
    for (int i = 0, a; i < n; i++)
    {
        scanf("%d", &a);
        ++ctr[a];
    }
    int64_t sum = 0, cnt = 0;
    for (int i = 2; i <= n; i++)
        if (lpf[i] == i)
        {
            sum += ctr[i] * cnt;
            cnt += ctr[i];
        }
        else if (lpf[i / lpf[i]] == i / lpf[i])
        {
            int64_t c = ctr[i];
            sum += c * (c + 1) >> 1;
            sum += c * ctr[lpf[i]];
            if (lpf[i] != i / lpf[i])
                sum += c * ctr[i / lpf[i]];
        }
    printf("%" PRId64 "\n", sum);
}

int main()
{
    sieve();
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
