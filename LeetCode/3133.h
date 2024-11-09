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

long long minEnd(int n, int x)
{
    int64_t y = x;
    --n;
    for (int i = 0; n; i++)
        if (~x & 1LL << i)
        {
            y |= (n & 1LL) << i;
            n >>= 1;
        }
    return y;
}
