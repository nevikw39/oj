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

static inline int64_t gcd(int64_t a, int64_t b)
{
    while (b)
    {
        const int64_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}

static inline int64_t f(int64_t x, int64_t y, int64_t z) { return (x - y + z) * 6 + (y - (z << 1)) * 3 + (z << 1); }

void solve()
{
    int a, b, c;
    int64_t m;
    scanf("%d%d%d%" SCNd64, &a, &b, &c, &m);
    const int64_t ab = a / gcd(a, b) * b, bc = b / gcd(b, c) * c, ca = c / gcd(c, a) * a, abc = ab / gcd(ab, c) * c;
    printf("%" PRId64 " %" PRId64 " %" PRId64 "\n", f(m / a, m / ab + m / ca, m / abc), f(m / b, m / ab + m / bc, m / abc), f(m / c, m / bc + m / ca, m / abc));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
