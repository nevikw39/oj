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

inline int bwmax(int x, int y) { return x ^ ((x ^ y) & -(x < y)); }

int cmp(const int *const __restrict__ lhs, const int *const __restrict__ rhs) { return *lhs - *rhs; }

int minPairSum(int *const __restrict__ nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), (int (*)(const void *const restrict, const void *const restrict))cmp);
    int y = 0;
    for (int *ptr = nums, *qtr = nums + numsSize - 1; ptr < qtr; ptr++, qtr--)
        y = bwmax(y, *ptr + *qtr);
    return y;
}
