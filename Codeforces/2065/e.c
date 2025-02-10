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

void solve()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    char a = '0', b = '1';
    if (n < m)
    {
        n ^= m ^= n ^= m;
        a ^= b ^= a ^= b;
    }
    if (k < n - m || k > n)
    {
        puts("-1");
        return;
    }
    n -= k;
    while (k--)
        putchar(a);
    m -= n;
    while (n--)
    {
        putchar(b);
        putchar(a);
    }
    while (m--)
        putchar(b);
    putchar('\n');
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
