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

const int M = 1e9 + 7;

int binpow(int a, int n)
{
    int y = 1;
    for (a %= M; n; n >>= 1, a = 1LL * a * a % M)
        if (n & 1)
            y = 1LL * y * a % M;
    return y;
}

inline int inv(int x) { return binpow(x, M - 2); }

#define N 101
bool flag = false;
int factorials[N] = {1}, factorial_invs[N] = {1};

int numMusicPlaylists(int n, int goal, int k)
{
    if (!flag)
    {
        flag = true;
        for (int i = 1; i < N; i++)
            factorial_invs[i] = inv(factorials[i] = 1LL * factorials[i - 1] * i % M);
    }
    int y = 0;
    for (int i = n, sign = 1; i >= k; i--, sign *= -1)
        y = (y + 1LL * sign * binpow(i - k, goal - k) * factorial_invs[n - i] % M * factorial_invs[i - k] % M + M) % M;
    return 1LL * factorials[n] * y % M;
}
