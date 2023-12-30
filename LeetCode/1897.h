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

bool makeEqual(char **words, int wordsSize)
{
    int arr[26] = {};
    for (int i = 0; i < wordsSize; i++)
        for (char *ptr = *words++; *ptr; ptr++)
            ++arr[*ptr - 'a'];
    for (int i = 0; i < 26; i++)
        if (i[arr] % wordsSize)
            return false;
    return true;
}
