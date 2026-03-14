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
    int h, w, q;
    scanf("%d%d%d\n", &h, &w, &q);
    while (q--)
    {
        char c;
        int x;
        scanf("%c %d\n", &c, &x);
        if (c == '1')
        {
            printf("%d\n", x * w);
            h -= x;
        }
        else
        {
            printf("%d\n", x * h);
            w -= x;
        }
    }
    return 0;
}
