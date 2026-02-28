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
    char s[1000001];
    scanf("%1000000s", s);
    int a = 0, ab = 0, abc = 0;
    for (char *c = s; *c; c++)
        switch (*c)
        {
        case 'A':
            ++a;
            break;
        case 'B':
            if (a)
            {
                --a;
                ++ab;
            }
            break;
        default: // 'C
            if (ab)
            {
                --ab;
                ++abc;
            }
        }
    printf("%d\n", abc);
    return 0;
}
