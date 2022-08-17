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

int firstUniqChar(char *s)
{
    int arr[26] = {0}, i = 0;
    for (char *ptr = s; *ptr; ptr++)
        ++arr[*ptr - 'a'];
    for (char *ptr = s; *ptr; ptr++)
        if (arr[*ptr - 'a'] == 1)
            return i;
        else
            ++i;
    return -1;
}
