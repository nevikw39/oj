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

inline int bwabs(int x) { return (x ^ (x >> ((sizeof(int) << 3) - 1))) - (x >> ((sizeof(int) << 3) - 1)); }
inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int minOperations(int *nums, int numsSize)
{
    for (int *ptr = nums + 1; ptr < nums + numsSize; ptr++)
    {
        const int ad = bwabs(*(ptr - 1) - *ptr);
        if (ad != 1 && numsSize - ad != 1)
            return -1;
    }
    if (numsSize == 1 || !*nums && 1[nums] == 1)
        return 0;
    return bwmin(numsSize - *nums, *nums + 2);
}
