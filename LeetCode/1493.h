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

int longestSubarray(int *nums, int numsSize)
{
    int y = 0, zero = 0;
    for (int l = 0, r = 0; r < numsSize; r++)
    {
        zero += !nums[r];
        while (zero > 1)
            zero -= !nums[l++];
        y = bwmax(y, r - l);
    }
    return y;
}
