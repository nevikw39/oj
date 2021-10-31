/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int64_t ps[n + 1];
    *ps = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        ps[i] = ps[i - 1] + (a > 0 ? a : 0);
    }
    while (q--)
    {
        int l, r, m;
        scanf("%d%d%d", &l, &r, &m);
        printf("%" PRId64 "\n", ps[l + m - 1] - ps[l - 1]);
    }
    return 0;
}
