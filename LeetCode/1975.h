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

inline int bwabs(int x) { return (x ^ (x >> ((sizeof(int) << 3) - 1))) - (x >> ((sizeof(int) << 3) - 1)); }
inline int bwmin(int x, int y) { return y ^ ((x ^ y) & -(x < y));}

long long maxMatrixSum(int **matrix, int matrixSize, int *matrixColSize)
{
    int64_t sum = 0;
    int cnt = 0, mn = INT_MAX;
    for (int **ptr = matrix; matrixSize--; ptr++, matrixColSize++)
        for (int *qtr = *ptr; (*matrixColSize)--; qtr++)
        {
            if (*qtr < 0)
                ++cnt;
            sum += *qtr = bwabs(*qtr);
            mn = bwmin(mn, *qtr);
        }
    if (cnt & 1)
        return sum - (mn << 1);
    return sum;
}
