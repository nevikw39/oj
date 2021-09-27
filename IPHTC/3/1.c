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
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        int *arr = malloc(sizeof(int) * (n + 1)), l = 0, r = 0;
        int64_t *ps = malloc(sizeof(int64_t) * (n + 1)), v = 0;
        *arr = *ps = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", arr + i);
            i[ps] = i[arr] + ps[i - 1];
        }
        while (q--)
        {
            int a, b;
            int64_t s;
            scanf("%d%d", &a, &b);
            if (a <= b)
                s = ps[b] - ps[a - 1];
            else
                s = ps[n] - ps[a - 1] + ps[b];
            if (v < s)
            {
                v = s;
                l = a;
                r = b;
            }
        }
        printf("Max_range: (%d,%d); Value: %" PRId64 "\n", l, r, v);
    }
    return 0;
}