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

int getCommon(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    while (nums1Size && nums2Size)
        if (*nums1 < *nums2)
        {
            ++nums1;
            --nums1Size;
        }
        else if (*nums1 == *nums2)
            return *nums1;
        else
        {
            ++nums2;
            --nums2Size;
        }
    return -1;
}
