/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <stdio.h>
#include <stdlib.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int inline static max(int l, int r)
{
    return l ^ ((l ^ r) & -(l < r));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k, *a, *head, *tail;
        scanf("%d%d%d", &n, &m, &k);
        a = malloc(sizeof(int) * n);
        head = a, tail = a + n - 1;
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        for (int i = 0; i < m - 1; i++)
            if (i < k && *head < *tail || i >= k && *head > *tail)
                ++head;
            else
                --tail;
        printf("%d\n", max(*head, *tail));
        free(a);
    }
    return 0;
}