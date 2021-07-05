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
    int64_t n, c, p = 0, pp = 0;
    scanf("%" SCNd64, &n);
    while (n--)
    {
        scanf("%" SCNd64, &c);
        c = p > pp + c ? p : pp + c;
        pp = p, p = c;
    }
    printf("%" PRId64 "\n", c);
    return 0;
}