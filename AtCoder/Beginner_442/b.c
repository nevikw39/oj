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
    int q, vol = 0;
    bool playing = false;
    scanf("%d\n", &q);
    while (q--)
    {
        const char a = getchar();
        getchar();
        switch (a)
        {
        case '1':
            ++vol;
            break;
        case '2':
            if (vol)
                --vol;
            break;
        default:
            playing = !playing;
        }
        puts(vol >= 3 && playing ? "Yes" : "No");
    }
    return 0;
}
