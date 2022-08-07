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

const int MOD = 1e9 + 7;

int countVowelPermutation(int n)
{
    int64_t dp[] = {1, 1, 1, 1, 1};
    while (n-- > 1)
    {
        int64_t rolling[] = {dp[0], dp[1], dp[2], dp[3], dp[4]};
        dp[0] = (rolling[1] + rolling[2] + rolling[4]) % MOD;
        dp[1] = (rolling[0] + rolling[2]) % MOD;
        dp[2] = (rolling[1] + rolling[3]) % MOD;
        dp[3] = rolling[2];
        dp[4] = (rolling[2] + rolling[3]) % MOD;
    }
    return (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % MOD;
}
