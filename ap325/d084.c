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
    int64_t n, k;
    scanf("%" SCNd64 "%" SCNd64, &n, &k);
    int64_t dp[n];
    scanf("%" SCNd64, dp);
    for (int i = 1; i < k + 1; i++)
    {
        int64_t x;
        scanf("%" SCNd64, &x);
        i[dp] = x > dp[i - 1] ? x : dp[i - 1];
    }
    for (int i = k + 1; i < n; i++)
    {
        int64_t x;
        scanf("%" SCNd64, &x);
        i[dp] = dp[i - k - 1] + x > dp[i - 1] ? dp[i - k - 1] + x : dp[i - 1];
    }
    printf("%" PRId64 "\n", dp[n - 1]);
    return 0;
}