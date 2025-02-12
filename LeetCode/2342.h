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

int maximumSum(const int *restrict nums, int numsSize)
{
    int y = -1, max_digit_sum[9 * 9 + 1] = {};
    while (numsSize--)
    {
        int digit_sum = 0;
        for (int i = *nums; i; i /= 10)
            digit_sum += i % 10;
        if (max_digit_sum[digit_sum] && y < max_digit_sum[digit_sum] + *nums)
            y = max_digit_sum[digit_sum] + *nums;
        if (max_digit_sum[digit_sum] < *nums)
            max_digit_sum[digit_sum] = *nums;
        ++nums;
    }
    return y;
}
