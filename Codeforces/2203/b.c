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
    char x[20];
    scanf("%19s", x);
    int sum = 0, arr[10] = {}, *ptr = arr + 9, cnt = 0;
    for (char *c = x; *c; c++)
    {
        sum += *c - '0';
        assert(*c != '0' || c != x);
        ++arr[*c - '0' - (c == x)];
    }
    while (sum > 9)
    {
        while (!*ptr && ptr > arr)
            --ptr;
        assert(ptr > arr && *ptr);
        sum -= ptr - arr;
        --*ptr;
        ++cnt;
    }
    printf("%d\n", cnt);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
