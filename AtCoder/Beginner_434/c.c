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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }
inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

void solve()
{
    int n, h;
    scanf("%d%d", &n, &h);
    int cur = 0, hl = h, hu = h, t[n], l[n], u[n];
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", i + t, i + l, i + u);
    for (int i = 0; i < n; i++)
    {
        const int d = i[t] - cur;
        hl = bwmax(hl - d, i[l]);
        hu = bwmin(hu + d, i[u]);
        if (hl > hu)
        {
            puts("No");
            return;
        }
        cur = i[t];
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
