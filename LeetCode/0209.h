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

int minSubArrayLen(int target, int *nums, int numsSize)
{
    int y = INT_MAX;
    for (int l = 0, r = 0, sum = 0; r < numsSize; r++)
    {
        sum += nums[r];
        while (sum >= target)
        {
            y = bwmin(y, r - l + 1);
            sum -= nums[l++];
        }
    }
    return y != INT_MAX ? y : 0;
}
