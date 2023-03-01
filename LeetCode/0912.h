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

int cmp(const int *l, const int *r) { return *l - *r; }

int *sortArray(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums;
}
