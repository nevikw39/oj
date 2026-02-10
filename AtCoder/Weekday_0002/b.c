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
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int a[n], cnt = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int64_t sum = 0;
    while (m--)
    {
        int b;
        scanf("%d", &b);
        --b;
        if (b[a] < k)
        {
            ++cnt;
            sum += b[a];
        }
    }
    printf("%d %" PRId64 "\n", cnt, sum);
    return 0;
}
