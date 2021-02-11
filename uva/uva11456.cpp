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
        int n, r = 0;
        cin >> n;
        vector<int> v(n), lis(n, 1), lds(n, 1);
        for (int &i : v)
            cin >> i;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (v[i] > v[j])
                    lis[i] = max(lis[i], lis[j] + 1);
                else if (v[i] < v[j])
                    lds[i] = max(lds[i], lds[j] + 1);
            }
            r = max(r, lis[i] + lds[i] - 1);
        }
        cout << r << '\n';
    }
    return 0;
}