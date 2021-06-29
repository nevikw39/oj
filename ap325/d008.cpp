#include <bits/stdc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#endif
using namespace std;
long long f(const int &n, const vector<vector<int>> &v, vector<int> &p, int i = 0, long long s = 0)
{
    if (i >= n)
        return s;
    vector<bool> valid(n + 1, true);
    for (int j = 0; j < i; j++)
    {
        valid[p[j]] = false;
        int k = i - j + p[j];
        if (k < n)
            valid[k] = false;
        k = j - i + p[j];
        if (k >= 0)
            valid[k] = false;
    }
    auto y = LLONG_MIN;
    for (int j = 0; j <= n; j++)
        if (valid[j])
        {
            p[i] = j;
            y = max(max(y, s + v[i][j]), f(n, v, p, i + 1, s + v[i][j]));
        }
    return y;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    vector<int> p(n + 1);
    cout << f(n, v, p) << '\n';
    return 0;
}