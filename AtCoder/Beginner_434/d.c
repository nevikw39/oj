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

#define N 2002

int main()
{
    static int a[N][N], b[N][N];
    int n, not_covered = 0;
    scanf("%d", &n);
    int exclusively_covered[n] = {};
    for (int i = 0, u, d, l, r; i < n; i++)
    {
        scanf("%d%d%d%d", &u, &d, &l, &r);
        ++d;
        ++r;
        ++a[u][l];
        --a[u][r];
        --a[d][l];
        ++a[d][r];
        b[u][l] += i;
        b[u][r] -= i;
        b[d][l] -= i;
        b[d][r] += i;
    }
    for (int i = 0; i < N; i++)
        for (int j = 1; j < N; j++)
        {
            a[i][j] += a[i][j - 1];
            b[i][j] += b[i][j - 1];
        }
    for (int i = 1; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            a[i][j] += a[i - 1][j];
            b[i][j] += b[i - 1][j];
        }
    for (int i = 1; i < 2001; i++)
        for (int j = 1; j < 2001; j++)
            if (!a[i][j])
                ++not_covered;
            else if (a[i][j] == 1)
                ++exclusively_covered[b[i][j]];
    for (const int *ptr = exclusively_covered; n--; ptr++)
        printf("%d\n", not_covered + *ptr);
    return 0;
}
