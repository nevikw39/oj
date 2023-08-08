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

int search(int *nums, int numsSize, int target)
{
    for (int l = 0, r = numsSize; l < r;)
    {
        int mid = (l & r) + ((l ^ r) >> 1);
        bool flag = (mid[nums] < *nums) ^ (target < *nums);
        if (flag && target < *nums || !flag && target > mid[nums])
            l = mid + 1;
        else if (flag && target >= *nums || !flag && target < mid[nums])
            r = mid;
        else
            return mid;
    }
    return -1;
}
