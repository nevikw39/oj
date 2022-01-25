/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

const int N = 1000001;

int main()
{
    int t, sieve[N], primes[N], cnt = 0;
    memset(sieve, 0, sizeof(sieve));
    sieve[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!sieve[i])
            primes[cnt++] = i;
        for (int j = 0; j < cnt && i * primes[j] < N; j++)
        {
            sieve[i * primes[j]] = 1;
            if (!(i % primes[j]))
                break;
        }
    }
    scanf("%d", &t);
    while (t--)
    {
        int n, e;
        scanf("%d%d", &n, &e);
        int a[n], ps1[n], ps2[n];
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        memset(ps1, 0, n * sizeof(int));
        memset(ps2, 0, n * sizeof(int));
        for (int i = 0; i < n; i++)
            if (i >= e && a[i - e] == 1)
                ps1[i] = ps1[i - e] + 1;
        for (int i = n - 1; i >= 0; i--)
            if (i < n - e && a[i + e] == 1)
                ps2[i] = ps2[i + e] + 1;
        int64_t r = 0;
        for (int i = 0; i < n; i++)
            if (!sieve[a[i]])
                r += (ps1[i] + 1LL) * (ps2[i] + 1LL) - 1;
        printf("%" PRId64 "\n", r);
    }
    return 0;
}