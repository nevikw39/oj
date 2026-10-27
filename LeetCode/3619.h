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

int dfs(int *const *const restrict grid, int n, int m, int k, int i, int j)
{
    static const int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
    int y = grid[i][j] % k;
    grid[i][j] = 0;
    for (int d = 0; d < 4; d++)
    {
        const int ip = i + di[d], jp = j + dj[d];
        if (0 <= ip && ip < n && 0 <= jp && jp < m && grid[ip][jp])
            y = (y + dfs(grid, n, m, k, ip, jp)) % k;
    }
    return y;
}

int countIslands(int *const *const restrict grid, int gridSize, int *const restrict gridColSize, int k)
{
    int cnt = 0;
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < *gridColSize; j++)
            if (grid[i][j] && !(dfs(grid, gridSize, *gridColSize, k, i, j) % k))
                cnt++;
    return cnt;
}
