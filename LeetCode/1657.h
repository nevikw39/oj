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

int cmp(int *l, int *r) { return *r - *l; }

bool closeStrings(char *word1, char *word2)
{
    int arr[26] = {}, brr[26] = {};
    while (*word1)
        ++arr[*word1++ - 'a'];
    while (*word2)
        ++brr[*word2++ - 'a'];
    for (int i = 0; i < 26; i++)
        if (!!i[arr] ^ !!i[brr])
            return false;
    qsort(arr, 26, sizeof(int), cmp);
    qsort(brr, 26, sizeof(int), cmp);
    for (int i = 0; i < 26; i++)
        if (i[arr] != i[brr])
            return false;
    return true;
}
