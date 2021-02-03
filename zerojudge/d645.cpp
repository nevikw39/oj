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
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1);
    while (n--)
    {
        int v, w, t;
        cin >> v >> w >> t;
        if (t == -1)
            for (int i = w; i <= m; i++)
                dp[i] = max(dp[i], dp[i - w] + v);
        else
            while (t--)
                for (int i = m - w; i >= 0; i--)
                    dp[i + w] = max(dp[i + w], dp[i] + v);
    }
    cout << dp[m] << '\n';
    return 0;
}