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

int numberOfWays(const char *corridor)
{
    int x = 0, y = 0, z = 1;
    for (const char *c = corridor; *c; c++)
        if (*c == 'S')
        {
            x = y;
            y = z;
            z = x;
        }
        else
            z = (z + x) % MOD;
    return x;
}
