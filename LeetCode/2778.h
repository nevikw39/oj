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

int sumOfSquares(const int *nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; nums++)
        if (!(numsSize % ++i))
            sum += *nums * *nums;
    return sum;
}
