#include <bits/extc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#define nevikw39 cin.tie(nullptr); ios::sync_with_stdio(false);
// #else
// #define AC ;
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
struct bit_lis
{
    int n;
    vector<int> v;
    bit_lis(int _n): n(_n)
    {
        v.resize(n + 1);
    }
    int inline lowbit(int x)
    {
        return x & -x;
    }
    int query(int x)
    {
        int y = 0;
        for (; x; x -= lowbit(x))
            y = max(y, v[x]);
        return y;
    }
    void update(int x)
    {
        int val = query(x - 1) + 1;
        for (; x <= n; x += lowbit(x))
            v[x] = max(v[x], val);
    }
};
struct doll
{
    int w, h;
    bool operator<(const doll &x) const
    {
        return w == x.w ? h > x.h : w < x.w;
    }
    bool operator==(const doll &x) const
    {
        return w == x.w && h == x.h;
    }
};
int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<doll> d(m);
        for (doll &i : d)
            cin >> i.w >> i.h;
        sort(d.begin(), d.end());
        vector<int> h, cc;
        for (const doll &i : d)
            h.push_back(i.h);
        cc = h;
        sort(cc.begin(), cc.end());
        cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
        bit_lis bl(m);
        for (const int &i : h)
            bl.update(lower_bound(cc.begin(), cc.end(), i) - cc.begin() + 1);
        cout << bl.query(m) << '\n';
    }
    return 0;
}