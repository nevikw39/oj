#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long f(const int &n, const int &p, const vector<int> &v, int i = 0, long long s = 0)
{
    if (s >= p)
        return LLONG_MIN;
    if (i >= n)
        return s;
    return max(f(n, p, v, i + 1, s + v[i]), f(n, p, v, i + 1, s));
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    cout << f(n, p, v) << '\n';
    return 0;
}