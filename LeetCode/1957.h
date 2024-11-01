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

char *makeFancyString(char *const restrict s)
{
    char *ptr = s, *qtr;
    for (int i = 0; i < 2; i++)
        if (!*ptr++)
            return s;
    for (qtr = ptr; *ptr; ptr++)
        if (*(qtr - 2) != *ptr || *(qtr - 1) != *ptr)
            *qtr++ = *ptr;
    *qtr = 0;
    return s;
}
