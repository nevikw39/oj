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

int arraySign(int *nums, int numsSize)
{
    int neg = 0;
    while (numsSize--)
        if (!*nums)
            return 0;
        else if (*nums++ < 0)
            ++neg;
    return (~neg & 1) - (neg & 1);
}
