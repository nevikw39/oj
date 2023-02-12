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

int tribonacci(int n)
{
    if (n < 3)
        return !!n;
    int a = 0, b = 1, c = 1;
    for (int i = 2, tmp; i < n; i++)
    {
        tmp = a + b + c;
        a = b;
        b = c;
        c = tmp;
    }
    return c;
}
