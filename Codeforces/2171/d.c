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
#include <stddef.h>
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
inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

void solve()
{
    int n;
    scanf("%d", &n);
    int p[n], pre_mn[n], suf_mx[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", i + p);
        i[pre_mn] = i[p];
        if (i)
            i[pre_mn] = bwmin(i[pre_mn], pre_mn[i - 1]);
    }
    for (int i = n - 1; ~i; i--)
    {
        i[suf_mx] = i[p];
        if (n - i > 1)
            i[suf_mx] = bwmax(i[suf_mx], suf_mx[i + 1]);
    }
    for (int i = 1; i < n; i++)
        if (pre_mn[i - 1] > i[suf_mx])
        {
            puts("No");
            return;
        }
    puts("Yes");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
