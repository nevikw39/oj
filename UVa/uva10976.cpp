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
    int k;
    while (cin >> k)
    {
        vector<pair<int, int>> v;
        for (int y = k + 1; y <= (k << 1); y++)
        {
            int x = y * k / (y - k);
            if (x * y == x * k + y * k)
                v.emplace_back(x, y);
        }
        cout << v.size() << '\n';
        for (const auto &i : v)
            cout << "1/" << k << " = 1/" << i.first << " + 1/" << i.second << '\n';
    }
    return 0;
}