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

int inline static max(int l, int r)
{
    return l ^ ((l ^ r) & -(l < r));
}

int inline static min(int l, int r)
{
    return r ^ ((l ^ r) & -(l < r));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q, *l, *r, *arr, a = 0;
        scanf("%d%d", &n, &q);
        l = malloc(sizeof(int) * q);
        r = malloc(sizeof(int) * q);
        arr = malloc(sizeof(int) * (n + 1));
        memset(arr, 0, sizeof(int) * (n + 1));
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", l + i, r + i);
            for (int j = i[l]; j <= i[r]; j++)
                ++j[arr];
        }
        for (int i = 0; i < q; i++)
        {
            for (int j = i[l]; j <= i[r]; j++)
                --j[arr];
            int sum = 0, *ps = malloc(sizeof(int) * (n + 1)), cnt = INT_MAX;
            for (int j = 1; j <= n; j++)
                if (j[arr])
                    ++sum;
            *ps = 0;
            for (int j = 1; j <= n; j++)
                j[ps] = ps[j - 1] + (j[arr] == 1);
            for (int j = 0; j < q; j++)
                if (j != i)
                    cnt = min(cnt, ps[r[j]] - ps[l[j] - 1]);
            a = max(a, sum - cnt);
            for (int j = i[l]; j <= i[r]; j++)
                ++j[arr];
            free(ps);
        }
        printf("%d\n", a);
        free(l);
        free(r);
        free(arr);
    }
    return 0;
}