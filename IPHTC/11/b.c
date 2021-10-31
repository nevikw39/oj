/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <assert.h>
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

void matrix_mul_assign(int64_t a[3][3], int64_t b[3][3])
{
    int64_t tmp[3][3];
    memset(tmp, 0, sizeof(tmp));
    for (int k = 0; k < 3; k++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j] % M) % M;
    memcpy(a, tmp, sizeof(tmp));
}

int main()
{
    int t;
    scanf("%d", &t);
    const int vec[3] = {1, 12, 13};
    while (t--)
    {
        int64_t x, i[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, b[3][3] = {{1, 2, 1}, {1, 0, 0}, {0, 1, 0}};
        scanf("%" SCNd64, &x);
        if (x <= 3)
        {
            printf("%d\n", vec[x - 1]);
            continue;
        }
        x -= 3;
        while (x)
        {
            if (x & 1)
                matrix_mul_assign(i, b); // i *= b
            matrix_mul_assign(b, b);     // b *= b
            x >>= 1;
        }
        printf("%" PRId64 "\n", (vec[2] * i[0][0] % M + vec[1] * i[0][1] % M + vec[0] * i[0][2]) % M);
    }
    return 0;
}
