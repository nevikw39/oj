#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int n;
bitset<17> v;
vector<int> a;
void dfs(int x)
{
    const static set<int> p{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    if (x == n && p.count(a.front() + a.back()))
    {
        cout << '1';
        for (int i = 1; i < n; i++)
            cout << ' ' << a[i];
        cout << '\n';
    }
    else
        for (int i = 2; i <= n; i++)
            if (!v[i] && p.count(i + a[x - 1]))
            {
                a[x] = i;
                v[i] = true;
                dfs(x + 1);
                v[i] = 0;
            }
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 0;
    while (cin >> n)
    {
        if (t)
            cout << '\n';
        cout << "Case " << ++t << ":\n";
        v.reset();
        a.clear();
        a.resize(n);
        a[0] = 1;
        dfs(1);
    }
    return 0;
}