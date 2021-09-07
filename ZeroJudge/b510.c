/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <stdio.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int m, n, col[10] = {0}, qa[19] = {0}, qb[19] = {0}, ra[19] = {0}, rb[19] = {0};

int backtrack(int q, int r)
{
    if (!q && !r)
        return 1;
    int i = m + n - q - r, y = 0;
    if (r)
        for (int j = 0; j < m + n; j++)
        {
            if (col[j] || qa[i - j + m + n - 1] || qb[i + j])
                continue;
            col[j] = 1;
            ++ra[i - j + m + n - 1];
            ++rb[i + j];
            y += backtrack(q, r - 1);
            col[j] = 0;
            --ra[i - j + m + n - 1];
            --rb[i + j];
        }
    if (q)
        for (int j = 0; j < m + n; j++)
        {
            if (col[j] || qa[i - j + m + n - 1] || qb[i + j] || ra[i - j + m + n - 1] || rb[i + j])
                continue;
            col[j] = 1;
            ++qa[i - j + m + n - 1];
            ++qb[i + j];
            y += backtrack(q - 1, r);
            col[j] = 0;
            --qa[i - j + m + n - 1];
            --qb[i + j];
        }
    return y;
}

int main()
{
    while (~scanf("%d%d", &m, &n))
    {
        memset(col, 0, sizeof(col));
        memset(qa, 0, sizeof(qa));
        memset(qb, 0, sizeof(qb));
        memset(ra, 0, sizeof(ra));
        memset(rb, 0, sizeof(rb));
        printf("%d\n", backtrack(m, n));
    }
    return 0;
}