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

inline bool is_sq(int x)
{
    int root = sqrt(x);
    return root * root == x;
}

int numSquares(int n)
{
    if (is_sq(n))
        return 1;
    while (!(n & 3))
        n >>= 2;
    if ((n & 7) == 7)
        return 4;
    for (int i = 1; i * i <= n; i++)
        if (is_sq(n - i * i))
            return 2;
    return 3;
}
