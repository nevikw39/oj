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

char findKthBit(int n, int k)
{
    if (n == 1)
        return '0';
    const int l = 1 << n;
    if (k < l >> 1)
        return findKthBit(n - 1, k);
    else if (k == l >> 1)
        return '1';
    return findKthBit(n - 1, l - k) ^ 1;
}
