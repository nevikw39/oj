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

int bestClosingTime(char *customers)
{
    int y = 0;
    for (int i = 0, mn = 0, penalty = 0; *customers; i++)
    {
        if (*customers != 'Y')
            ++penalty;
        else
            --penalty;
        if (mn > penalty)
        {
            mn = penalty;
            y = i + 1;
        }
    }
    return y;
}
