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

int cmp(const int *const lhs, const int *const rhs) { return *lhs - *rhs; }

bool f(int *nums, int numsSize, int p, int y)
{
    int cnt = 0;
    for (int *ptr = nums; ptr + 1 < nums + numsSize; ptr++)
        if (1 [ptr] - *ptr <= y)
        {
            ++ptr;
            if (++cnt >= p)
                return false;
        }
    return true;
}

int minimizeMax(int *nums, int numsSize, int p)
{
    if (!p)
        return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int l = 0, r = nums[numsSize - 1] - *nums;
    while (l < r)
    {
        int mid = (l & r) + ((l ^ r) >> 1);
        if (f(nums, numsSize, p, mid))
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
