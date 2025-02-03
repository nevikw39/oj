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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int longestMonotonicSubarray(const int *restrict nums, int numsSize)
{
    int inc = 1, dec = 1, y = 1;
    while (--numsSize)
    {
        if (*nums < *(nums + 1))
        {
            y = bwmax(y, ++inc);
            dec = 1;
        }
        else if (*nums > *(nums + 1))
        {
            inc = 1;
            y = bwmax(y, ++dec);
        }
        else
        {
            inc = 1;
            dec = 1;
        }
        ++nums;
    }
    return y;
}
