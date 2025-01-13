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

int minimumLength(const char *restrict s)
{
    int arr[26] = {}, sum = 0;
    while (*s)
        ++arr[*s++ - 'a'];
    for (int i = 0; i < 26; i++)
        if (i[arr])
            sum += 2 - (i[arr] & 1);
    return sum;
}
