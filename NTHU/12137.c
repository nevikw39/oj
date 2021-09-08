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
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int n, k, *a;

int recur(int x, int s)
{
    if (x == n)
        return s == k;
    return recur(x + 1, s) + recur(x + 1, s + x[a]);
}

int main()
{
    scanf("%d%d", &n, &k);
    a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("%d\n", recur(0, 0));
    free(a);
    return 0;
}