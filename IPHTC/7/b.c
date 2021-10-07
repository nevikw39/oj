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

int main()
{
    int64_t x, y, m, r = 1;
    scanf("%" SCNd64 "%" SCNd64 "%" SCNd64, &x, &y, &m);
    if (!x || m == 1)
    {
        puts("0");
        return 0;
    }
    for (x %= m; y; y >>= 1, x = x * x % m)
        if (y & 1)
            r = r * x % m;
    printf("%" PRId64 "\n", r);
    return 0;
}
