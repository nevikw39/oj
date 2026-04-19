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

static inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int maxDistance(const int *const restrict nums1, int nums1Size, const int *const restrict nums2, int nums2Size)
{
    int d = 0;
    for (const int *ptr = nums1, *qtr = nums2; ptr < nums1 + nums1Size && qtr < nums2 + nums2Size;)
        if (*ptr <= *qtr)
        {
            d = bwmax(d, (qtr - nums2) - (ptr - nums1));
            ++qtr;
        }
        else
            ++ptr;
    return d;
}
