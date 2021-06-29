#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
vector<int> v;
long long f(int l, int r)
{
    if (r - l <= 1)
        return 0;
    int m = lower_bound(v.begin() + l, v.begin() + r, (v[l] + v[r]) >> 1) - v.begin();
    if (v[m - 1] - v[l] >= v[r] - v[m])
        --m;
    return v[r] - v[l] + f(l, m) + f(m, r);
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, l;
    cin >> n >> l;
    v.resize(n + 2);
    v[0] = 0, v[n + 1] = l;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    cout << f(0, n + 1) << '\n';
    return 0;
}