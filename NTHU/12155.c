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

int *p, *rk;

int find(int x)
{
    return p[x] == x ? x : (p[x] = find(p[x]));
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (rk[x] >= rk[y])
    {
        rk[x] += rk[y];
        p[y] = x;
    }
    else
    {
        rk[y] += rk[x];
        p[x] = y;
    }
}

int static inline square(int x)
{
    return x * x;
}

int main()
{
    int n, r, *x, *y, *v, bh = 0, remain = 0;
    scanf("%d%d", &n, &r);
    x = malloc(sizeof(int) * n);
    y = malloc(sizeof(int) * n);
    p = malloc(sizeof(int) * n);
    rk = malloc(sizeof(int) * n);
    v = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        rk[i] = 1;
        v[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", x + i, y + i);
        for (int j = 0; j < i; j++)
            if (square(x[i] - x[j]) + square(y[i] - y[j]) <= square(r))
                unite(i, j);
    }
    for (int i = 0; i < n; i++)
    {
        int pp = find(i);
        if (v[pp])
            continue;
        v[pp] = 1;
        if (rk[pp] == 1)
            ++remain;
        else
            ++bh;
    }
    printf("%d %d\n", remain, bh);
    free(x);
    free(y);
    free(p);
    free(rk);
    free(v);
    return 0;
}