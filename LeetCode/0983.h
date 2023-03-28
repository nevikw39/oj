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

inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }
inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int mincostTickets(int *days, int daysSize, int *costs, int costsSize)
{
    bool arr[365 + 1] = {};
    while (daysSize--)
        arr[*days++] = true;
    int dp[365 + 1] = {};
    for (int i = 1; i <= 365; i++)
        if (arr[i])
            dp[i] = bwmin(dp[i - 1] + *costs, bwmin(dp[bwmax(i - 7, 0)] + 1 [costs], dp[bwmax(i - 30, 0)] + 2 [costs]));
        else
            dp[i] = dp[i - 1];
    return dp[365];
}
