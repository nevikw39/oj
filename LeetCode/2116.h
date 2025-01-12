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

inline int sign(bool x) { return x - !x; }

bool canBeValid(const char *restrict s, const char *restrict locked)
{
    int mn = 0, mx = 0, len = 0;
    while (*s)
    {
        const bool paren = *s++ == '(', free = *locked++ == '0';
        mn -= sign(!paren || free);
        if (mn < 0)
            mn = 0;
        mx += sign(paren || free);
        if (mx < 0)
            return false;
        ++len;
    }
    return ~len & 1 && !mn;
}
