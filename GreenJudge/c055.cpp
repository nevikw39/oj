// C
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// C++
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")

using namespace std;

const int INF = 1 << 29;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int g[500][500];
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            g[i][j] = INF;
    int n, m;
    cin >> n;
    vector<int> w(n), d(n, INF), v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    cin >> m;
    while (m--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        a--, b--;
        g[a][b] = min(g[a][b], k);
    }
    d[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int x, mn = INF;
        for (int y = 0; y < n; y++)
            if (!v[y] && d[y] <= mn)
                mn = d[x = y];
        v[x] = 1;
        for (int y = 0; y < n; y++)
            d[y] = min(d[y], d[x] + g[x][y] + w[y]);
    }
    cout << (d[n - 1] != INF ? d[n - 1] : -1) << '\n';
    return 0;
}