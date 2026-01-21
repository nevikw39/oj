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

inline int lowbit(int x) { return x & -x; }

int *minBitwiseArray(int *const __restrict__ nums, int numsSize, int *const __restrict__ returnSize)
{
    *returnSize = numsSize;
    for (int *ptr = nums; numsSize--; ptr++)
        *ptr -= *ptr & 1 ? lowbit(*ptr + 1) >> 1 : *ptr + 1;
    return nums;
}
