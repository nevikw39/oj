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

int prefixCount(char *const *restrict words, int wordsSize, const char *const restrict pref)
{
    const int l = strlen(pref);
    int y = 0;
    while (wordsSize--)
        if (!strncmp(*words++, pref, l))
            ++y;
    return y;
}
