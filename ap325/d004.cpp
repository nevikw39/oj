#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
vector<int> v;
vector<long long> p, s;
long long f(int l, int r, int d)
{
    if (r - l <= 1 || d < 1)
        return 0;
    long long w = 0, mn = LLONG_MAX, m = 0;
    p[l] = 0;
    for (int i = l + 1; i <= r; i++)
        p[i] = p[i - 1] + (w += v[i - 1]);
    w = 0;
    s[r] = 0;
    for (int i = r - 1; i >= l; i--)
        s[i] = s[i + 1] + (w += v[i + 1]);
    for (int i = l + 1; i < r; i++)
    {
        auto x = abs(p[i] - s[i]);
        if (mn > x)
        {
            mn = x;
            m = i;
        }
    }
    return v[m] + f(l, m - 1, d - 1) + f(m + 1, r, d - 1);
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    v.resize(n + 1);
    p.resize(n + 1);
    s.resize(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    cout << f(1, n, k) << '\n';
    return 0;
}