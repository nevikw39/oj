/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/

#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

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

int inline bwavg(int l, int r) { return (l & r) + ((l ^ r) >> 1); }

int main()
{
    int n;
    scanf("%d", &n);
    int l = 1, r = n;
    while (r - l > 1)
    {
        int m = bwavg(l, r);
        printf("? %d\n", m);
        fflush(stdout);
        char s;
        do
            s = getchar();
        while (isspace(s));
        if (s == '0')
            l = m;
        else
            r = m;
    }
    printf("! %d\n", bwavg(l, r));
    fflush(stdout);
    return 0;
}
