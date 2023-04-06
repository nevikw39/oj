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

bool dfs(int **grid, int n, int m, int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (grid[i][j])
        return true;
    grid[i][j] = true;
    bool y = true;
    static const int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
    for (int d = 0; d < 4; d++)
        if (!dfs(grid, n, m, i + di[d], j + dj[d]))
            y = false;
    return y;
}

int closedIsland(int **grid, int gridSize, int *gridColSize)
{
    int y = 0;
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < *gridColSize; j++)
            if (!grid[i][j] && dfs(grid, gridSize, *gridColSize, i, j))
                ++y;
    return y;
}
