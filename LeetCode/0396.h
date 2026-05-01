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

int maxRotateFunction(const int *const restrict nums, int numsSize)
{
    int sum = 0, f = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += i[nums];
        f += i * i[nums];
    }
    int mx = f;
    for (int i = numsSize - 1; i; i--)
    {
        f += sum - numsSize * i[nums];
        if (mx < f)
            mx = f;
    }
    return mx;
}
