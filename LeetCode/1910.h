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

char *removeOccurrences(char *const restrict s, const char *const restrict part)
{
    const int m = strlen(part);
    char *ptr = s, *qtr = s;
    while (*qtr)
    {
        *ptr++ = *qtr++;
        if (ptr - m >= s && !strncmp(ptr - m, part, m))
            ptr -= m;
    }
    *ptr = 0;
    return s;
}
