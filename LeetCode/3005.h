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

int maxFrequencyElements(int *nums, int numsSize)
{
    int arr[100] = {}, mx = 0, cnt = 0;
    while (numsSize--)
        ++arr[*nums++ - 1];
    for (int *ptr = arr; ptr < arr + 100; ptr++)
        if (mx < *ptr)
        {
            mx = *ptr;
            cnt = 1;
        }
        else if (mx == *ptr)
            ++cnt;
    return mx * cnt;
}
