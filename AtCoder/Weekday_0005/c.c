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
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        i[b] = i[a];
    }
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1] - k)
            a[i] = a[i - 1] - k;
    for (int i = n - 1; i; i--)
        if (a[i - 1] < a[i] - k)
            a[i - 1] = a[i] - k;
    int64_t sum = 0;
    for (int i = 0; i < n; i++)
        sum += i[a] - i[b];
    printf("%" PRId64 "\n", sum);
    return 0;
}
