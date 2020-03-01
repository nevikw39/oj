#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l = 0, r = 0, a = 0;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        cc_hash_table<int, null_type> s;
        while (r < n)
        {
            while (r < n && s.find(v[r]) == s.end())
                s.insert(v[r++]);
            a = max(a, r - l);
            s.erase(v[l++]);
        }
        cout << a << '\n';
    }
    return 0;
}