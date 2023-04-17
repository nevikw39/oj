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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize)
{
    int mx = INT_MIN;
    for (int *ptr = candies; ptr < candies + candiesSize; ptr++)
        mx = bwmax(mx, *ptr);
    bool *y = malloc(sizeof(bool) * (*returnSize = candiesSize));
    for (bool *ptr = y; candiesSize--; ptr++)
        *ptr = *candies++ + extraCandies >= mx;
    return y;
}
