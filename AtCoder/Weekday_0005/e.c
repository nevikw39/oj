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

inline int _log2(int x) { return 31 - __builtin_clz(x); }
inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int st[n][_log2(n) + 1]; // sparse table
    for (int i = 0; i < n; i++)
        scanf("%d", i[st]);
    for (int j = 1; j <= _log2(n); j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = bwmax(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        const int x = _log2(r - l + 1);
        printf("%d\n", bwmax(st[l][x], st[r - (1 << x) + 1][x]));
    }
    return 0;
}
