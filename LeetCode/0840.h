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

inline bool f(const int row[], const int col[], const int diag[], const int arr[])
{
    if (diag[0] != 15 || diag[1] != 15)
        return false;
    for (int i = 0; i < 3; i++)
        if (i[row] != 15 || i[col] != 15)
            return false;
    for (int i = 1; i <= 9; i++)
        if (i[arr] != 1)
            return false;
    return true;
}

int numMagicSquaresInside(int *const *const grid, int gridSize, int *const gridColSize)
{
    int cnt = 0;
    for (int i = 0; i + 2 < gridSize; i++)
        for (int j = 0; j + 2 < *gridColSize; j++)
        {
            int row[3] = {}, col[3] = {}, diag[2] = {}, arr[16] = {};
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++)
                {
                    const int val = grid[i + k][j + l];
                    row[k] += val;
                    col[l] += val;
                    if (k == l)
                        diag[0] += val;
                    if (k + l == 2)
                        diag[1] += val;
                    ++arr[val];
                }
            if (f(row, col, diag, arr))
                ++cnt;
        }
    return cnt;
}
