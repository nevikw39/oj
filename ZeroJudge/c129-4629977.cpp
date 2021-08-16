#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> v;
short x, y;
void dfs(short i, short j)
{
    v[i][j] = '#';

    for (short a = -1; a < 2; a++)
        for (short b = -1; b < 2; b++)
        {
            short n = i + a, m = j + b;

            if (0 <= n && n < x && 0 <= m && m < y && v[n][m] == '@')
                dfs(n, m);
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> x >> y && x && y)
    {
        short n = 0;
        v = vector<vector<char>>(x, vector<char>(y));

        for (auto & i : v)
            for (char & j : i)
                cin >> j;

        for (short i = 0; i < x; i++)
            for (short j = 0; j < y; j++)
                if (v[i][j] == '@')
                {
                    dfs(i, j);
                    n++;
                }

        cout << n << endl;
    }


    return 0;
}
