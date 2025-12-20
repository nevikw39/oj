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

int main()
{
    int h, w, n, arr[90], mx = 0;
    memset(arr, -1, sizeof arr);
    scanf("%d%d%d", &h, &w, &n);
    int row[h];
    memset(row, 0, sizeof(int) * h);
    for (int i = 0; i < h; i++)
        for (int j = 0, a; j < w; j++)
        {
            scanf("%d", &a);
            arr[a - 1] = i;
        }
    while (n--)
    {
        int b;
        scanf("%d", &b);
        --b;
        if (~arr[b])
        {
            ++row[arr[b]];
            if (mx < row[arr[b]])
                mx = row[arr[b]];
        }
    }
    printf("%d\n", mx);
    return 0;
}
