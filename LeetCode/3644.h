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

int sortPermutation(int *const restrict nums, int numsSize)
{
    int and_prod = -1;
    for (int i = 0; i < numsSize; i++)
        if (i[nums] != i)
            and_prod &= i[nums];
    return ~and_prod ? and_prod : 0;
}
