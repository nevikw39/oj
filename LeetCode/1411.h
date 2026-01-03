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

#define MOD 1000000007

int numOfWays(int n)
{
    int a = 0, b = 3;
    while (n--)
    {
        const int ap = (a * 3LL % MOD + (b << 1) % MOD) % MOD, bp = ((a << 1) % MOD + (b << 1) % MOD) % MOD;
        a = ap;
        b = bp;
    }
    return (a + b) % MOD;
}
