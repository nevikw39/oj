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

int inline bwabs(int x) { return (x ^ (x >> ((sizeof(int) << 3) - 1))) - (x >> ((sizeof(int) << 3) - 1)); }

int main()
{
    char s1 = getchar_unlocked(), s2 = getchar_unlocked();
    getchar_unlocked();
    char t1 = getchar_unlocked(), t2 = getchar_unlocked();
    if ((bwabs(s1 - s2) % 3 & 1) ^ (bwabs(t1 - t2) % 3 & 1))
        puts("No");
    else
        puts("Yes");
    return 0;
}
