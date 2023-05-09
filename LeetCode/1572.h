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

int diagonalSum(int **mat, int matSize, int *matColSize)
{
    int y = matSize & 1 ? -mat[matSize >> 1][matSize >> 1] : 0;
    for (int i = 0; i < matSize; i++)
        y += mat[i][i] + mat[i][matSize - i - 1];
    return y;
}
