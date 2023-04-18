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

char *mergeAlternately(char *word1, char *word2)
{
    char *y = calloc(sizeof(char), strlen(word1) + strlen(word2) + 1);
    for (char *ptr = y; *word1 || *word2;)
    {
        if (*word1)
            *ptr++ = *word1++;
        if (*word2)
            *ptr++ = *word2++;
    }
    return y;
}
