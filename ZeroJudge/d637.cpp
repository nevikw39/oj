#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
template <typename T>
using heap = __gnu_pbds::priority_queue<T>;
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n), dp(101);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = 100; j >= a[i]; j--)
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
    cout << dp[100] << '\n';
    return 0;
}