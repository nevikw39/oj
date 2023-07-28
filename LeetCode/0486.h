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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

bool PredictTheWinner(int *nums, int numsSize)
{
    int *dp = calloc(numsSize, sizeof(int));
    for (int i = numsSize - 1; ~i; i--)
        for (int j = i; j < numsSize; j++)
            if (i == j)
                j[dp] = i[nums];
            else
                j[dp] = bwmax(nums[i] - j[dp], j[nums] - dp[j - 1]);
    bool y = dp[numsSize - 1] >= 0;
    free(dp);
    return y;
}
