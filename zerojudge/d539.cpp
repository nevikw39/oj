#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long long;
ul n, t[500005], d[1000001];
void build(ul l, ul r, ul p)
{
    if (l == r)
    {
        d[p] = t[l];
        return;
    }
    ul m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, (p << 1) | 1);
    d[p] = max(d[p << 1], d[(p << 1) | 1]);
}
ul query(ul l, ul r, ul s, ul e, ul p)
{
    if (l > e || r < s)
        return 0;
    if (l <= s && e <= r)
        return d[p];
    ul m = (s + e) >> 1;
    return max(query(l, r, s, m, p << 1), query(l, r, m + 1, e, (p << 1) | 1));
}
int main()
{
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    // ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    build(1, n, 1);
    int m;
    cin >> m;
    for (int _ = 0; _ < m; _++)
    {
        int i, j;
        cin >> i >> j;
        cout << query(i < j ? i : j, i > j ? i : j, 1, n, 1) << '\n';
    }
    return 0;
}