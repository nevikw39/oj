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

int minInsertions(const char *restrict s)
{
    int cnt = 0, balance = 0;
    while (*s)
        if (*s++ == '(')
            ++balance;
        else
        {
            if (!balance)
                ++cnt;
            else
                --balance;
            if (*s == ')')
                ++s;
            else
                ++cnt;
        }
    return cnt + (balance << 1);
}
