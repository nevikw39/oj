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

int main()
{
    int n, m, k, cnt = 0;
    scanf("%d%d%d", &n, &m, &k);
    int s[n];
    for (int i = 0; i < n; i++)
        scanf("%d", s + i);
    while (m--)
    {
        int p, v;
        scanf("%d%d", &p, &v);
        s[p - 1] = v;
    }
    for (int *ptr = s; ptr < s + n; ptr++)
        if (*ptr < k)
            ++cnt;
    printf("%d\n", cnt);
    return 0;
}
