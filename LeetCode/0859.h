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

bool buddyStrings(char *s, char *goal)
{
    int n = strlen(s), m = strlen(goal);
    if (n != m)
        return false;
    if (!strcmp(s, goal))
    {
        int arr[26] = {};
        for (char *ptr = s; *ptr; ptr++)
            if (++arr[*ptr - 'a'] == 2)
                return true;
        return false;
    }
    int st = -1, nd = -1;
    for (int i = 0; i < n; i++)
        if (s[i] != goal[i])
        {
            if (!~st)
                st = i;
            else if (!~nd)
                nd = i;
            else
                return false;
        }
    return ~nd && s[st] == goal[nd] && s[nd] == goal[st];
}
