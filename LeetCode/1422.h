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

int maxScore(const char *restrict s)
{
    int zeros = 0, ones = 0, y = INT_MIN;
    while (*(s + 1))
    {
        if (*s++ == '0')
            ++zeros;
        else
            ++ones;
        if (y < zeros - ones)
            y = zeros - ones;
    }
    if (*s == '1')
        ++ones;
    return y + ones;
}
