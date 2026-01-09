/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
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

void solve()
{
    int cnt = 0, sum = 0, a4;
    int64_t total = 0;
    for (int i = 0, a; i < 9; i++)
    {
        scanf("%d", &a);
        if (a)
        {
            total += a;
            ++cnt;
            sum += i;
        }
        if (i == 4)
            a4 = a;
    }
    if (cnt == 2 && sum == 8)
        puts("1");
    else if (a4 - 1 > total - a4)
        printf("%d\n", (a4 << 1) - 1 - total);
    else
        puts("0");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
