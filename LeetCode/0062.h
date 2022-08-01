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

int inline uniquePaths(int m, int n)
{
    --m;
    --n;
    if (m < n)
        m ^= n ^= m ^= n;
    m += n;
    int y = 1;
    for (int i = 1; i <= n; i++)
        y = y * (m - i + 1LL) / i;
    return y;
}
