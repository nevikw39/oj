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

int f(const int *const restrict nums, const int numsSize, const int target, const int sum)
{
    if (!numsSize)
        return target == sum;
    return f(nums + 1, numsSize - 1, target, sum + *nums) + f(nums + 1, numsSize - 1, target, sum - *nums);
}

int findTargetSumWays(int *nums, int numsSize, int target) { return f(nums, numsSize, target, 0); }
