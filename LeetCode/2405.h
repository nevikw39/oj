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

int partitionString(char *s)
{
    int y = 1;
    bool arr[26] = {};
    while (*s)
    {
        if (arr[*s - 'a'])
        {
            for (bool *ptr = arr; ptr < arr + 26; ptr++)
                *ptr = false;
            ++y;
        }
        arr[*s++ - 'a'] = true;
    }
    return y;
}
