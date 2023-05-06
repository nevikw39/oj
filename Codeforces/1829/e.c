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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int n, m, a[1000][1000];

int dfs(int i, int j)
{
    static const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
    int y = a[i][j];
    a[i][j] = 0;
    for (int k = 0; k < 4; k++)
        if (0 <= i + di[k] && i + di[k] < n && 0 <= j + dj[k] && j + dj[k] < m && a[i + di[k]][j + dj[k]])
            y += dfs(i + di[k], j + dj[k]);
    return y;
}

void solve()
{
    int r = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j])
                r = bwmax(r, dfs(i, j));
    printf("%d\n", r);
}

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
        solve();
    return 0;
}
