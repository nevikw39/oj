/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int cmp(const int *const lhs, const int *const rhs) { return *rhs - *lhs; }

int change(int amount, int *coins, int coinsSize)
{
    qsort(coins, coinsSize, sizeof(int), cmp);
    int *dp = calloc(amount + 1, sizeof(int));
    *dp = 1;
    for (int *ptr = coins; ptr != coins + coinsSize; ptr++)
        for (int i = *ptr; i <= amount; i++)
            i[dp] += (i - *ptr)[dp];
    int y = dp[amount];
    free(dp);
    return y;
}
