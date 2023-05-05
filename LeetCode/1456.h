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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int maxVowels(char *s, int k)
{
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    for (int kk = k; kk--;)
        switch (*s++)
        {
        case 'a':
            ++a;
            break;
        case 'e':
            ++e;
            break;
        case 'i':
            ++i;
            break;
        case 'o':
            ++o;
            break;
        case 'u':
            ++u;
        }
    int y = a + e + i + o + u;
    while (*s)
    {
        switch (*s)
        {
        case 'a':
            ++a;
            break;
        case 'e':
            ++e;
            break;
        case 'i':
            ++i;
            break;
        case 'o':
            ++o;
            break;
        case 'u':
            ++u;
        }
        switch (s[-k])
        {
        case 'a':
            --a;
            break;
        case 'e':
            --e;
            break;
        case 'i':
            --i;
            break;
        case 'o':
            --o;
            break;
        case 'u':
            --u;
        }
        y = bwmax(y, a + e + i + o + u);
        ++s;
    }
    return y;
}
