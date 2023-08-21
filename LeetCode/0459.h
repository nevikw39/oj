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
inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

bool repeatedSubstringPattern(char *s)
{
    int len = strlen(s);
    int *z = malloc(sizeof(int) * len);
    for (int i = 0, l = 0, r = 0; i < len; i++)
    {
        z[i] = bwmax(bwmin(z[i - l], r - i), 0);
        while (i + z[i] < len && s[z[i]] == s[i + z[i]])
        {
            l = i;
            r = i + z[i]++;
        }
    }
    bool y = false;
    for (int i = 1; i < len && !y; i++)
        if (z[i] + i == len && !(len % i))
            y = true;
    free(z);
    return y;
}
