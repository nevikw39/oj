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
    int n, m;
    scanf("%d%d", &n, &m);
    int c[m], d[m], sum = 0;
    memset(d, 0, sizeof(int) * m);
    for (int i = 0; i < m; i++)
        scanf("%d", c + i);
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        d[a - 1] += b;
    }
    for (int i = 0; i < m; i++)
        if (i[c] < i[d])
            sum += i[c];
        else
            sum += i[d];
    printf("%d\n", sum);
    return 0;
}
