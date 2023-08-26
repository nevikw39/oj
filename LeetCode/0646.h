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

int cmp(const int *const *const lhs, const int *const *const rhs) { return 1[*lhs] - 1[*rhs]; }

int findLongestChain(int **pairs, int pairsSize, int *pairsColSize)
{
    qsort(pairs, pairsSize, sizeof(int *), cmp);
    int y = 0;
    for (int cur = INT_MIN; pairsSize--; ++pairs)
        if (cur < **pairs)
        {
            cur = 1[*pairs];
            ++y;
        }
    return y;
}
