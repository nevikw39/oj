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

inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int minPathSum(int **grid, int gridSize, int *gridColSize)
{
    int y = **grid;
    for (int *ptr = *grid + 1; (*gridColSize)-- > 1; ptr++)
        y = *ptr += *(ptr - 1);
    ++gridColSize;
    for (int **pptr = grid + 1; pptr < grid + gridSize; pptr++)
        y = **pptr += **(pptr - 1);
    for (int **pptr = grid, **qqtr = grid + 1; qqtr < grid + gridSize; pptr++, qqtr++, ++gridColSize)
        for (int *ptr = *pptr + 1, *qtr = *qqtr + 1; (*gridColSize)-- > 1; ptr++, qtr++)
            y = *qtr += bwmin(*(qtr - 1), *ptr);
    return y;
}
