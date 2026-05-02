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

//constexpr
static inline bool good(int x)
{
    bool flag = false;
    for (int i = x; i; i /= 10)
        switch (i % 10)
        {
        case 3:
        case 4:
        case 7:
            return false;
        case 2:
        case 5:
        case 6:
        case 9:
            flag = true;
        }
    return flag;
}

int rotatedDigits(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (good(i))
            ++cnt;
    return cnt;
}
