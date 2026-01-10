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
    int arr[200] = {}, n;
    scanf("%d", &n);
    for (int i = 0, t; i < n; i++)
    {
        scanf("%d", &t);
        arr[t - 1] = i + 1;
    }
    for (int i = 0, cnt = 0; cnt < 3; i++)
    {
        assert(i < 200);
        if (i[arr])
        {
            printf("%d ", i[arr]);
            ++cnt;
        }
    }
    putchar_unlocked('\n');
    return 0;
}
