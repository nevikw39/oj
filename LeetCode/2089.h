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

int *targetIndices(const int *restrict nums, int numsSize, int target, int *restrict returnSize)
{
    *returnSize = 0;
    int i = 0;
    while (numsSize--)
    {
        const int num = *nums++;
        if (num < target)
            ++i;
        else if (num == target)
            ++*returnSize;
    }
    int *const restrict r = malloc(sizeof(int) * *returnSize);
    for (int *ptr = r; ptr < r + *returnSize; ptr++)
        *ptr = i++;
    return r;
}
