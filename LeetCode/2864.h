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

char *maximumOddBinaryNumber(char *s)
{
    char *ptr;
    int odd = -1, even = 0;
    for (ptr = s; *ptr; ptr++)
        if (*ptr - '0' & 1)
            ++odd;
        else
            ++even;
    ptr = s;
    while (odd--)
        *ptr++ = '1';
    while (even--)
        *ptr++ = '0';
    *ptr = '1';
    return s;
}
