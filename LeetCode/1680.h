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

const int MOD = 1e9 + 7;
inline int f(int x) { return 32 - __builtin_clz(x); }

int concatenatedBinary(int n)
{
    int y = 0;
    for (int i = 1; i <= n; i++)
        y = ((1LL * y << f(i)) % MOD + i) % MOD;
    return y;
}
