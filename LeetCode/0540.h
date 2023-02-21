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

int singleNonDuplicate(int *nums, int numsSize)
{
    for (int i = 0; i + 1 < numsSize; i += 2)
        if (nums[i] != nums[i + 1])
            return nums[i];
    return nums[numsSize - 1];
}
