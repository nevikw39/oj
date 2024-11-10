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

inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int arr[32];

inline int f()
{
    int y = 0;
    for (int k = 0; k < 32; k++)
        if (arr[k])
            y |= 1 << k;
    return y;
}

int minimumSubarrayLength(int *nums, int numsSize, int k)
{
    memset(arr, 0, sizeof arr);
    int y = INT_MAX;
    for (int *ptr = nums, *qtr = nums; qtr < nums + numsSize; qtr++)
    {
        for (int k = 0; k < 32; k++)
            if (*qtr & 1 << k)
                ++k[arr];
        while (ptr <= qtr && f() >= k)
        {
            y = bwmin(y, qtr - ptr + 1);
            for (int k = 0; k < 32; k++)
                if (*ptr & 1 << k)
                    --k[arr];
            ++ptr;
        }
    }
    return y < INT_MAX ? y : -1;
}
