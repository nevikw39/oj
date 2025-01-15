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

int minimizeXor(const int num1, const int num2)
{
    int y = 0, n = __builtin_popcount(num2);
    for (int i = 31 - __builtin_clz(num1); ~i && n; --i)
        if (num1 & 1 << i)
        {
            y |= 1 << i;
            --n;
        }
    for (int i = 1; n; i <<= 1)
        if (~y & i)
        {
            y |= i;
            --n;
        }
    return y;
}
