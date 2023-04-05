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

inline int div_ceil(int64_t lhs, int rhs) { return (lhs + rhs - 1) / rhs; }
inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int minimizeArrayValue(int *nums, int numsSize)
{
    int y = 0, cnt = 0;
    int64_t ps = 0;
    while (numsSize--)
        y = bwmax(y, div_ceil(ps += *nums++, ++cnt));
    return y;
}
