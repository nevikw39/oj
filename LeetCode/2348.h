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

long long zeroFilledSubarray(int *nums, int numsSize)
{
    int64_t sum = 0;
    for (int cnt = 0; numsSize--;)
        if (*nums++)
            cnt = 0;
        else
            sum += ++cnt;
    return sum;
}
