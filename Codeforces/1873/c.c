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

void solve()
{
    static int scores[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                                 {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
                                 {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
                                 {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
                                 {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
                                 {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
                                 {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
                                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    char grid[11][11];
    for (int i = 0; i < 10; i++)
        scanf("%s", grid[i]);
    int r = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (grid[i][j] == 'X')
                r += scores[i][j];
    printf("%d\n", r);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
