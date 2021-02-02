#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int64_t m, n;
    cin >> m >> n;
    vector<int64_t> v(n), w(n);
    while (m--)
    {
        for (auto &i : w)
            cin >> i;
        vector<int64_t> l(n), r(n);
        l[0] = v[0] + w[0];
        for (int64_t i = 1; i < n; i++)
            l[i] = max(l[i - 1] + w[i], v[i] + w[i]);
        r[n - 1] = v[n-1] + w[n - 1];
        for (int64_t i = n - 2; i >= 0; i--)
            r[i] = max(r[i + 1] + w[i], v[i] + w[i]);
        for (int64_t i = 0; i < n; i++)
            w[i] = max(l[i], r[i]);
        v = w;
    }
    cout << *max_element(v.begin(), v.end()) << '\n';
    return 0;
}