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

void dfs(int **grid, int n, int m, int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || !grid[i][j])
        return;
    grid[i][j] = false;
    static const int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
    for (int d = 0; d < 4; d++)
        dfs(grid, n, m, i + di[d], j + dj[d]);
}

int numEnclaves(int **grid, int gridSize, int *gridColSize)
{
    for (int i = 0; i < gridSize; i++)
    {
        dfs(grid, gridSize, *gridColSize, i, 0);
        dfs(grid, gridSize, *gridColSize, i, *gridColSize - 1);
    }
    for (int j = 0; j < *gridColSize; j++)
    {
        dfs(grid, gridSize, *gridColSize, 0, j);
        dfs(grid, gridSize, *gridColSize, gridSize - 1, j);
    }
    int y = 0;
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < *gridColSize; j++)
            y += grid[i][j];
    return y;
}
