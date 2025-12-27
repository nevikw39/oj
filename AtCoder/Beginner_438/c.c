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
    int n;
    scanf("%d", &n);
    int a[n], *ptr = a;
    while (n--)
    {
        int i;
        scanf("%d", &i);
        *ptr++ = i;
        while (ptr - a >= 4 && *(ptr - 4) == *(ptr - 3) && *(ptr - 3) == *(ptr - 2) && *(ptr - 2) == *(ptr - 1))
            ptr -= 4;
    }
    printf("%d\n", ptr - a);
    return 0;
}
