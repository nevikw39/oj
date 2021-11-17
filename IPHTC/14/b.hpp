const int MOD = 10007;

Matrix::Matrix(int r, int c)
{
    row = r;
    col = c;
    memset(mat, 0, sizeof(mat));
}

int *Matrix::operator[](const int &x) { return mat[x]; }

Matrix Matrix::operator+(const Matrix &x) const
{
    Matrix y(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            y[i][j] = ((mat[i][j] + x[i][j]) % MOD + MOD) % MOD;
    return y;
}

Matrix operator*(const Matrix &x, const Matrix &y)
{
    Matrix z(x.row, y.col);
    for (int i = 0; i < x.row; i++)
        for (int j = 0; j < y.col; j++)
            for (int k = 0; k < x.col; k++)
                z[i][j] = ((z[i][j] + x[i][k] * y[k][j]) % MOD + MOD) % MOD;
    return z;
}
