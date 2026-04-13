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

static inline int bwabs(int x) { return (x ^ (x >> ((sizeof(int) << 3) - 1))) - (x >> ((sizeof(int) << 3) - 1)); }
static inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int getMinDistance(int *nums, int numsSize, int target, int start)
{
    int d = INT_MAX;
    for (int i = 0; i < numsSize; i++)
        if (i[nums] == target)
            d = bwmin(d, bwabs(i - start));
    return d;
}
