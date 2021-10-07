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
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int main()
{
    char s[1001 + 1], p[1001];
    int q;
    while (~scanf("%s%s%d", s + 1, p, &q))
    {
        int ls = strlen(s + 1), lp = strlen(p), *ps = malloc(sizeof(int) * (ls - lp + 2)), r = *ps = 0;
        for (int i = 1; i <= ls - lp + 1; i++)
        {
            i[ps] = ps[i - 1];
            if (!strncmp(s + i, p, lp))
                ++i[ps];
        }
        while (q--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (b - lp + 1 >= a - 1 && r < ps[b - lp + 1] - ps[a - 1])
                r = ps[b - lp + 1] - ps[a - 1];
        }
        printf("%d\n", r);
    }
    return 0;
}
