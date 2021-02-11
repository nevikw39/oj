#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long long;
ul n, a[100001], d[400004];
void build(ul l, ul r, ul p)
{
    if (l == r)
    {
        d[p] = a[l];
        return;
    }
    ul m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, (p << 1) | 1);
    d[p] = min(d[p << 1], d[(p << 1) | 1]);
}
ul query(ul l, ul r, ul s, ul t, ul p)
{
    if (l > t || r < s)
    return LLONG_MAX;
    if (l <= s && t <= r)
        return d[p];
    ul m = (s + t) >> 1;
    return min(query(l, r, s, m, p << 1), query(l, r, m + 1, t, (p << 1) | 1));
}
int main()
{
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    // ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i]++;
    build(1, n, 1);
    for (int _ = 0; _ < n; _++)
    {
        int i, j;
        cin >> i >> j;
        cout << query(i, j, 1, n, 1) << '\n';
    }
    return 0;
}