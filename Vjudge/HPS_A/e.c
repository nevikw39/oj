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

int main()
{
    char master[101], driven[101];
    while (~scanf("%s%s", master, driven))
    {
        int l1 = strlen(master), l2 = strlen(driven), r, i, j;
        for (i = 0, j = 0; i < l1; i++)
        {
            for (j = 0; j < l2 && i + j < l1; j++)
                if (master[i + j] == '2' && driven[j] == '2')
                    break;
            if (j == l2 || i + j == l1)
                break;
        }
        r = j;
        for (i = 0, j = 0; i < l2; i++)
        {
            for (j = 0; j < l1 && i + j < l2; j++)
                if (master[j] == '2' && driven[i + j] == '2')
                    break;
            if (j == l1 || i + j == l2)
                break;
        }
        printf("%d\n", l1 + l2 - (r > j ? r : j));
    }
    return 0;
}