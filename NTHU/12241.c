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

void matrix_multiple(int64_t a[2][2], int64_t b[2][2], int64_t c[2][2])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            c[i][j] = 0;
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % M) % M;
}

int main()
{
    int64_t n;
    while (~scanf("%" SCNd64, &n))
    {
        int64_t m[2][2] = {{1, 1}, {1, 0}}, v[2] = {1, 1}, base[2][2] = {{1, 0}, {0, 1}}, tmp[2][2];
        if (n <= 2)
        {
            puts("1");
            continue;
        }
        n -= 2;
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
        printf("%" PRId64 "\n", (base[0][0] * v[0] % M + base[0][1] * v[1] % M) % M);
    }
    return 0;
}