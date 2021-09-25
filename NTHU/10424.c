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
    int **m = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        m[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            scanf("%d", m[i] + j);
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            int p = 0;
            for (int x = 0; x < 3; x++)
                for (int y = 0; y < 3; y++)
                    p = p > m[i + x][j + y] ? p : m[i + x][j + y];
            printf("%3d", p);
        }
        putchar_unlocked('\n');
    }
    return 0;
}