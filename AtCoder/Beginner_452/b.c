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
    int h, w;
    scanf("%d%d", &h, &w);
    for (int i = 0; i < w; i++)
        putchar('#');
    putchar('\n');
    for (int i = 2; i < h; i++)
    {
        putchar('#');
        for (int j = 2; j < w; j++)
            putchar('.');
        puts("#");
    }
    for (int i = 0; i < w; i++)
        putchar('#');
    putchar('\n');
    return 0;
}
