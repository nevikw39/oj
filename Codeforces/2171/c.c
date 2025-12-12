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
    int n;
    scanf("%d", &n);
    int a[n], x = -1;
    for (int i = 0; i < n; i++)
        scanf("%d", i + a);
    bool tie = true;
    for (int i = 0, b; i < n; i++)
    {
        scanf("%d", &b);
        if (i[a] ^ b)
        {
            x = i;
            tie ^= 1;
        }
    }
    assert(tie || ~x);
    if (tie)
        puts("Tie");
    else if (x & 1)
        puts("Mai");
    else
        puts("Ajisai");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
