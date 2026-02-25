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

int cmp(const void *lhs, const void *rhs)
{
    const int l = *(int *)lhs, r = *(int *)rhs, popcnt_l = __builtin_popcount(l), popcnt_r = __builtin_popcount(r);
    return popcnt_l - popcnt_r ?: l - r;
}

int *sortByBits(int *arr, int arrSize, int *returnSize)
{
    qsort(arr, *returnSize = arrSize, sizeof(int), cmp);
    return arr;
}
