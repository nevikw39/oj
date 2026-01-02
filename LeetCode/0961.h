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

int repeatedNTimes(int *const nums, int numsSize)
{
    for (int *ptr = nums + 2; numsSize-- > 2; ptr++)
        if (*ptr == *(ptr - 1) || *ptr == *(ptr - 2))
            return *ptr;
    return *nums;
}
