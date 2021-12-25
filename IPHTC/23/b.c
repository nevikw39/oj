/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

static inline int min(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

static inline int max(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q, a = 0;
        scanf("%d%d", &n, &q);
        int l[n], r[n], arr[n + 1];
        memset(arr, 0, sizeof(int) * (n + 1));
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", l + i, r + i);
            for (int j = l[i]; j <= r[i]; j++)
                ++arr[j];
        }
        for (int i = 0; i < q; i++)
        {
            for (int j = l[i]; j <= r[i]; j++)
                --arr[j];
            int sum = 0, ps[n + 1], cnt = INT_MAX;
            for (int j = 1; j <= n; j++)
                if (arr[j])
                    ++sum;
            *ps = 0;
            for (int j = 1; j <= n; j++)
                ps[j] = ps[j - 1] + (arr[j] == 1);
            for (int j = 0; j < q; j++)
                if (i != j)
                    cnt = min(cnt, ps[r[j]] - ps[l[j] - 1]);
            a = max(a, sum - cnt);
            for (int j = l[i]; j <= r[i]; j++)
                ++arr[j];
        }
        printf("%d\n", a);
    }
    return 0;
}
