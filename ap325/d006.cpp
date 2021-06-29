#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long f(const int &n, const vector<int> &v, int i = 0, int p = 1)
{
    if (i >= n)
        return p == 1;
    return f(n, v, i + 1, p * v[i] % 10009) + f(n, v, i + 1, p);
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    cout << f(n, v) - 1 << '\n';
    return 0;
}