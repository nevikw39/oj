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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int maxAscendingSum(const int *restrict nums, int numsSize)
{
    int y = *nums++, sum = y;
    while (--numsSize)
    {
        if (*(nums - 1) < *nums)
            sum += *nums;
        else
            sum = *nums;
        y = bwmax(y, sum);
        ++nums;
    }
    return y;
}
