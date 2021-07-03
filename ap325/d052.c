/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    int64_t n, c = 0, r = 0;
    scanf("%" SCNd64, &n);
    while (n--)
    {
        int64_t x;
        scanf("%" SCNd64, &x);
        c = c > 0 ? c + x : x;
        r = r > c ? r : c;
    }
    printf("%" PRId64 "\n", r);
    return 0;
}