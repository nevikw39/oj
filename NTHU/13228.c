/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <inttypes.h>
#include <limits.h>
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

static inline int64_t min(int64_t l, int64_t r) { return r ^ ((l ^ r) & -(l < r)); }

static inline int64_t max(int64_t l, int64_t r) { return l ^ ((l ^ r) & -(l < r)); }

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int64_t n = max(b + c + 1, d) + 1, arr[n], r = 0;
        memset(arr, 0, sizeof(int64_t) * n);
        for (int i = a; i <= b; i++)
        {
            ++arr[i + b];
            --arr[i + c + 1];
        }
        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];
        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];
        for (int i = c; i <= d; i++)
            r += arr[min((int)ceil(i * 3.0 / 2) - 1, n - 1)] - arr[i];
        printf("%" PRId64 "\n", r);
    }
    return 0;
}
