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

#define N (50)
#define MOD (998244353)

int f[N + 1], rf[N + 1];

static inline int binexp(int64_t x, int n)
{
    int64_t y = 1;
    for (x %= MOD; n; x *= x, x %= MOD, n >>= 1)
        if (n & 1)
            y *= x, y %= MOD;
    return y;
}

static inline int inv(int x) { return binexp(x, MOD - 2); }

void solve()
{
    int n;
    scanf("%d", &n);
    int a[n + 1], sum = 0, cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", a + i);
        sum += i[a];
    }
    const int q = sum / n + 1, r = sum % n;
    for (int i = 1; i <= n; i++)
        if (i[a] > q || i[a] == q && ++cnt > r)
        {
            puts("0");
            return;
        }
    printf("%d\n", 1LL * f[r] * rf[r - cnt] % MOD * f[n - cnt] % MOD);
}

int main()
{
    f[0] = rf[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        f[i] = 1LL * i * f[i - 1] % MOD;
        rf[i] = 1LL * inv(i) * rf[i - 1] % MOD;
    }
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
