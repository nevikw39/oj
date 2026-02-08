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
    int n;
    scanf("%d", &n);
    char s[101][101];
    for (int i = 0; i < n; i++)
        scanf("%100s", s[i]);
    char diag[(100 << 1) - 1] = {};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] != '?')
            {
                if (!diag[i + j])
                    diag[i + j] = s[i][j];
                else if (diag[i + j] != s[i][j])
                {
                    puts("-1");
                    return 0;
                }
            }
    for (char *ptr = diag; ptr < diag + (n << 1) - 1; ptr++)
        if (!*ptr)
            *ptr = '0';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (s[i][j] == '?')
                s[i][j] = diag[i + j];
        puts(s[i]);
    }
    return 0;
}
