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

int numOfSubarrays(const int *restrict arr, int arrSize)
{
    int odd = 0, even = 0, cnt = 0;
    while (arrSize--)
    {
        if (*arr++ & 1)
        {
            odd ^= even ^= odd ^= even;
            ++odd;
        }
        else
            ++even;
        cnt += odd;
        cnt %= 1000000007;
    }
    return cnt;
}
