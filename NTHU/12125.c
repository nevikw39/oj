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
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int *a = malloc(sizeof(int) * (n + 1));
    int64_t *ps = malloc(sizeof(int64_t) * (n + 1));
    0[a] = 0[ps] = 0;
    for (int i = 1; i <= n; i++)
    {
        char buf[8];
        scanf("%d%s%s", a + i, buf, buf);
        i[ps] = ps[i - 1] + i[a];
    }
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%" PRId64 "\n", r[ps] - ps[l - 1]);
    }
    free(a);
    free(ps);
    return 0;
}