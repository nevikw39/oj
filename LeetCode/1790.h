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

bool areAlmostEqual(const char *restrict s1, const char *restrict s2)
{
    int arr[26] = {}, brr[26] = {}, diff = 0;
    while (*s1)
    {
        ++arr[*s1 - 'a'];
        ++brr[*s2 - 'a'];
        if (*s1++ != *s2++)
            ++diff;
    }
    for (int i = 0; i < 26; i++)
        if (arr[i] != brr[i])
            return false;
    return !diff || diff == 2;
}
