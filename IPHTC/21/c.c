/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int inline static max(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int inline static min(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k, r = INT_MIN;
        scanf("%d%d%d", &n, &m, &k);
        int a[n];
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        k = min(k, m - 1);
        for (int i = 0; i <= k; i++)
        {
            int t = INT_MAX;
            for (int j = 0; j <= m - 1 - k; j++)
                t = min(t, max(a[i + j], a[n - m + i + j]));
            r = max(r, t);
        }
        printf("%d\n", r);
    }
    return 0;
}
