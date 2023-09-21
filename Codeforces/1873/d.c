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
    int n, k = 1, r = 0;
    scanf("%d%d", &n, &k);
    char *s = malloc(sizeof(char) * (n + 1));
    scanf("%s", s);
    for (char *ptr = s; *ptr;)
        if (*ptr != 'B')
            ++ptr;
        else
        {
            ++r;
            for (int i = 0; i < k && *ptr; i++)
                ++ptr;
        }
    printf("%d\n", r);
    free(s);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
