/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <stdio.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int n, col[14] = {0}, a[27] = {0}, b[27] = {0};

int backtrack(int q)
{
    if (!q)
        return 1;
    int i = n - q, y = 0;
    for (int j = 0; j < n; j++)
    {
        if (col[j] || a[i - j + n - 1] || b[i + j])
            continue;
        col[j] = 1;
        ++a[i - j + n - 1];
        ++b[i + j];
        y += backtrack(q - 1);
        col[j] = 0;
        --a[i - j + n - 1];
        --b[i + j];
    }
    return y;
}

int main()
{
    scanf("%d", &n);
    printf("%d\n", backtrack(n));
    return 0;
}