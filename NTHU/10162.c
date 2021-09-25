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
    int m, n, p;
    scanf("%d%d", &m, &n);
    int **a = malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        i[a] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            scanf("%d", i[a] + j);
    }
    scanf("%d%d", &n, &p);
    int **b = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        i[b] = malloc(sizeof(int) * p);
        for (int j = 0; j < p; j++)
            scanf("%d", i[b] + j);
    }
    int **c = malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        i[c] = malloc(sizeof(int) * p);
        for (int j = 0; j < p; j++)
            c[i][j] = 0;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
            printf("%d ", c[i][j]);
        putchar_unlocked('\n');
    }
    return 0;
}