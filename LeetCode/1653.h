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

inline int bwmin(int x, int y) { return y ^ ((x ^ y) & -(x < y)); }

int minimumDeletions(char *s)
{
    int mn = 0, b = 0;
    for (char *c = s; *c; c++)
        if (*c == 'b')
            ++b;
        else
            mn = bwmin(mn + 1, b);
    return mn;
}
