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
    int x, y;
    scanf("%d%d", &x, &y);
    const int n = x + y;
    const bool even = ~n & 1;
    if (even && !x || !even && !y || x > n >> 1)
    {
        puts("no");
        return;
    }
    puts("yes");
    int cur = 2;
    for (int i = even; i < x; i++)
    {
        printf("1 %d\n%d %d\n", cur, cur, cur + 1);
        cur += 2;
    }
    while (cur <= n)
        printf("1 %d\n", cur++);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
