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

char *maxSumOfSquares(int num, int sum)
{
    char *const s = malloc(sizeof(char) * (num + 1)), *ptr = s;
    while (num--)
    {
        const int digit = sum < 9 ? sum : 9;
        *ptr++ = '0' + digit;
        sum -= digit;
    }
    *ptr = 0;
    if (sum)
    {
        free(s);
        return "";
    }
    return s;
}
