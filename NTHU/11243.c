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
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int main()
{
    int n;
    scanf("%d", &n);
    int **t = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        t[i] = malloc(sizeof(int *) * (i + 1));
        for (int j = 0; j <= i; j++)
            scanf("%d", t[i] + j);
    }
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            t[i][j] += t[i + 1][j] > t[i + 1][j + 1] ? t[i + 1][j] : t[i + 1][j + 1];
    printf("%d\n", **t);
    return 0;
}