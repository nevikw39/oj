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

int numSteps(const char *restrict s)
{
    int ones = 0, trailing_zeros = 0, n = 0;
    while (*s)
    {
        if (*s == '1')
        {
            ++ones;
            trailing_zeros = 0;
        }
        else
            ++trailing_zeros;
        ++s;
        ++n;
    }
    return ones == 1 ? n - 1 : (n << 1 | 1) - ones - trailing_zeros;
}
