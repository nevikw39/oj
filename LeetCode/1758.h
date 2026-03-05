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

int minOperations(const char *s)
{
    bool flag = true;
    int a = 0, b = 0;
    for (char *c = s; *c; c++, flag ^= 1)
        if ((*c ^ flag) & 1)
            ++a;
        else
            ++b;
    return a < b ? a : b;
}
