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

static inline bool f(bool *x, int *cnt)
{
    if (!*x && ++*cnt == 4)
        return false;
    *x = true;
    return true;
}

bool findRotation(int **mat, int matSize, int *matColSize, int **target, int targetSize, int *targetColSize)
{
    bool a = false, b = false, c = false, d = false;
    int cnt = 0;
    for (int i = 0; i < matSize; i++)
        for (int j = 0; j < matSize; j++)
        {
            if (mat[i][j] != target[i][j] && !f(&a, &cnt))
                return false;
            if (mat[i][j] != target[matSize - 1 - j][i] && !f(&b, &cnt))
                return false;
            if (mat[i][j] != target[matSize - 1 - i][matSize - 1 - j] && !f(&c, &cnt))
                return false;
            if (mat[i][j] != target[j][matSize - 1 - i] && !f(&d, &cnt))
                return false;
        }
    return true;
}
