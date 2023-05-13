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

const int M = 1e9 + 7;

int countGoodStrings(int low, int high, int zero, int one)
{
    int *dp = calloc(sizeof(int), high + 1), y = 0;
    *dp = 1;
    for (int i = 1; i <= high; i++)
    {
        if (i >= zero)
            i[dp] = dp[i - zero];
        if (i >= one)
            i[dp] = (i[dp] + dp[i - zero]) % M;
        if (i >= low)
            y += dp[i];
    }
    free(dp);
    return y;
}
