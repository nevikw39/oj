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
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

const int M = 1e9 + 7;

void matrix_multiple(int64_t a[3][3], int64_t b[3][3], int64_t c[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            c[i][j] = 0;
    for (int k = 0; k < 3; k++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % M) % M;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int64_t n, m[3][3] = {{1, 2, 1}, {1, 0, 0}, {0, 1, 0}}, v[3] = {13, 12, 1}, base[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, tmp[3][3];
        scanf("%" SCNd64, &n);
        if (n <= 3)
        {
            printf("%" PRId64 "\n", v[3 - n]);
            continue;
        }
        n -= 3;
        while (n)
        {
            if (n & 1)
            {
                matrix_multiple(base, m, tmp);
                memcpy(base, tmp, sizeof(m));
            }
            matrix_multiple(m, m, tmp);
            memcpy(m, tmp, sizeof(m));
            n >>= 1;
        }
        printf("%" PRId64 "\n", (base[0][0] * v[0] % M + base[0][1] * v[1] % M + base[0][2] * v[2] % M) % M);
    }
    return 0;
}