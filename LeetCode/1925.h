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

#define N 250

bool is_square[N * N << 1 | 1];

int countTriples(int n)
{
    if (!*is_square)
        for (int i = 0; i * i < N * N << 1; i++)
            is_square[i * i] = true;
    int cnt = 0;
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
            if (a * a + b * b <= n * n && is_square[a * a + b * b])
                ++cnt;
    return cnt;
}
