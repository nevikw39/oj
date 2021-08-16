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
    int n, l = 1;
    vector<int> v, a;
    while (cin >> n)
        a.push_back(n);
    n = a.size();
    vector<int> dp(n);
    dp[0] = 0;
    v.push_back(a[0]);
    for (int i = 1; i < n; i++)
        if (a[i] > v.back())
        {
            v.push_back(a[i]);
            dp[i] = l++;
        }
        else
        {
            auto itr = lower_bound(v.begin(), v.end(), a[i]);
            *itr = a[i];
            dp[i] = itr - v.begin();
        }
    cout << l << "\n-\n";
    deque<int> d;
    for (int i = n - 1; i >= 0; i--)
        if (dp[i] == l - 1)
        {
            d.push_front(a[i]);
            --l;
        }
    for (const int &i : d)
        cout << i << '\n';
    return 0;
}