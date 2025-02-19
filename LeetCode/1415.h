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

char *getHappyString(int n, int k)
{
    static const int low[] = {1, 0, 0}, up[] = {2, 2, 1};
    if (3 * (1 << n - 1) < k)
        return "";
    k -= 1;
    int mid = 1 << n - 1;
    char *const str = malloc(sizeof(char) * (n + 1));
    *str = 'a' + k / mid;
    k %= mid;
    for (int i = 1; i < n; i++)
    {
        mid >>= 1;
        if (k >= mid)
        {
            k -= mid;
            str[i] = 'a' + up[str[i - 1] - 'a'];
        }
        else
            str[i] = 'a' + low[str[i - 1] - 'a'];
    }
    str[n] = 0;
    return str;
}
