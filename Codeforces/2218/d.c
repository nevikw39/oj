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

#define N (120000)

bool sieved[N];
int primes[10000], *tail = primes;

void sieve()
{
    for (int i = 2; tail < primes + 10000; i++)
    {
        if (!sieved[i])
            *tail++ = i;
        for (int *ptr = primes; ptr != tail && i * *ptr < N; ptr++)
        {
            sieved[i * *ptr] = true;
            if (!(i % *ptr))
                break;
        }
    }
}

void solve()
{
    int n;
    scanf("%d", &n);
    putchar('1');
    for (int i = 1; i < n; i++)
        printf(" %" PRId64, 1LL * primes[i - 1] * primes[i]);
    putchar('\n');
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
