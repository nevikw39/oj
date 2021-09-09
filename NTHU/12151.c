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
    int n, *row, *col;
    scanf("%d", &n);
    row = malloc(sizeof(int) * n);
    col = malloc(sizeof(int) * n);
    memset(row, 0, sizeof(int) * n);
    memset(col, 0x7f, sizeof(int) * n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int a;
            scanf("%d", &a);
            row[i] = row[i] > a ? row[i] : a;
            col[j] = col[j] < a ? col[j] : a;
        }
    for (int i = 0; i < n; i++)
        printf(i != n - 1 ? "%d " : "%d\n", i[row]);
    for (int j = 0; j < n; j++)
        printf(j != n - 1 ? "%d " : "%d\n", j[col]);
    free(row);
    free(col);
    return 0;
}