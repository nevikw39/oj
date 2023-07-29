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

double dp[200][200];

double f(int a, int b)
{
    if (a <= 0 && b <= 0)
        return .5;
    if (a <= 0 || b <= 0)
        return a <= 0;
    if (dp[a][b])
        return dp[a][b];
    for (int i = 0; i < 4; i++)
        dp[a][b] += f(a + i - 4, b - i);
    return dp[a][b] /= 4.;
}

double soupServings(int n)
{
    if (n > 4800)
        return 1.;
    memset(dp, 0, sizeof dp);
    return f((n + 24) / 25, (n + 24) / 25);
}
