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
    int n, dash = 0, underscore = 0;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        const char s = getchar();
        if (s == '-')
            ++dash;
        else // if (s == '_')
            ++underscore;
        // else
        //     assert(false);
    }
    getchar();
    printf("%" PRId64 "\n", INT64_C(1) * (dash >> 1) * underscore * (dash - (dash >> 1)));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
