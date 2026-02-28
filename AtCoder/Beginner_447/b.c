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
    char s[101];
    scanf("%100s", s);
    int arr[26] = {}, mx = 0;
    for (char *c = s; *c; c++)
        if (mx < ++arr[*c - 'a'])
            mx = arr[*c - 'a'];
    for (char *c = s; *c; c++)
        if (mx != arr[*c - 'a'])
            putchar(*c);
    putchar('\n');
    return 0;
}
