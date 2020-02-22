#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n && n)
    {
        unordered_multiset<int> f, t;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            f.insert(a);
            t.insert(b);
        }
        cout << (f == t ? "YES\n" : "NO\n");
    }
    return 0;
}