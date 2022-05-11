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

int c(int n, int r)
{
    if (r > n - r)
        r = n - r;
    int y = 1;
    for (int i = 0; i < r; i++)
        y = y * (n - i) / (i + 1);
    return y;
}

int inline h(int n, int r) { return c(n + r - 1, r); }

int inline countVowelStrings(int n) { return h(5, n); }
