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

static inline int bwabs(int x) { return (x ^ (x >> ((sizeof(int) << 3) - 1))) - (x >> ((sizeof(int) << 3) - 1)); }

static inline int reverse(int x)
{
    int y = 0;
    while (x)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

int mirrorDistance(int n) { return bwabs(n - reverse(n)); }
