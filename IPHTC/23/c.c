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

int cmp(int *l, int *r) { return *l - *r; }

int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, p, k, r = 0;
        scanf("%d%d%d", &n, &p, &k);
        int a[n + 1], ps[n + 1];
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        qsort(a + 1, n, sizeof(int), cmp);
        *ps = 0;
        for (int i = 1; i < k; i++)
            if ((ps[i] = ps[i - 1] + a[i]) <= p)
                r = i;
        for (int i = k; i <= n; i++)
            if ((ps[i] = ps[i - k] + a[i]) <= p)
                r = i;
        printf("%d\n", r);
    }
    return 0;
}
