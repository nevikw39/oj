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

#define MOD 1000000007

int countPermutations(const int *const complexity, int complexitySize)
{
    const int *ptr = complexity, mn = *ptr;
    int perm = 1;
    while (--complexitySize)
        if (mn >= *++ptr)
            return 0;
        else
            perm = 1LL * perm * complexitySize % MOD;
    return perm;
}
