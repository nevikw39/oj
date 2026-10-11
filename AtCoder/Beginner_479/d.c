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

inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int l[n], r[n], pre_mn_r[n], suf_mn_l[n];
    for (int *ptr = l + 1; ptr < l + n; ptr++)
        scanf("%d", ptr);
    for (int *ptr = r; ptr + 1 < r + n; ptr++)
        scanf("%d", ptr);
    *pre_mn_r = *r;
    for (int i = 1; i < n; i++)
        pre_mn_r[i] = bwmin(pre_mn_r[i - 1], i[r]);
    suf_mn_l[n - 1] = l[n - 1];
    for (int i = n - 2; ~i; i--)
        suf_mn_l[i] = bwmin(suf_mn_l[i + 1], i[l]);
    while (q--)
    {
        int s, t;
        scanf("%d%d", &s, &t);
        if (--s < --t)
        {
            int d = s[r];
            if (s)
                d = bwmin(d, s[l] + pre_mn_r[s - 1]);
            printf("%d\n", d);
        }
        else
        {
            int d = s[l];
            if (n - s > 1)
                d = bwmin(d, s[r] + suf_mn_l[s + 1]);
            printf("%d\n", d);
        }
    }
    return 0;
}
