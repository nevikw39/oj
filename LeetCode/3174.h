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

char *clearDigits(char *const s)
{
    char *ptr = s, *qtr = s;
    while (*qtr)
    {
        if (!isdigit(*qtr))
            *ptr++ = *qtr;
        else if (ptr > s)
            --ptr;
        ++qtr;
    }
    *ptr = 0;
    return s;
}
