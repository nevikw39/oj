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

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    static const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
    int *y = malloc(sizeof(int) * (*returnSize = matrixSize * *matrixColSize));
    for (int i = 0, j = 0, k = 0, *ptr = y; 0 <= i && i < matrixSize && 0 <= j && j < *matrixColSize && matrix[i][j] != INT_MIN; i += di[k], j += dj[k])
    {
        *ptr++ = matrix[i][j];
        matrix[i][j] = INT_MIN;
        if (i + di[k] < 0 || i + di[k] >= matrixSize || j + dj[k] < 0 || j + dj[k] >= *matrixColSize || matrix[i + di[k]][j + dj[k]] == INT_MIN)
            k = k + 1 & 3;
    }
    return y;
}
