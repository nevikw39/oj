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
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

const int M = 1e9 + 7;

void matrix_mutiple(int64_t a[2][2], int64_t b[2][2])
{
    int64_t c[2][2];
    memset(c, 0, sizeof(c));
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % M) % M;
    memcpy(a, c, sizeof(c));
}

int main()
{
    int64_t i;
    while (~scanf("%" SCNd64, &i))
    {
        int64_t B[2][2] = {{1, 1}, {1, 0}}, I[2][2] = {{1, 0}, {0, 1}};
        for (; i; i >>= 1, matrix_mutiple(B, B))
            if (i & 1)
                matrix_mutiple(I, B);
        printf("%" PRId64 "\n", I[0][1] % M);
    }
    return 0;
}
