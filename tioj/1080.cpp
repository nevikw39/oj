#include <bits/extc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
struct bit
{
    vector<int> v;
    bit(int n)
    {
        v.resize(n + 1);
    }
    int inline lowbit(int x)
    {
        return x & -x;
    }
    void update(int x, int val = 1)
    {
        for (int i = x, n = v.size(); i < n; i += lowbit(i))
            v[i] += val;
    }
    int query(int x)
    {
        int y = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            y += v[i];
        return y;
    }
};
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, t = 0;
    while (cin >> n && n)
    {
        vector<int> v(n), w;
        for (int &i : v)
            cin >> i;
        w = v;
        sort(w.begin(), w.end());
        w.resize(unique(w.begin(), w.end()) - w.begin());
        for (int &i : v)
            i = lower_bound(w.begin(), w.end(), i) - w.begin() + 1;
        long long r = 0;
        bit b(100001);
        for (const int &i : v)
        {
            r += b.query(100001) - b.query(i);
            b.update(i);
        }
        cout << "Case #" << ++t << ": " << r << '\n';
    }
    return 0;
}