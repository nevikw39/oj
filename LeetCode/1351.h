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

int countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int sum = 0;
    for (int i = 0, j = *gridColSize - 1; i < gridSize && ~j;)
        if (grid[i][j] < 0)
        {
            sum += gridSize - i;
            --j;
        }
        else
            ++i;
    return sum;
}
