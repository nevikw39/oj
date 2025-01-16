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

int xorAllNums(const int *restrict nums1, const int nums1Size, const int *restrict nums2, const int nums2Size)
{
    int y = 0;
    if (nums2Size & 1)
        for (int n = nums1Size; n--;)
            y ^= *nums1++;
    if (nums1Size & 1)
        for (int n = nums2Size; n--;)
            y ^= *nums2++;
    return y;
}
