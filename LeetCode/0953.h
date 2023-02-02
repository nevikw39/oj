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

bool isAlienSorted(char **words, int wordsSize, char *order)
{
    int arr[26];
    for (int i = 0; i < 26; i++)
        arr[i[order] - 'a'] = i;
    for (int i = 1; i < wordsSize; i++)
    {
        char *l = words[i - 1], *r = words[i];
        while (*l && *l == *r)
        {
            ++l;
            ++r;
        }
        if (*l && !*r || *l && *r && arr[*l - 'a'] > arr[*r - 'a'])
            return false;
    }
    return true;
}
