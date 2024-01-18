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

int climbStairs(int n)
{
    if (n < 2)
        return n;
    int a = 1, b = 2;
    for (int i = 2, tmp; i < n; i++)
    {
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return b;
}
