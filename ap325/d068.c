/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int64_t inline bwmin(int64_t x, int64_t y)
{
    return y ^ ((x ^ y) & -(x < y));
}

int main()
{
    int64_t n, c, p = INT64_MAX, pp = 0, ppp = 0;
    scanf("%" SCNd64, &n);
    while (n--)
    {
        scanf("%" SCNd64, &c);
        c += bwmin(p, bwmin(pp, ppp));
        ppp = pp, pp = p, p = c;
    }
    printf("%" PRId64 "\n", bwmin(pp, p));
    return 0;
}