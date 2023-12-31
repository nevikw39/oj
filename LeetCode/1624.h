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

int maxLengthBetweenEqualCharacters(char *s)
{
    int y = -1, arr[26];
    memset(arr, -1, sizeof arr);
    for (int i = 0; *s; i++, s++)
        if (~arr[*s - 'a'])
            y = bwmax(y, i - arr[*s - 'a'] - 1);
        else
            arr[*s - 'a'] = i;
    return y;
}
