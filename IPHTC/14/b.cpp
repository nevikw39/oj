#include <cstring>
#include <iomanip>
#include <iostream>

const int MAX_N = 102;

class Matrix
{
public:
    Matrix()
    {
        row = col = 0;
        memset(mat, 0, sizeof(mat));
    }
    // TODO
    Matrix(int r, int c);
    const int &getrow() { return row; }
    const int &getcol() { return col; }
    // TODO
    int *operator[](const int &x);
    const int *operator[](const int &x) const { return mat[x]; }
    // TODO
    Matrix operator+(const Matrix &x) const;
    // TODO: be aware that this function is declared with friend!!!
    friend Matrix operator*(const Matrix &x, const Matrix &y);
    void print()
    {
        for (int i = 0; i < row; i++)
        {
            if (i == 0)
                std::cout << "/";
            else if (i == row - 1)
                std::cout << "\\";
            else
                std::cout << "|";
            for (int j = 0; j < col; j++)
            {
                std::cout << std::right << std::setw(8) << mat[i][j];
            }
            if (i == 0)
                std::cout << " \\\n";
            else if (i == row - 1)
                std::cout << " /\n";
            else
                std::cout << " |\n";
        }
    }

private:
    int mat[MAX_N][MAX_N];
    int row, col;
};

#include "b.hpp"

using namespace std;

int r, c;
long long times;
char op;
Matrix M, ans;

Matrix fast_add(Matrix mat, long long t)
{
    Matrix rtn(mat.getrow(), mat.getcol());
    for (; t; t >>= 1)
    {
        if (t & 1)
            rtn = rtn + mat;
        mat = mat + mat;
    }
    return rtn;
}

Matrix fast_mul(Matrix mat, long long t)
{
    Matrix rtn(mat.getrow(), mat.getcol());
    for (int i = 0; i < mat.getrow(); i++)
        rtn[i][i] = 1;
    for (; t; t >>= 1)
    {
        if (t & 1)
            rtn = rtn * mat;
        mat = mat * mat;
    }
    return rtn;
}

int main()
{
    cin >> r >> c >> times >> op;
    M = Matrix(r, c);
    for (int i = 0, tmp; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> tmp;
            M[i][j] = tmp % MOD;
        }
    switch (op)
    {
    case '+':
        ans = fast_add(M, times);
        break;
    case '*':
        ans = fast_mul(M, times);
        break;
    }
    ans.print();
    return 0;
}
