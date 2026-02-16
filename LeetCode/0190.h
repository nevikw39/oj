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

int reverseBits(unsigned int n)
{
    for (unsigned int i = sizeof(int) * CHAR_BIT >> 1, mask = -1; i; i >>= 1)
    {
        mask ^= mask << i;
        n = ((n >> i) & mask) | ((n << i) & ~mask);
    }
    return n;
}
