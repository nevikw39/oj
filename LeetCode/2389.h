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

bool validPartition(int *nums, int numsSize)
{
    bool dp[3] = {false, *nums == 1[nums], true};
    for (int i = 2, *ptr = nums + 2; i < numsSize; i++, ++ptr)
        if (*dp || 1[dp] || 2[dp])
            dp[i % 3] = *ptr == ptr[-1] && dp[(i - 2 + 3) % 3]
                    || *ptr == ptr[-1] && *ptr == ptr[-2] && dp[i % 3]
                    || *ptr - ptr[-1] == 1 && *ptr - ptr[-2] == 2 && dp[i % 3];
        else
            return false;
    return dp[(numsSize - 1) % 3];
}
