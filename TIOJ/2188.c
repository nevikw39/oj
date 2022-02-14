/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int main()
{
    int n = 0;
    char c;
    while (~(c = getchar_unlocked()))
        if (isdigit(c))
            n = n * 10 + c - '0';
        else if (!n)
            putchar_unlocked(c);
        else
        {
            while (n--)
                putchar_unlocked(c);
            n = 0;
        }
    putchar_unlocked('\n');
    return 0;
}