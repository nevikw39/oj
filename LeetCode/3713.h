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

int longestBalanced(char *s)
{
    int mx = 0;
    while (*s)
    {
        int arr[26] = {}, cnt = 0, f = 0;
        for (char *ss = s; *ss; ss++)
        {
            if (!arr[*ss - 'a']++)
                ++cnt;
            if (f < arr[*ss - 'a'])
                f = arr[*ss - 'a'];
            const int l = ss - s + 1;
            if (cnt * f == l && mx < l)
                mx = l;
        }
        ++s;
    }
    return mx;
}
