#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> v;
short x, y, a, w, n, e, s;
void dfs(short i, short j)
{
    v[i][j] = '0';
    a++;
    w = j < w ? j : w;
    n = i < n ? i : n;
    e = j > e ? j : e;
    s = i > s ? i : s;

    for (short a = -1; a < 2; a++)
        for (short b = -1; b < 2; b++)
        {
            short n = i + a, m = j + b;

            if (0 <= n && n < x && 0 <= m && m < y && v[n][m] == '1')
                dfs(n, m);
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y;
    v = vector<vector<char>>(x, vector<char>(y, '0'));

    for (auto & i : v)
        for (char & j : i)
            cin >> j;

    for (short i = 0; i < x; i++)
        for (short j = 0; j < y; j++)
            if (v[i][j] == '1')
            {
                a = 0, w = y, n = x, e = 0, s = 0;
                dfs(i, j);
                cout << w << ' ' << n << ' ' << e << ' ' << s << ' ' << a << '\n';
            }

    return 0;
}
