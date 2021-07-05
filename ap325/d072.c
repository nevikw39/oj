/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int64_t inline bwmin(int64_t x, int64_t y)
{
    return y ^ ((x ^ y) & -(x < y));
}

int64_t inline bwabs(int64_t x)
{
    return (x ^ (x >> ((sizeof(int64_t) << 3) - 1))) - (x >> ((sizeof(int64_t) << 3) - 1));
}

int main()
{
    int64_t n, la, ca = 0, lb, cb = 0;
    scanf("%" SCNd64 "%" SCNd64, &n, &la);
    lb = la;
    while (n--)
    {
        int64_t a, b, ca_n, cb_n;
        scanf("%" SCNd64 "%" SCNd64, &a, &b);
        if (ca + bwabs(a - la) < cb + bwabs(a - lb))
            ca_n = ca + bwabs(a - la);
        else
            ca_n = cb + bwabs(a - lb);
        if (ca + bwabs(b - la) < cb + bwabs(b - lb))
            cb_n = ca + bwabs(b - la);
        else
            cb_n = cb + bwabs(b - lb);
        la = a, lb = b, ca= ca_n, cb = cb_n;
    }
    printf("%" PRId64 "\n", bwmin(ca, cb));
    return 0;
}