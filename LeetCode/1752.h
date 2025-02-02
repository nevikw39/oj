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

bool check(const int *const restrict nums, const int numsSize)
{
    int cnt = *nums < nums[numsSize - 1];
    for (int i = 1; i < numsSize; ++i)
        if (nums[i - 1] > nums[i])
            ++cnt;
    return cnt <= 1;
}
