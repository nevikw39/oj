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

inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int minFlips(char *s)
{
    int a = 0, b = 0;
    bool flag = true;
    for (char *c = s; *c; c++, flag ^= 1)
        if ((*c ^ flag) & 1)
            ++a;
        else
            ++b;
    if (flag)
        return bwmin(a, b);
    int y = bwmin(a, b);
    for (char *c = s; *c; c++, flag ^= 1)
    {
        if ((*c ^ flag) & 1)
            ++a;
        else
            ++b;
        if ((*c ^ !flag) & 1)
            --a;
        else
            --b;
        y = bwmin(y, bwmin(a, b));
    }
    return y;
}
