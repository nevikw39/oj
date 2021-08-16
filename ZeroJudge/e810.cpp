#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
struct node
{
    int x, n;
    bool operator<(const node &r) const
    {
        return n < r.n;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (auto &i : v)
        i.resize(n, INT_MAX);
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a][b] = v[b][a] = w;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = min(v[i][j], max(v[i][k], v[k][j]));
    cin >> a >> b;
    cout << (v[a][b] != INT_MAX ? v[a][b] : -1) << '\n';
    return 0;
}
