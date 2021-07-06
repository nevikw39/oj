/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

const int64_t P = 1e9 + 9;

inline int64_t binpow(int64_t a, int64_t n)
{
    int64_t y = 1;
    for (a %= P; n; n >>= 1, a = a * a % P)
        if (n & 1)
            y = y * a % P;
    return y;
}

int main()
{
    int64_t n, p, c = 1;
    scanf("%" SCNd64, &n);
    for (int i = 1; i <= n; i++)
        p = c, c = p * ((i << 2) - 2) % P * binpow(i + 1, P - 2) % P;
    printf("%" PRId64 "\n", c);
    return 0;
}