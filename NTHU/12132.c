/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int n, *a, *ptr, *eaten;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n), ptr = a, eaten = malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    memset(eaten, 0, sizeof(int) * (n + 1));
    while (n--)
    {
        int b, w = 1;
        scanf("%d", &b);
        if (b[eaten])
        {
            printf(n ? "0 " : "0\n");
            continue;
        }
        while (b != *ptr)
        {
            eaten[*ptr++] = 1;
            ++w;
        }
        eaten[*ptr++] = 1;
        printf(n ? "%d " : "%d\n", w);
    }
    free(a);
    free(eaten);
    return 0;
}