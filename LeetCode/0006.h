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

char *convert(char *s, int numRows)
{
    if (numRows == 1)
        return s;
    int l = strlen(s), m = numRows - 1 << 1;
    char *y = malloc(l + 1), *ptr = y;
    for (int i = 0; i < numRows; i++)
        for (char *qtr = s + i; qtr - s < l; qtr += m)
        {
            *ptr++ = *qtr;
            if (i && numRows - i > 1)
            {
                char *rtr = qtr + m - (i << 1);
                if (rtr - s < l)
                    *ptr++ = *rtr;
            }
        }
    *ptr = 0;
    return y;
}
