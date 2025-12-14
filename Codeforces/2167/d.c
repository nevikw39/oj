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

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

void solve()
{
    int n;
    scanf("%d", &n);
    int64_t a[n];
    for (int i = 0; i < n; i++)
        scanf("%" PRId64 "d", a + i);
    for (int i = 0; i < 16; i++)
    {
        bool flag = false;
        for (int64_t *ptr = a; ptr < a + n && !flag; ptr++)
            if (*ptr % i[primes])
                flag = true;
        if (flag)
        {
            printf("%d\n", i[primes]);
            return;
        }
    }
    puts("-1");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
