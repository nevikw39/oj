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

int closestTarget(char *const restrict *const restrict words, int wordsSize, const char *const restrict target, int startIndex)
{
    for (int i = 0; i << 1 <= wordsSize; i++)
        if (!strcmp(words[(startIndex + i) % wordsSize], target) || !strcmp(words[(startIndex - i + wordsSize) % wordsSize], target))
            return i;
    return -1;
}
