/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

char x[1000001];

int main()
{
    while (scanf("%s", x) && strcmp(x, "END"))
    {
        int l = strlen(x);
        if (l == 1 && *x == '1')
        {
            puts("1");
            continue;
        }
        int i = 2;
        while (l != 1 + (int)log10(l))
        {
            l = 1 + (int)log10(l);
            ++i;
        }
        printf("%d\n", i);
    }
    return 0;
}