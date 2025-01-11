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

bool canConstruct(const char *restrict s, int k)
{
    int arr[26] = {}, odds = 0, l = 0;
    while (*s)
    {
        if (++arr[*s++ - 'a'] & 1)
            ++odds;
        else
            --odds;
        ++l;
    }
    return odds <= k && k <= l;
}
