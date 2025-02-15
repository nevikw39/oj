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

bool f(int x, int target)
{
    if (x < target || target < 0)
        return false;
    if (x == target)
        return true;
    for (int i = 10; x >= i; i *= 10)
        if (f(x / i, target - x % i))
            return true;
    return false;
}

int punishmentNumber(int n)
{
    int y = 0;
    for (int i = 1; i <= n; i++)
        if (f(i * i, i))
            y += i * i;
    return y;
}
