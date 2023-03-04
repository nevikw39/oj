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

long long countSubarrays(int *nums, int numsSize, int minK, int maxK)
{
    int64_t y = 0;
    int l = -1, r_mn = -1, r_mx = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < minK || nums[i] > maxK)
            l = i;
        if (nums[i] == minK)
            r_mn = i;
        if (nums[i] == maxK)
            r_mx = i;
        y += bwmax(0, bwmin(r_mn, r_mx) - l);
    }
    return y;
}
