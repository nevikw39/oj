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

bool bitset[26];

int f(char **arr, int arrSize)
{
    if (!arrSize)
        return 0;
    int y = f(arr + 1, arrSize - 1), l = 0;
    bool flag = true;
    for (char *ptr = *arr; *ptr && flag; ptr++, l++)
        if (bitset[*ptr - 'a'])
            flag = false;
        else
            bitset[*ptr - 'a'] = true;
    if (flag)
        y = bwmax(y, l + f(arr + 1, arrSize - 1));
    else
        --l;
    for (char *ptr = *arr; *ptr && l--; ptr++)
        bitset[*ptr - 'a'] = false;
    return y;
}

int maxLength(char **arr, int arrSize)
{
    memset(bitset, 0, sizeof bitset);
    return f(arr, arrSize);
}
