/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int cmp(const int *l, const int *r)
{
    if (*l < *r)
        return -1;
    if (*l == *r)
        return 0;
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, p, k, *a, *ps, r = 0;
        scanf("%d%d%d", &n, &p, &k);
        a = malloc(sizeof(int) * n);
        ps = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        qsort(a, n, sizeof(int), cmp);
        if ((0[ps] = 0[a]) <= p)
            r = 1;
        for (int i = 1; i < k - 1; i++)
            if ((i[ps] = ps[i - 1] + i[a]) <= p)
                r = i + 1;
        if ((ps[k - 1] = a[k - 1]) <= p)
            r = k;
        for (int i = k; i < n; i++)
            if ((i[ps] = ps[i - k] + i[a]) <= p)
                r = i + 1;
        printf("%d\n", r);
        free(a);
        free(ps);
    }
    return 0;
}