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

int cmp(const void *const l, const void *const r) { return *(int *)l - *(int *)r; }

long long maxAlternatingSum(int *nums, int numsSize)
{
    int *ptr;
    for (ptr = nums; ptr < nums + numsSize; ptr++)
        *ptr *= *ptr;
    qsort(nums, numsSize, sizeof *nums, cmp);
    int64_t sum = 0;
    ptr = nums;
    while (ptr < nums + (numsSize >> 1))
        sum -= *ptr++;
    while (ptr < nums + numsSize)
        sum += *ptr++;
    return sum;
}
