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

long long minimumReplacement(int *nums, int numsSize)
{
    int64_t y = 0;
    for (int *ptr = nums + numsSize - 2; ptr >= nums; ptr--)
        if (*ptr > 1[ptr])
        {
            int replaces = (*ptr + 1[ptr] - 1LL) / 1[ptr];
            y += replaces - 1;
            *ptr /= replaces;
        }
    return y;
}
